#ifndef __USART_H
#define __USART_H
#include "type.h"

#define FOSC 11059200L          //?�̨�3?��?��
#define BAUD 9600             //��??��2����??��

#define NONE_PARITY     0       //?TD��?��
#define ODD_PARITY      1       //??D��?��
#define EVEN_PARITY     2       //??D��?��
#define MARK_PARITY     3       //����??D��?��
#define SPACE_PARITY    4       //??���D��?��

//#define PARITYBIT NONE_PARITY   //?����?D��?��??  
#define PARITYBIT EVEN_PARITY   //?����?D��?��??  

#define TEXT_MODE		0	   	//??��??�꨺?��y?Y
#define HEX_MODE		1		//HEX?�꨺?��y?Y

#define RECEIVE_MODE	TEXT_MODE	//?����?��y?Y?�꨺?

#define S2RI  0x01              //S2CON.0
#define S2TI  0x02              //S2CON.1
#define S2RB8 0x04              //S2CON.2
#define S2TB8 0x08              //S2CON.3

#define S2_S0 0x01              //P_SW2.0

typedef struct
{	
	u8 Uart_RecvData_IsNewFrame;
	u8 Uart_RecvData_Notificatio;
	u8 Uart_RecvData_Pos;
	u8 Local_Uart2Rec_Buf[50];
}Usart2_Runtime_t;

extern Usart2_Runtime_t Usart2_Runtime_Var;

extern void usart2_init(u32 baudrate);
extern void SendData(BYTE dat);
extern void SendString(char *s);
extern void Usart2_Revcive_OneByte(u8 ch);

#endif
