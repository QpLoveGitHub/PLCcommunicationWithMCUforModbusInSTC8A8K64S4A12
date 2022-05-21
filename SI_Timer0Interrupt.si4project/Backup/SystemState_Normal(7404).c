#include "reg51.h"
#include "SystemManageDef.h"
#include "SystemState_Normal.h"
#include "SystemManage.h"
#include "type.h"

#define LD3 P11
#define LD4 P10

sbit P10 = P1^0;
sbit P11 = P1^1;

static u8 g_10ms_cnt = 0;

void System_Normal_Task(void)
{
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

