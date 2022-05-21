#include "softtimer.h"
#include "timer.h"
#include "type.h"


u32	g_timer_ms = 0;

u32	TimerMS_Get(void)
{
	if( 0 == g_timer_ms )
		return	1;
	else
		return	g_timer_ms;
}



u32	TimerMS_Elapse(u32 old_time)
{
	u32 cur_time = g_timer_ms;
	if( cur_time >= old_time)
		return	cur_time - old_time;
	else
		return	0xFFFFFFFF - old_time + cur_time + 1;
}



u32	TimerMS_CheckTimeout(u32 old_time,u32 time_out)
{
	return	(TimerMS_Elapse(old_time) >= time_out);
}

void	TimerMS_Proc(int tick)
{
	g_timer_ms += tick;
	if(0 == g_timer_ms)
		g_timer_ms = 1;
}




void	Timer_Init(StTimer * p,int timer_num)
{
	int iter = 0;
	for(iter=0;iter<timer_num;++iter)
	{
		p[iter].cur_time = 0;
		p[iter].enable = FALSE;
		p[iter].flag = FALSE;
	}
}

void	Timer_Enable(StTimer * p)
{
	if(p)
		p->enable = TRUE;
}

void	Timer_Disable(StTimer * p)
{
	if(p)
		p->enable = FALSE;
}

void	Timer_SetTimeout(StTimer * p,u32 timeout)
{
	if(!p)
		return;
	p->timeout = timeout;
}

bool	Timer_IsEnable(StTimer * p)
{
	if(!p)
		return	FALSE;
	return	p->enable;
}

bool	Timer_IsTimeout(StTimer * p)
{
	if(p && p->enable)
		return	p->flag;
	return	FALSE;
}

void	Timer_Update(StTimer * p)	//?¨¹D?¨°?????¨º¡À?¡Â
{
	if(!p)
		return;
	p->cur_time = TimerMS_Get();
	p->flag = FALSE;
}


void	Timer_SetFlag(StTimer * p)	//????¨°?????¨º¡À?¡Â3?¨º¡À
{
	if(!p)
		return;
	p->flag = TRUE;
	p->cur_time = 0;
}


void	Timer_Start(StTimer * p)
{
	Timer_Enable(p);
	Timer_Update(p);
}

void	Timer_End(StTimer * p)
{
	Timer_Disable(p);
}

//bool	g_timeout_flag = FALSE;
void	Timer_Proc(StTimer * p,int timer_num)
{
	//u32 elapse = 0;
	int iter = 0;
	if(!p)
		return;
	for(iter=0;iter<timer_num;++iter)
	{
		if(p[iter].enable && !p[iter].flag)
		{
#if 1
			if(TimerMS_CheckTimeout(p[iter].cur_time,p[iter].timeout))
			{
				p[iter].flag = TRUE;
				p[iter].cur_time = 0;
			}
#else
			elapse = TimerMS_Elapse(p[iter].cur_time);
			if(elapse >= p[iter].timeout)
			{
				p[iter].flag = TRUE;
				p[iter].cur_time = 0;
				if(elapse >= (p[iter].timeout + (p[iter].timeout/2)))
				{
					g_timeout_flag = TRUE;
				}
			}
#endif
		}
	}
}



