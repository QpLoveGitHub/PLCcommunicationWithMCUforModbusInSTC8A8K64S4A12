#ifndef __LCD12864_H
#define __LCD12864_H
#include "type.h"

extern void lcd12864_module_init(void);
extern void lcd12864_module_Disp(u16 *P_data,u8 len);

#endif
