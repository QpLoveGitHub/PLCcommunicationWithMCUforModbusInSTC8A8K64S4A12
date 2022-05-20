#include "reg51.h"
#include "timer.h"

void system_init(void)
{
	timer0_init();
	timer1_init();
	EA = 1;
}

