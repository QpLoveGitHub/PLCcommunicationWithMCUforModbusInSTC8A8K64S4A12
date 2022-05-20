#include "reg51.h"
#include "intrins.h"
#include "type.h"
#include "systemManage.h"


static u32 g_TM0_Isr_cnt = 0;
static u32 g_TM1_Isr_cnt = 0;


void TM0_Isr() interrupt 1 using 1
{
	TimeSlice_Count();

	if(g_TM0_Isr_cnt++ >= 2000)
	{
		g_TM0_Isr_cnt = 0;
		//P10 = !P10; //测试端口     
	}
	               
}

void TM1_Isr() interrupt 3 using 1
{
	if(g_TM1_Isr_cnt++ >= 100)
	{
		g_TM1_Isr_cnt = 0;
		//P11 = !P11; //测试端口     
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

void timer1_init()
{
	TMOD = 0x00;
	TL1 = 0x66;
	TH1 = 0xfc;
	TR1 = 1;
	ET1 = 1;	
}


