#include "reg51.h"
#include "SystemManageDef.h"
#include "SystemState_Normal.h"
#include "SystemManage.h"
#include "type.h"
#include "usart.h"
#include "string.h"
//#include "modbustimer.h"
#include "timer_UsingTimer0.h"
#include "register.h"
#include "LCD12864.h"
#include "LCD1602.h"
#include "main.h"



#define LD3 P11
#define LD4 P10
#define TEST_PORT_PIN P12

sbit P10 = P1^0;
sbit P11 = P1^1;
sbit P13 = P1^3;
sbit P00 = P0^0;

static u8 g_10ms_cnt = 0;
u32 g_10ms_uart2_recv_timeout = 0;
extern u32 g_current_system_time;
extern u32 g_history_system_time;
extern u16 __reg_data[REGISTER_DATA_LEN];


void System_Normal_Task(void)
{
	//u8 i;
	static u16 __reg_data0_history = 0x0000;

	Notify_ModbusRtu_Register_IsReceived_Message();
	reg_monitor();
	
	if (SystemState_TimeSlice_Obtain(System_TimeSlice_1ms)  == System_TimeSlice_ObtainSuccess)
    {


		if (SystemState_TimeSlice_Obtain(System_TimeSlice_10ms)//10ms
			== System_TimeSlice_ObtainSuccess)
		{
				if(g_10ms_cnt++ >= 20)
				{
					g_10ms_cnt = 0;			
				}
				if(g_10ms_uart2_recv_timeout++ >= 5)
				{
					Usart2_Runtime_Var.Uart_RecvData_IsNewFrame = true;
					g_10ms_uart2_recv_timeout = 0;
				}
			
		}

		 if (SystemState_TimeSlice_Obtain(System_TimeSlice_20ms)//20ms
                == System_TimeSlice_ObtainSuccess)
        {
//        	if(true == timer_usingTimer0_IsTimerout(0,3000))
//        	{
//        		
//				SendString("timer_usingTimer0_IsTimerout(0,3000)\r\n");
//				timer_usingTimer0_StartTimer(0);
//			}
//        
        }

		if (SystemState_TimeSlice_Obtain(System_TimeSlice_50ms)
                == System_TimeSlice_ObtainSuccess)
        {
					//LD4 = !LD4;
			if((false == Usart2_Runtime_Var.Uart_RecvData_IsNewFrame) && (true == Usart2_Runtime_Var.Uart_RecvData_Notificatio))
			{
#if 0
				for(i = 0;i <Usart2_Runtime_Var.Uart_RecvData_Pos;i++)
				{
					SendData(Usart2_Runtime_Var.Local_Uart2Rec_Buf[i]);
				}
				memset(Usart2_Runtime_Var.Local_Uart2Rec_Buf,0x0,50);
				Usart2_Runtime_Var.Uart_RecvData_Notificatio = false;
				Usart2_Runtime_Var.Uart_RecvData_Pos = 0;
#endif			
			}
					
        }		

		 if (SystemState_TimeSlice_Obtain(System_TimeSlice_100ms)
                == System_TimeSlice_ObtainSuccess)
        {
					
        }

		 if (SystemState_TimeSlice_Obtain(System_TimeSlice_200ms)
                == System_TimeSlice_ObtainSuccess)
        {
        }

		if (SystemState_TimeSlice_Obtain(System_TimeSlice_500ms)
                == System_TimeSlice_ObtainSuccess)
        {
		}

		if (SystemState_TimeSlice_Obtain(System_TimeSlice_1s)
                == System_TimeSlice_ObtainSuccess)
		{
			//LD4 = !LD4;
#ifdef USE_LCD12864
				if(__reg_data0_history != __reg_data[0])
				{
					__reg_data0_history = __reg_data[0];
					lcd12864_module_Disp(&__reg_data[0]);
				}
#endif
#ifdef USE_LCD1602
				if(__reg_data0_history != __reg_data[0])
				{
					__reg_data0_history = __reg_data[0];
					lcd1602_module_Disp(&__reg_data[0]);
				}
#endif
		}

		if (SystemState_TimeSlice_Obtain(System_TimeSlice_2s)
						== System_TimeSlice_ObtainSuccess)
		{

			
		}

		if (SystemState_TimeSlice_Obtain(System_TimeSlice_5s)
						== System_TimeSlice_ObtainSuccess)
		{
				//LD3 = !LD3;
		}
	}
}

