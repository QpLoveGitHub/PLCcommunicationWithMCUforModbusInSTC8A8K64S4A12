#include "reg51.h"
#include "timer.h"
#include "usart.h"
//#include "modbustimer.h"
#include "timer_UsingTimer0.h"
#include "register.h"
#include "LCD1602.h"
#include "main.h"


#define VERSION_INFO "ZZCL MODBUS & DAC Display Verison 2022.5.21\r\n"

void system_init(void)
{
	timer0_init();
	timer1_init();
	usart2_init(9600);
	EA = 1;
	
#ifdef USE_LCD1602
	lcd1602_module_init();
#endif
	
#ifdef USE_LCD12864
	lcd12864_module_init();
#endif

	timer_usingTimer0_StartTimer(0);
	reg_init();
	SendString(VERSION_INFO);
}

