#include "STC15F2K60S2.H" 
#include "intrins.h"	
#include "usart.h"

bit busy;
bit flag;

void SendData(BYTE dat)
{
    while (busy);              
    ACC = dat;                 
    if (P)                      
    {
#if (PARITYBIT == ODD_PARITY)
        S2CON &= ~S2TB8;        
#elif (PARITYBIT == EVEN_PARITY)
        S2CON |= S2TB8;        
#endif
    }
    else
    {
#if (PARITYBIT == ODD_PARITY)
        S2CON |= S2TB8;         
#elif (PARITYBIT == EVEN_PARITY)
        S2CON &= ~S2TB8;        
#endif
    }
    busy = 1;
    S2BUF = ACC;                
}







