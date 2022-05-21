#ifndef __TIMER_USING_TIMER0_H
#define __TIMER_USING_TIMER0_H
#include "type.h"
typedef u8 Timer_UsingTimer0_TimerID ;

extern void timer_usingTimer0_StartTimer(Timer_UsingTimer0_TimerID timerID);
extern void timer_usingTimer0_StopTimer(Timer_UsingTimer0_TimerID timerID);
bool timer_usingTimer0_IsTimerout(Timer_UsingTimer0_TimerID timerID,u32 timeout);

#endif
