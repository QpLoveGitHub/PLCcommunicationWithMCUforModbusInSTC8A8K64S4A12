#include "reg51.h"
#include "timer.h"
#include "usart.h"

#define VERSION_INFO "ZZCL MODBUS & DAC Display Verison 2022.5.21\r\n"

void system_init(void)
{
	timer0_init();
	timer1_init();
	usart2_init(9600);
	EA = 1;
	
	SendString(VERSION_INFO);
}

