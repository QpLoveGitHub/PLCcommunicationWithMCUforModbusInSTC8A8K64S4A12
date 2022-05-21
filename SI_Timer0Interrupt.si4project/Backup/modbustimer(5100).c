#include "modbustimer.h"
#include "softtimer.h"
#include "type.h"


StTimer	g_Modbus_Timer[ModbusTimer_MAX] =
{
	{500},
};

void  ModbusTimer_Init(void)
{
	Timer_Init(g_Modbus_Timer,ModbusTimer_MAX);	
}


bool	ModbusTimer_IsEnable(EnModbusTimer ti)
{
	if(ti >= ModbusTimer_MAX)
		return	FALSE;
	return	Timer_IsEnable(&g_Modbus_Timer[(int)ti]);
}

void	ModbusTimer_Enable(EnModbusTimer ti)
{
	if(ti >= ModbusTimer_MAX)
		return;
	Timer_Enable(&g_Modbus_Timer[(int)ti]);
}

void	ModbusTimer_Disable(EnModbusTimer ti)
{
	if(ti >= ModbusTimer_MAX)
		return;
	Timer_Disable(&g_Modbus_Timer[(int)ti]);
}

void	ModbusTimer_SetTimeout(EnModbusTimer ti,u32 timeout)
{
	if(ti >= ModbusTimer_MAX)
		return;
	Timer_SetTimeout(&g_Modbus_Timer[(int)ti],timeout);
}

void	ModbusTimer_Update(EnModbusTimer ti)
{
	if(ti >= ModbusTimer_MAX)
		return;
	Timer_Update(&g_Modbus_Timer[(int)ti]);
}

bool	ModbusTimer_IsTimeout(EnModbusTimer ti)
{
	if(ti >= ModbusTimer_MAX)
		return	FALSE;
	return	Timer_IsTimeout(&g_Modbus_Timer[(int)ti]);
}

void	ModbusTimer_SetFlag(EnModbusTimer ti)
{
	if(ti >= ModbusTimer_MAX)
		return;
	Timer_SetFlag(&g_Modbus_Timer[(int)ti]);
}


void	ModbusTimer_Start(EnModbusTimer ti)
{
	if(ti >= ModbusTimer_MAX)
		return;
	Timer_Start(&g_Modbus_Timer[(int)ti]);
}

void	ModbusTimer_End(EnModbusTimer ti)
{
	if(ti >= ModbusTimer_MAX)
		return;
	Timer_End(&g_Modbus_Timer[(int)ti]);
}


void	ModbusTimer_Proc(void)
{
	Timer_Proc(g_Modbus_Timer,ModbusTimer_MAX);
}



