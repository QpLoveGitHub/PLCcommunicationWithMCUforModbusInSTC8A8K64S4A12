#include "STC15F2K60S2.h"
#include "LCD12864.h"
//#include "type.h"
#define uchar unsigned char 
#define uint  unsigned int  
sbit RS=P4^0; 
sbit RW=P4^1; 
sbit E =P4^2; 
sbit PSB =P4^3;  
/*********************************************     *********************************************/ 
void Delay_1ms(uint x) 
{  
	uint j,i;   
	for(j=0;j<x;j++)   
	{    
		for(i=0;i<120;i++);  
	}  
}

/*********************************************   LCD12864*********************************************/ 
void Busy_LCD12864()   
{   
	uchar busy;
	do  
	{      
		E = 0;         
		RS = 0;      
		RW = 1;      
		Delay_1ms(20);    
		E = 1;     
		P2M0=0x00;
		P2M1=0x00;	 
		busy=P2;    
		Delay_1ms(20);  
		E = 0;    
	}while(busy&0x80);  
}  
/*********************************************   LCD12864*********************************************/ 
void Write_Data(uchar k) 
{   
	Busy_LCD12864();   
	E =1;    
	RS=1;    
	RW=0;   
	P2M0=0xFF;
	P2M1=0x00;	
	P2=k;   
	Delay_1ms(20);  
	E =0;    
	Delay_1ms(20);   
}  

/*********************************************   LCD12864  *********************************************/ 
void Write_Cmd(uchar cmd) 
{      
	Busy_LCD12864();    
	E=1;   
	RS=0;    
	RW=0;   
	P2M0=0xFF;
	P2M1=0x00;	
	P2=cmd;    
	Delay_1ms(20); 
	E=0;   
	Delay_1ms(20); 
}  

/*********************************************   LCD12864¨°o?¡ì¨ºy?Y??¨º?¡Á¨®3¨¬D¨°  *********************************************/ 
void Disp(uchar y,uchar x,uchar i,uchar *z)   
{     
	uchar Address;    
	if(y==1)
	{
		Address=0x80+x;
	}     
	if(y==2){Address=0x90+x;}        
	if(y==3){Address=0x88+x;}    
	if(y==4){Address=0x98+x;}  
	Write_Cmd(Address);
	while(i)       
	{    
		Write_Data(*(z++));      
		i--;         
	}   
} 

 /*********************************************   LCD12864¨°  *********************************************/ 
 void Ini_Lcd(void)     
 {     

	 PSB=1;      

	 Delay_1ms(20);                  
	 Write_Cmd(0x30);   
	 Delay_1ms(20);      
	 Write_Cmd(0x02);   
	 Delay_1ms(20);      
	 Write_Cmd(0x0c);    
	 Delay_1ms(20);      
	 Write_Cmd(0x06);   
	 Delay_1ms(20);      
	 Write_Cmd(0x80);     
	 Delay_1ms(20);      
	 Write_Cmd(0x01);   
 }

#if 0
 void main()
{
	P4M1=0x00;
	P4M0=0x00;
	Ini_Lcd();
	Disp(1,0,16,"LCD12864?¨¬2a3¨¦1|");
	Disp(2,1,12,"STC15W4K56S4");
	Disp(3,1,12,"¦Ì£¤???¨²?a¡¤¡é¡ã?");
	Disp(4,2,16,"--?Y¨¢¡é?¨¦¦Ì?¡Á¨®");
	while(1);
}
#endif

void lcd12864_module_init(void)
{
	P4M1=0x00;
	P4M0=0x00;
	Ini_Lcd();
	//Disp(1,0,16,"LCD12864?¨¬2a3¨¦1|");
	Disp(2,1,12,"STC15W4K56S4");
	//Disp(3,1,12,"¦Ì£¤???¨²?a¡¤¡é¡ã?");
	Disp(4,0,16,"MODBUSRTU--ZZCL");
	//while(1);
}

void lcd12864_module_Disp(u16 *P_data,u8 len)
{
	unsigned char lcd12864_module_Disp_String[] = {"MODBUSRTU--ZZCL"};
	unsigned char tmBuf[4];
	int i;
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
	
	lcd12864_module_Disp_String[14] = tmBuf[0];
	lcd12864_module_Disp_String[13] = tmBuf[1];
	lcd12864_module_Disp_String[12] = tmBuf[2];
	lcd12864_module_Disp_String[11] = tmBuf[3];
	Disp(4,0,16,lcd12864_module_Disp_String);	
}


