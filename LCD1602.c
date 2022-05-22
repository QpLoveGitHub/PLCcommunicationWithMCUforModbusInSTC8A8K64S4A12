#include "STC15F2K60S2.h"
#include "LCD1602.h"

#define  uint unsigned int  
#define  uchar unsigned char 
#define CLOUNM2_OFFSET (0x40+0)
sbit rs=P4^0;    
sbit rw=P4^1;        
sbit en=P4^2;        

sbit lcdsel=P4^3;	
//uchar code table[]=" lCD1602 check ok"; 
uchar code table[]=" MODBUS  check ok"; 

//uchar code table1[]="  --Jellina";             
//uchar  table1[]="  --Jellina";  
uchar  table1[]="  --ZZCL   ";  



void delay(uint n)                 
{ 
    uint x,y;  
    for(x=n;x>0;x--) 
        for(y=110;y>0;y--); 
} 

void delay_1s()
{
	delay(100000);
}

void lcd_wcom(uchar com)              
{ 
    rs=0;            
    rw=0;             
    P2=com;           
    delay(5);            
    en=1;           
    en=0; 
} 
void lcd_wdat(uchar dat)    
{ 
    rs=1;        
    rw=0;        
    P2=dat;        
    delay(5);        
    en=1;        
    en=0; 
} 
void lcd_init()              
{ 
    lcd_wcom(0x38);       
    lcd_wcom(0x0c);     
    lcd_wcom(0x06);   
    lcd_wcom(0x01);   
} 

#if 0
void main()          
{     
 uchar n,m=0; 

	P4M1=0x00;
	P4M0=0x00;
	P2M0=0xff;
	P2M1=0x00;	
	
	lcdsel = 1;
    lcd_init();                 
    lcd_wcom(0x80);   
    for(m=0;m<17;m++)     
    { 
            lcd_wdat(table[m]);           
            delay(200); 
    } 
    
    lcd_wcom(0x80+CLOUNM2_OFFSET);
		for(n=0;n<11;n++)   
    {     
            lcd_wdat(table1[n]); 
           delay(200); 
    } 
    //while(1);       
		while(1)
		{
			if(table1[5] < 'z')
			{
				table1[5]++;
				delay_1s();
				lcd_wcom(0x80+CLOUNM2_OFFSET);
				lcd_wdat(table1[5]); 
			  delay(200);
			}
			else
			{
				table1[5] = 'a' -1;
			}
		}
} 
#endif

void lcd1602_module_init(void)
{
	uchar n,m=0; 

	P4M1=0x00;
	P4M0=0x00;
	P2M0=0xff;
	P2M1=0x00;	
	
	lcdsel = 1;
    lcd_init();                 
    lcd_wcom(0x80);   
    for(m=0;m<17;m++)     
    { 
       lcd_wdat(table[m]);           
       delay(200); 
    } 
    
    lcd_wcom(0x80+CLOUNM2_OFFSET);
		for(n=0;n<11;n++)   
    {     
       lcd_wdat(table1[n]); 
		delay(200); 
    } 
}

void lcd1602_module_Disp(u16 *P_data,u8 len)
{
	unsigned char lcd1602_module_Disp_String[] = {"  0x1ZCL   "};
	unsigned char tmBuf[4];
	int i;
	uchar n,m=0;
	tmBuf[0] = (u8)((*P_data) & 0x000F);
	tmBuf[1] = (u8)(((*P_data) >> 4) & 0x000F);
	tmBuf[2] = (u8)(((*P_data) >> 8) & 0x000F);
	tmBuf[3] = (u8)(((*P_data) >> 12) & 0x000F);

	for(i = 0;i < 4;i++)
	{
		if(tmBuf[i] < 0xA)
		{
			tmBuf[i] += 48;
		}
		else
		{
			tmBuf[i] += 55;
		}
	}

	lcd1602_module_Disp_String[7] = tmBuf[0];
	lcd1602_module_Disp_String[6] = tmBuf[1];
	lcd1602_module_Disp_String[5] = tmBuf[2];
	lcd1602_module_Disp_String[4] = tmBuf[3];
 
#if 0
	P4M1=0x00;
	P4M0=0x00;
	P2M0=0xff;
	P2M1=0x00;	
	
		lcdsel = 1;
    lcd_init();                 
    lcd_wcom(0x80);   
    for(m=0;m<17;m++)     
    { 
       lcd_wdat(table[m]);           
       delay(200); 
    } 
#endif
    
    lcd_wcom(0x80+CLOUNM2_OFFSET);
		for(n=0;n<11;n++)   
    {     
       lcd_wdat(lcd1602_module_Disp_String[n]); 
		delay(200); 
    } 
}




