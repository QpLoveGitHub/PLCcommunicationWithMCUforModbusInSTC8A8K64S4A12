#ifndef __SOFTTIMER_H
#define __SOFTTIMER_H
#include "type.h"

u32	TimerMS_Get(void);
u32	TimerMS_Elapse(u32 old_time);
u32	TimerMS_CheckTimeout(u32 old_time,u32 time_out);

void	TimerMS_Proc(int tick);

typedef	struct	_StTimer
{
	u32	timeout;
	u32	cur_time;
	bool enable;
	bool flag;
}StTimer;

void	Timer_Init(StTimer * p,int timer_num);
void	Timer_Enable(StTimer * p);
void	Timer_Disable(StTimer * p);
bool	Timer_IsEnable(StTimer * p);
void	Timer_SetTimeout(StTimer * p,u32 timeout);
bool	Timer_IsTimeout(StTimer * p);
void	Timer_Update(StTimer * p);
void	Timer_SetFlag(StTimer * p);
void	Timer_Start(StTimer * p);
void	Timer_End(StTimer * p);
void	Timer_Proc(StTimer * p,int timer_num);

#endif
