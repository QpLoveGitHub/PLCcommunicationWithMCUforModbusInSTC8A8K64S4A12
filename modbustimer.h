#ifndef __MODBUSTIMER_H
#define __MODBUSTIMER_H
#include "softtimer.h"

typedef	enum	_EnModbusTimer
{
	ModbusTimer_ToogleLed,
	ModbusTimer_MAX,
}EnModbusTimer;

extern StTimer	g_Modbus_Timer[ModbusTimer_MAX];


extern void	ModbusTimer_Init(void);
extern bool	ModbusTimer_IsEnable(EnModbusTimer ti);
extern void	ModbusTimer_Enable(EnModbusTimer ti);
extern void	ModbusTimer_Disable(EnModbusTimer ti);
extern void	ModbusTimer_SetTimeout(EnModbusTimer ti,u32 timeout);
extern void	ModbusTimer_Update(EnModbusTimer ti);
extern bool	ModbusTimer_IsTimeout(EnModbusTimer ti);
extern void	ModbusTimer_SetFlag(EnModbusTimer ti);

extern void	ModbusTimer_Start(EnModbusTimer ti);
extern void	ModbusTimer_End(EnModbusTimer ti);

extern void	ModbusTimer_Proc(void);

u32	TimerMS_Get(void);


#endif
