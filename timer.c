#include "reg51.h"
#include "intrins.h"
#include "type.h"
#include "systemManage.h"
#include "modbustimer.h"
#include "SystemState_Normal.h"
#include "softtimer.h"


static u32 g_TM0_Isr_cnt = 0;
static u32 g_TM1_Isr_cnt = 0;
sbit P10_T = P1^0;
sbit P11_T = P1^1;

u32 g_current_system_time = 0;
u32 g_history_system_time = 0;
extern bool timer_usingTimer0_Enable;



void TM0_Isr() interrupt 1 using 1
{	
	TimeSlice_Count();               
}

void TM1_Isr() interrupt 3 using 1
{
	if(true == timer_usingTimer0_Enable)
	{
		g_current_system_time++;
	}
}


//500us per intterrupt
void timer0_init()
{
	TMOD = 0x00;
	TL0 = 0x33; //65536-11.0592M/12/1000
	TH0 = 0xFE;
	TR0 = 1; //启动定时器
	ET0 = 1; //使能定时器中断
}

//1ms per interrupt
void timer1_init()
{
	TMOD = 0x00;
	TL1 = 0x66;
	TH1 = 0xfc;
	TR1 = 1;
	ET1 = 1;	
}


