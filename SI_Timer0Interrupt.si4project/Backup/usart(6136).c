#include "STC15F2K60S2.H" 
#include "intrins.h"	
#include "usart.h"
#include "type.h"

bit busy;
bit flag;
static u8 sendByte;
Usart2_Runtime_t Usart2_Runtime_Var = {true,false,0,{0}};
extern u32 g_10ms_uart2_recv_timeout;

void usart2_init(u32 baudrate)
{
	P_SW2 &= ~S2_S0;           
//  P_SW2 |= S2_S0;             

#if (PARITYBIT == NONE_PARITY)
    S2CON = 0x50;               
#elif (PARITYBIT == ODD_PARITY) || (PARITYBIT == EVEN_PARITY) || (PARITYBIT == MARK_PARITY)
    S2CON = 0xda;               
#elif (PARITYBIT == SPACE_PARITY)
    S2CON = 0xd2;               
#endif

    //T2L = (65536 - (FOSC/4/BAUD));   //谷豕??2“足??那??℅～?米
    //T2H = (65536 - (FOSC/4/BAUD))>>8;
	T2L = (65536 - (FOSC/4/baudrate));   
    T2H = (65536 - (FOSC/4/baudrate))>>8;
    AUXR = 0x14;               
    IE2 = 0x01;                 
}


void SendData(BYTE dat)
{
    while (busy);              
    ACC = dat;                 
    if (P)                      
    {
#if (PARITYBIT == ODD_PARITY)
        S2CON &= ~S2TB8;        
#elif (PARITYBIT == EVEN_PARITY)
        S2CON |= S2TB8;        
#endif
    }
    else
    {
#if (PARITYBIT == ODD_PARITY)
        S2CON |= S2TB8;         
#elif (PARITYBIT == EVEN_PARITY)
        S2CON &= ~S2TB8;        
#endif
    }
    busy = 1;
    S2BUF = ACC;                
}

void SendString(char *s)
{
    while (*s)                 
    {
        SendData(*s++);      
		}
}

void Uart2() interrupt 8 using 1
{
	u8  tmp;
    if (S2CON & S2RI)
    {
        S2CON &= ~S2RI;         //??3yS2RI??
        //sendByte = S2BUF;              //??豕?∩??迆?車那?那y?Y
        tmp = S2BUF;
        Usart2_Revcive_OneByte(tmp);
		flag = 1;	
    }
    if (S2CON & S2TI)
    {
        S2CON &= ~S2TI;         //??3yS2TI??
        busy = 0;               //???|㊣那??
    }
}

void Usart2_Revcive_OneByte(u8 ch)
{
	if((true == Usart2_Runtime_Var.Uart_RecvData_IsNewFrame) && (0x1 == ch))
	{
		Usart2_Runtime_Var.Local_Uart2Rec_Buf[0] = ch;
		Usart2_Runtime_Var.Uart_RecvData_Pos++;
		Usart2_Runtime_Var.Uart_RecvData_Notificatio = true;
		Usart2_Runtime_Var.Uart_RecvData_IsNewFrame = false;
		g_10ms_uart2_recv_timeout = 0;
	}
	else if(true == Usart2_Runtime_Var.Uart_RecvData_Notificatio)
	{
		Usart2_Runtime_Var.Local_Uart2Rec_Buf[Usart2_Runtime_Var.Uart_RecvData_Pos++] = ch;		
		g_10ms_uart2_recv_timeout = 0;
	}
}








