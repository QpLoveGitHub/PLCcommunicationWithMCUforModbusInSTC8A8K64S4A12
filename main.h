#ifndef __MAIN_H
#define __MAIN_H
#define ccts(c1, c2)    ((((c1) << 8) & 0xFF00) + ((c2) & 0x00FF))
//#define USE_LCD12864

#ifndef USE_LCD12864
#define USE_LCD1602
#endif

#endif
