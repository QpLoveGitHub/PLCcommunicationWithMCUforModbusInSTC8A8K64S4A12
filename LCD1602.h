#ifndef __LCD1602_H
#define __LCD1602_H
#include "type.h"

extern void lcd1602_module_init(void);
extern void lcd1602_module_Disp(u16 *P_data,u8 len);

#endif

