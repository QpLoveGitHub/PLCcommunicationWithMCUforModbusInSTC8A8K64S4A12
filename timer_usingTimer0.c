#include "timer_usingTimer0.h"
#include "reg51.h"

bool timer_usingTimer0_Enable = false;
extern u32 g_current_system_time;

void timer_usingTimer0_StartTimer(Timer_UsingTimer0_TimerID timerID)
{
	(void)timerID;
	timer_usingTimer0_Enable = true;
	ET0 = 0;
	g_current_system_time = 0;
	ET0 = 1;
}

void timer_usingTimer0_StopTimer(Timer_UsingTimer0_TimerID timerID)
{
	(void)timerID;
	timer_usingTimer0_Enable = false;
	g_current_system_time = 0;
}

bool timer_usingTimer0_IsTimerout(Timer_UsingTimer0_TimerID timerID,u32 timeout)
{
	(void)timerID;
	if(g_current_system_time >= timeout)
	{
		return true;
	}
	return false;
}




