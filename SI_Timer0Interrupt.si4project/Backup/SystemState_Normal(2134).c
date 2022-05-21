#include "reg51.h"
#include "SystemManageDef.h"
#include "SystemState_Normal.h"
#include "SystemManage.h"
#include "type.h"
#include "usart.h"
#include "string.h"

#define LD3 P11
#define LD4 P10

sbit P10 = P1^0;
sbit P11 = P1^1;

static u8 g_10ms_cnt = 0;
u32 g_10ms_uart2_recv_timeout = 0;

void System_Normal_Task(void)
{
	u8 i;
	
	if (SystemState_TimeSlice_Obtain(System_TimeSlice_1ms)  == System_TimeSlice_ObtainSuccess)
    {

		if (SystemState_TimeSlice_Obtain(System_TimeSlice_10ms)//10ms
			== System_TimeSlice_ObtainSuccess)
		{
				if(g_10ms_cnt++ >= 20)
				{
					g_10ms_cnt = 0;
					//LD3 = !LD3;
				}
				if(g_10ms_uart2_recv_timeout++ >= 20)
				{
					//Usart2_Runtime_Var.Uart_RecvData_IsNewFrame = true;
					g_10ms_uart2_recv_timeout = 0;
				}
			
		}

		 if (SystemState_TimeSlice_Obtain(System_TimeSlice_20ms)//20ms
                == System_TimeSlice_ObtainSuccess)
        {
        	
        }

		if (SystemState_TimeSlice_Obtain(System_TimeSlice_50ms)
                == System_TimeSlice_ObtainSuccess)
        {
			//LEDred_TOOGLE;
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
