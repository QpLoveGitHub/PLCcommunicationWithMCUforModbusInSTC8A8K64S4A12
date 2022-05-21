#include "type.h"
#include "register.h"
#include "timer.h"
#include "usart.h"
#include "softtimer.h"
#include "string.h"
#include "crc.h"
#include "main.h"
#include "timer_usingTimer0.h"

typedef struct {
    u8          received;
    u8          waiting_head_byte;
    u8          pos;
    u8          packet_data[256];
    TIMER_ID    terminal_timerid;
} reg_context_t;


reg_context_t reg_context;

u16 __reg_data[REGISTER_DATA_LEN] = 
{
	TEST_ADDRESS0_DATA,
	TEST_ADDRESS1_DATA,
};
u16 __local_reg_data[120] = {0};

void Notify_ModbusRtu_Register_IsReceived_Message(void)
{
	if(true == timer_usingTimer0_IsTimerout(0,5))
	{
		
		//SendString("timer version 2022-5-21 v00000000000000000000\r\n");
		//P10 = !P10;
		reg_context.received = true;
		timer_usingTimer0_StopTimer(0);
	}
}


u8 reg_write(u16 reg_address, void *reg_value, u16 reg_num)
{    
    memcpy((void *)&__reg_data[reg_address], reg_value, 2*reg_num);
    
    return 0;
}

u8 reg_read(u16 reg_address, void *reg_value, u16 reg_num)
{
    memcpy(reg_value, (void *)&__reg_data[reg_address], 2*reg_num);
    
    return 0;
}

u8 reg_command_receive(u8 rdata)
{
    if (reg_context.waiting_head_byte == TRUE)
    {
        // 如果是接收到的第一个字节 则判断下是否是EDA的数据包头 不是则直接返回
        if (rdata != rtu_address)
        //if (rdata != 0x01)
        {
            // 所有的EDA应答数据包都是由EDA_PACKET_HEAD开始 这样可以有效过滤到非法字符
            return -1;
        }

        reg_context.waiting_head_byte = FALSE;        
        reg_context.received = FALSE;

        reg_context.pos = 0;
        reg_context.packet_data[reg_context.pos++] = rdata;

        //timerStart(g_hTimer, reg_context.terminal_timerid, FALSE);
        timer_usingTimer0_StartTimer(0);
    }
    else
    {
        // 如果连续收到的数据超过了规定的最大长度 则忽略后续接收到的数据
        if (reg_context.pos >= MODBUS_MAX_PACKET_LEN)
        {
           // timerStart(g_hTimer, reg_context.terminal_timerid, FALSE);
            return 0;
        }

        reg_context.packet_data[reg_context.pos++] = rdata;
        //timerStart(g_hTimer, reg_context.terminal_timerid, FALSE);
        timer_usingTimer0_StartTimer(0);
    }

    return 0;
}

void reg_modbus_send_response_packet(u8 *buf, u16 len)
{
    u16 i;

    //REG_485_OUTPUT_ENABLE;

    for (i=0; i<len; i++)
    {
        REG_PUTCHAR(buf[i]);
    }

    //REG_485_OUTPUT_DISABLE;
}

u8 reg_modbus_crc_check(u8 *buf, u16 len)
{
    u8  crch;
    u8  crcl;
    u16 crc;

    if (len < 8)
    {
        //DEBUG_ERROR("crc len invalid %d\r\n", len);
        return -1;
    }

    crc = modbus_crc16(buf, len - 2);
    crch = (U8)(crc >> 8);
    crcl = (U8)(crc);

    if ((crcl != buf[len - 2]) || (crch != buf[len - 1]))
    {
        //DEBUG_ERROR("crc[%x] is invalid crc1[%x] crc2[%x]\r\n", crc, buf[len-2], buf[len-1]);
        return -2;
    }

    return 0;
}

u8 reg_modbus_exception_response(u8 command, u8 errcode)
{
    u16 crc = 0;
    
    reg_context.packet_data[0] = rtu_address;	//0x01;
    reg_context.packet_data[1] = 0x80 | command;
    reg_context.packet_data[2] = errcode;
    crc = modbus_crc16(reg_context.packet_data, 3);
    reg_context.packet_data[3] = (u8)(crc);
    reg_context.packet_data[4] = (u8)(crc >> 8);

    reg_modbus_send_response_packet(reg_context.packet_data, 5);
        
    return 0;
}

u8 reg_modbus_multi_read_command_response(u16 *reg_data, u16 reg_num)
{
    u8  i = 0;
    u16 crc = 0;
    
    reg_context.packet_data[0] = rtu_address;	//0x01;
    reg_context.packet_data[1] = 0x03;
    reg_context.packet_data[2] = 2*reg_num;
    for (i=0; i<reg_num; i++)
    {
        reg_context.packet_data[3+2*i]   = (u8)(reg_data[i] >> 8);
        reg_context.packet_data[3+2*i+1] = (u8)(reg_data[i]);
    }

    crc = modbus_crc16(reg_context.packet_data, 3+2*reg_num);
    reg_context.packet_data[3+2*reg_num]   = (u8)(crc);
    reg_context.packet_data[3+2*reg_num+1] = (u8)(crc >> 8);

    reg_modbus_send_response_packet(reg_context.packet_data, 5+2*reg_num);
        
    return 0;
}

u8 reg_multi_read_process(u8 *buf, u16 len)
{
    u16 reg_addr;
    u16 reg_num;   

    reg_addr = ccts(buf[2], buf[3]);
    reg_num  = ccts(buf[4], buf[5]);
    
    if (reg_num > 120)
    {
//        DEBUG_ERROR("REG: reg num %d is out of scope\r\n", reg_num);
        return -1;
    }
    
//    DEBUG_TRACE("REG: modbus read command\r\n");
//    DEBUG_TRACE("REG: modbus reg begin addr %d\r\n", reg_addr);
//    DEBUG_TRACE("REG: modbus reg addr num %d\r\n", reg_num);
    
    memset(__local_reg_data, 0, sizeof(__local_reg_data));
    reg_read(reg_addr, __local_reg_data, reg_num);
    reg_modbus_multi_read_command_response(__local_reg_data, reg_num);
    
    return 0;
}

u8 reg_request_dispatch(u8 *buf, u16 len)
{
    u8   rtv = 0;    

    rtv = reg_modbus_crc_check(buf, len);
    if (0 != rtv)
    {
//        DEBUG_ERROR("REG: modbus crc check failed with errcode %d\r\n", rtv);
        return -1;
    }

    if (buf[0] != rtu_address)
    //if (buf[0] != REG_MODBUS_MASTER_ADDR)
    {
//        DEBUG_ERROR("REG: invalid dev address %d\r\n", buf[0]);
        return -1;
    }

    if ((buf[1] != REG_MODBUS_OPR_MULTI_READ)
     && (buf[1] != REG_MODBUS_OPR_MULTI_WRITE)
     && (buf[1] != REG_MODBUS_OPR_SINGLE_WRITE)
    )
    {
//        DEBUG_ERROR("REG: invalid modbus opr command %d\r\n", buf[1]);
        return -1;
    }

    switch (buf[1])
    {
        case REG_MODBUS_OPR_MULTI_READ:			// 读
//            DEBUG_ERROR("1111111111111\r\n");
            reg_multi_read_process(buf, len);
            break;
        case REG_MODBUS_OPR_MULTI_WRITE:		// 写多地址
//            DEBUG_ERROR("1111111111112\r\n");
//            reg_multi_write_process(buf, len);
            break;
        case REG_MODBUS_OPR_SINGLE_WRITE:		
//            DEBUG_ERROR("1111111111113\r\n");	// 写单地址
//            reg_single_write_process(buf, len);
            break;
        case BIT_MODBUS_OPR_READ:
			break;
		
		case BIT_MODBUS_OPR_WRITE:
			break;

		case REG_MODBUS_READ_INPUT_REGISTER:
			break;
			
		default:
            break;
    }

    return 0;
}

void reg_modbus_timer_out(void *p)
{
    reg_context.received  = TRUE;
}

void reg_init()
{
    memset(&reg_context, 0, sizeof(reg_context));
    reg_context.waiting_head_byte = TRUE;
    
    //reg_context.terminal_timerid = timerRegister(g_hTimer, 2, reg_modbus_timer_out, NULL);	//2
	
} 

void reg_monitor()
{
    if (reg_context.received)
    {   
		
//		if (test_tt2==0)
//		{
//			test_tt2 = 1;
//			GPIO_SetBits(PORT_PIN_LED1, PIN_LED2);
//		}
//		else
//		{
//			test_tt2 = 0;
//			GPIO_ResetBits(PORT_PIN_LED1, PIN_LED2);
//			
//		}

        reg_context.waiting_head_byte = TRUE;
    
//        DEBUG_ERROR("reg_test =%d\r\n", reg_test++);
        reg_request_dispatch(reg_context.packet_data, reg_context.pos);

        reg_context.pos = 0;
        reg_context.received = FALSE;        
    }
}



