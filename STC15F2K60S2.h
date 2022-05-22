#ifndef __STC15F2K60S2_H_
#define __STC15F2K60S2_H_

/////////////////////////////////////////////////
//¡Á¡é¨°a: STC15W4K32S4?¦Ì¨¢D¦Ì?D???,¨¦?¦Ì?o¨®?¨´¨®D¨®?PWM?¨¤1?¦Ì?IO?¨²?¨´?a
//      ??¡Á¨¨¨¬?,D¨¨???aD??¨²¨¦¨¨???a¡Á????¨°?¨²?¨°??¨ª?¨ª¨¬?¡ê¨º?¡¤??¨¦?y3¡ê¨º1¨®?
//?¨¤1?IO: P0.6/P0.7/P1.6/P1.7/P2.1/P2.2
//        P2.3/P2.7/P3.7/P4.2/P4.4/P4.5
/////////////////////////////////////////////////

/////////////////////////////////////////////////

//¡ã¨¹o?¡À?¨ª¡¤???to¨®,2?¨®?¨¢¨ª¨ªa?¨´¡ã¨¹o?"REG51.H"

//?¨²o?¨¬?¨ºa1|?¨¹??¡ä??¡Â        // ?¡ä???¦Ì   ?¨¨¨º?
sfr ACC         =   0xE0;   //0000,0000 ¨¤??¨®?¡ÂAccumulator
sfr B           =   0xF0;   //0000,0000 B??¡ä??¡Â
sfr PSW         =   0xD0;   //0000,0000 3¨¬D¨°¡Á¡ä¨¬?¡Á?
sbit CY         =   PSW^7;
sbit AC         =   PSW^6;
sbit F0         =   PSW^5;
sbit RS1        =   PSW^4;
sbit RS0        =   PSW^3;
sbit OV         =   PSW^2;
sbit P          =   PSW^0;
sfr SP          =   0x81;   //0000,0111 ????????
sfr DPL         =   0x82;   //0000,0000 ¨ºy?Y????¦Ì¨ª¡Á??¨²
sfr DPH         =   0x83;   //0000,0000 ¨ºy?Y??????¡Á??¨²

//I/O ?¨²¨¬?¨ºa1|?¨¹??¡ä??¡Â
sfr P0          =   0x80;   //1111,1111 ???¨²0
sbit P00        =   P0^0;
sbit P01        =   P0^1;
sbit P02        =   P0^2;
sbit P03        =   P0^3;
sbit P04        =   P0^4;
sbit P05        =   P0^5;
sbit P06        =   P0^6;
sbit P07        =   P0^7;
sfr P1          =   0x90;   //1111,1111 ???¨²1
sbit P10        =   P1^0;
sbit P11        =   P1^1;
sbit P12        =   P1^2;
sbit P13        =   P1^3;
sbit P14        =   P1^4;
sbit P15        =   P1^5;
sbit P16        =   P1^6;
sbit P17        =   P1^7;
sfr P2          =   0xA0;   //1111,1111 ???¨²2
sbit P20        =   P2^0;
sbit P21        =   P2^1;
sbit P22        =   P2^2;
sbit P23        =   P2^3;
sbit P24        =   P2^4;
sbit P25        =   P2^5;
sbit P26        =   P2^6;
sbit P27        =   P2^7;
sfr P3          =   0xB0;   //1111,1111 ???¨²3
sbit P30        =   P3^0;
sbit P31        =   P3^1;
sbit P32        =   P3^2;
sbit P33        =   P3^3;
sbit P34        =   P3^4;
sbit P35        =   P3^5;
sbit P36        =   P3^6;
sbit P37        =   P3^7;
sfr P4          =   0xC0;   //1111,1111 ???¨²4
sbit P40        =   P4^0;
sbit P41        =   P4^1;
sbit P42        =   P4^2;
sbit P43        =   P4^3;
sbit P44        =   P4^4;
sbit P45        =   P4^5;
sbit P46        =   P4^6;
sbit P47        =   P4^7;
sfr P5          =   0xC8;   //xxxx,1111 ???¨²5
sbit P50        =   P5^0;
sbit P51        =   P5^1;
sbit P52        =   P5^2;
sbit P53        =   P5^3;
sbit P54        =   P5^4;
sbit P55        =   P5^5;
sbit P56        =   P5^6;
sbit P57        =   P5^7;
sfr P6          =   0xE8;   //0000,0000 ???¨²6
sbit P60        =   P6^0;
sbit P61        =   P6^1;
sbit P62        =   P6^2;
sbit P63        =   P6^3;
sbit P64        =   P6^4;
sbit P65        =   P6^5;
sbit P66        =   P6^6;
sbit P67        =   P6^7;
sfr P7          =   0xF8;   //0000,0000 ???¨²7
sbit P70        =   P7^0;
sbit P71        =   P7^1;
sbit P72        =   P7^2;
sbit P73        =   P7^3;
sbit P74        =   P7^4;
sbit P75        =   P7^5;
sbit P76        =   P7^6;
sbit P77        =   P7^7;
sfr P0M0        =   0x94;   //0000,0000 ???¨²0?¡ê¨º???¡ä??¡Â0
sfr P0M1        =   0x93;   //0000,0000 ???¨²0?¡ê¨º???¡ä??¡Â1
sfr P1M0        =   0x92;   //0000,0000 ???¨²1?¡ê¨º???¡ä??¡Â0
sfr P1M1        =   0x91;   //0000,0000 ???¨²1?¡ê¨º???¡ä??¡Â1
sfr P2M0        =   0x96;   //0000,0000 ???¨²2?¡ê¨º???¡ä??¡Â0
sfr P2M1        =   0x95;   //0000,0000 ???¨²2?¡ê¨º???¡ä??¡Â1
sfr P3M0        =   0xB2;   //0000,0000 ???¨²3?¡ê¨º???¡ä??¡Â0
sfr P3M1        =   0xB1;   //0000,0000 ???¨²3?¡ê¨º???¡ä??¡Â1
sfr P4M0        =   0xB4;   //0000,0000 ???¨²4?¡ê¨º???¡ä??¡Â0
sfr P4M1        =   0xB3;   //0000,0000 ???¨²4?¡ê¨º???¡ä??¡Â1
sfr P5M0        =   0xCA;   //0000,0000 ???¨²5?¡ê¨º???¡ä??¡Â0
sfr P5M1        =   0xC9;   //0000,0000 ???¨²5?¡ê¨º???¡ä??¡Â1
sfr P6M0        =   0xCC;   //0000,0000 ???¨²6?¡ê¨º???¡ä??¡Â0
sfr P6M1        =   0xCB;   //0000,0000 ???¨²6?¡ê¨º???¡ä??¡Â1
sfr P7M0        =   0xE2;   //0000,0000 ???¨²7?¡ê¨º???¡ä??¡Â0
sfr P7M1        =   0xE1;   //0000,0000 ???¨²7?¡ê¨º???¡ä??¡Â1

//?¦Ì¨ª31¨¹¨¤¨ª¨¬?¨ºa1|?¨¹??¡ä??¡Â
sfr PCON        =   0x87;   //0001,0000 ¦Ì??¡ä??????¡ä??¡Â
sfr AUXR        =   0x8E;   //0000,0000 ?¡§?¨²??¡ä??¡Â
sfr AUXR1       =   0xA2;   //0000,0000 ?¡§?¨²??¡ä??¡Â1
sfr P_SW1       =   0xA2;   //0000,0000 ¨ªa¨¦¨¨???¨²?D????¡ä??¡Â1
sfr CLK_DIV     =   0x97;   //0000,0000 ¨º¡À?¨®¡¤??¦Ì??????¡ä??¡Â
sfr BUS_SPEED   =   0xA1;   //xx10,x011 ¡Á¨¹???¨´?¨¨??????¡ä??¡Â
sfr P1ASF       =   0x9D;   //0000,0000 ???¨²1?¡ê?a1|?¨¹??????¡ä??¡Â
sfr P_SW2       =   0xBA;   //0xxx,x000 ¨ªa¨¦¨¨???¨²?D????¡ä??¡Â

//?D??¨¬?¨ºa1|?¨¹??¡ä??¡Â
sfr IE          =   0xA8;   //0000,0000 ?D????????¡ä??¡Â
sbit EA         =   IE^7;
sbit ELVD       =   IE^6;
sbit EADC       =   IE^5;
sbit ES         =   IE^4;
sbit ET1        =   IE^3;
sbit EX1        =   IE^2;
sbit ET0        =   IE^1;
sbit EX0        =   IE^0;
sfr IP          =   0xB8;   //0000,0000 ?D??¨®??¨¨????¡ä??¡Â
sbit PPCA       =   IP^7;
sbit PLVD       =   IP^6;
sbit PADC       =   IP^5;
sbit PS         =   IP^4;
sbit PT1        =   IP^3;
sbit PX1        =   IP^2;
sbit PT0        =   IP^1;
sbit PX0        =   IP^0;
sfr IE2         =   0xAF;   //0000,0000 ?D????????¡ä??¡Â2
sfr IP2         =   0xB5;   //xxxx,xx00 ?D??¨®??¨¨????¡ä??¡Â2
sfr INT_CLKO    =   0x8F;   //0000,0000 ¨ªa2??D??¨®?¨º¡À?¨®¨º?3???????¡ä??¡Â

//?¡§¨º¡À?¡Â¨¬?¨ºa1|?¨¹??¡ä??¡Â
sfr TCON        =   0x88;   //0000,0000 T0/T1??????¡ä??¡Â
sbit TF1        =   TCON^7;
sbit TR1        =   TCON^6;
sbit TF0        =   TCON^5;
sbit TR0        =   TCON^4;
sbit IE1        =   TCON^3;
sbit IT1        =   TCON^2;
sbit IE0        =   TCON^1;
sbit IT0        =   TCON^0;
sfr TMOD        =   0x89;   //0000,0000 T0/T1?¡ê¨º???¡ä??¡Â
sfr TL0         =   0x8A;   //0000,0000 T0¦Ì¨ª¡Á??¨²
sfr TL1         =   0x8B;   //0000,0000 T1¦Ì¨ª¡Á??¨²
sfr TH0         =   0x8C;   //0000,0000 T0??¡Á??¨²
sfr TH1         =   0x8D;   //0000,0000 T1??¡Á??¨²
sfr T4T3M       =   0xD1;   //0000,0000 T3/T4?¡ê¨º???¡ä??¡Â
sfr T3T4M       =   0xD1;   //0000,0000 T3/T4?¡ê¨º???¡ä??¡Â
sfr T4H         =   0xD2;   //0000,0000 T4??¡Á??¨²
sfr T4L         =   0xD3;   //0000,0000 T4¦Ì¨ª¡Á??¨²
sfr T3H         =   0xD4;   //0000,0000 T3??¡Á??¨²
sfr T3L         =   0xD5;   //0000,0000 T3¦Ì¨ª¡Á??¨²
sfr T2H         =   0xD6;   //0000,0000 T2??¡Á??¨²
sfr T2L         =   0xD7;   //0000,0000 T2¦Ì¨ª¡Á??¨²
sfr WKTCL       =   0xAA;   //0000,0000 ¦Ì?¦Ì???D??¡§¨º¡À?¡Â¦Ì¨ª¡Á??¨²
sfr WKTCH       =   0xAB;   //0000,0000 ¦Ì?¦Ì???D??¡§¨º¡À?¡Â??¡Á??¨²
sfr WDT_CONTR   =   0xC1;   //0000,0000 ?¡ä??1¡¤??????¡ä??¡Â

//¡ä?DD?¨²¨¬?¨ºa1|?¨¹??¡ä??¡Â
sfr SCON        =   0x98;   //0000,0000 ¡ä??¨²1??????¡ä??¡Â
sbit SM0        =   SCON^7;
sbit SM1        =   SCON^6;
sbit SM2        =   SCON^5;
sbit REN        =   SCON^4;
sbit TB8        =   SCON^3;
sbit RB8        =   SCON^2;
sbit TI         =   SCON^1;
sbit RI         =   SCON^0;
sfr SBUF        =   0x99;   //xxxx,xxxx ¡ä??¨²1¨ºy?Y??¡ä??¡Â
sfr S2CON       =   0x9A;   //0000,0000 ¡ä??¨²2??????¡ä??¡Â
sfr S2BUF       =   0x9B;   //xxxx,xxxx ¡ä??¨²2¨ºy?Y??¡ä??¡Â
sfr S3CON       =   0xAC;   //0000,0000 ¡ä??¨²3??????¡ä??¡Â
sfr S3BUF       =   0xAD;   //xxxx,xxxx ¡ä??¨²3¨ºy?Y??¡ä??¡Â
sfr S4CON       =   0x84;   //0000,0000 ¡ä??¨²4??????¡ä??¡Â
sfr S4BUF       =   0x85;   //xxxx,xxxx ¡ä??¨²4¨ºy?Y??¡ä??¡Â
sfr SADDR       =   0xA9;   //0000,0000 ¡ä¨®?¨²¦Ì??¡¤??¡ä??¡Â
sfr SADEN       =   0xB9;   //0000,0000 ¡ä¨®?¨²¦Ì??¡¤?¨¢¡À???¡ä??¡Â

//ADC ¨¬?¨ºa1|?¨¹??¡ä??¡Â
sfr ADC_CONTR   =   0xBC;   //0000,0000 A/D¡Áa????????¡ä??¡Â
sfr ADC_RES     =   0xBD;   //0000,0000 A/D¡Áa???¨¢1???8??
sfr ADC_RESL    =   0xBE;   //0000,0000 A/D¡Áa???¨¢1?¦Ì¨ª2??

//SPI ¨¬?¨ºa1|?¨¹??¡ä??¡Â
sfr SPSTAT      =   0xCD;   //00xx,xxxx SPI¡Á¡ä¨¬???¡ä??¡Â
sfr SPCTL       =   0xCE;   //0000,0100 SPI??????¡ä??¡Â
sfr SPDAT       =   0xCF;   //0000,0000 SPI¨ºy?Y??¡ä??¡Â

//IAP/ISP ¨¬?¨ºa1|?¨¹??¡ä??¡Â
sfr IAP_DATA    =   0xC2;   //0000,0000 EEPROM¨ºy?Y??¡ä??¡Â
sfr IAP_ADDRH   =   0xC3;   //0000,0000 EEPROM¦Ì??¡¤??¡Á??¨²
sfr IAP_ADDRL   =   0xC4;   //0000,0000 EEPROM¦Ì??¡¤¦Ì¨²¡Á??¨²
sfr IAP_CMD     =   0xC5;   //xxxx,xx00 EEPROM?¨¹¨¢???¡ä??¡Â
sfr IAP_TRIG    =   0xC6;   //0000,0000 EEPRPM?¨¹¨¢?¡ä£¤¡¤¡é??¡ä??¡Â
sfr IAP_CONTR   =   0xC7;   //0000,x000 EEPROM??????¡ä??¡Â

//PCA/PWM ¨¬?¨ºa1|?¨¹??¡ä??¡Â
sfr CCON        =   0xD8;   //00xx,xx00 PCA??????¡ä??¡Â
sbit CF         =   CCON^7;
sbit CR         =   CCON^6;
sbit CCF2       =   CCON^2;
sbit CCF1       =   CCON^1;
sbit CCF0       =   CCON^0;
sfr CMOD        =   0xD9;   //0xxx,x000 PCA 1¡è¡Á¡Â?¡ê¨º???¡ä??¡Â
sfr CL          =   0xE9;   //0000,0000 PCA??¨ºy?¡Â¦Ì¨ª¡Á??¨²
sfr CH          =   0xF9;   //0000,0000 PCA??¨ºy?¡Â??¡Á??¨²
sfr CCAPM0      =   0xDA;   //0000,0000 PCA?¡ê?¨¦0¦Ì?PWM??¡ä??¡Â
sfr CCAPM1      =   0xDB;   //0000,0000 PCA?¡ê?¨¦1¦Ì?PWM??¡ä??¡Â
sfr CCAPM2      =   0xDC;   //0000,0000 PCA?¡ê?¨¦2¦Ì?PWM ??¡ä??¡Â
sfr CCAP0L      =   0xEA;   //0000,0000 PCA?¡ê?¨¦0¦Ì?2?¡Á?/¡À¨¨????¡ä??¡Â¦Ì¨ª¡Á??¨²
sfr CCAP1L      =   0xEB;   //0000,0000 PCA?¡ê?¨¦1¦Ì?2?¡Á?/¡À¨¨????¡ä??¡Â¦Ì¨ª¡Á??¨²
sfr CCAP2L      =   0xEC;   //0000,0000 PCA?¡ê?¨¦2¦Ì?2?¡Á?/¡À¨¨????¡ä??¡Â¦Ì¨ª¡Á??¨²
sfr PCA_PWM0    =   0xF2;   //xxxx,xx00 PCA?¡ê?¨¦0¦Ì?PWM??¡ä??¡Â
sfr PCA_PWM1    =   0xF3;   //xxxx,xx00 PCA?¡ê?¨¦1¦Ì?PWM??¡ä??¡Â
sfr PCA_PWM2    =   0xF4;   //xxxx,xx00 PCA?¡ê?¨¦1¦Ì?PWM??¡ä??¡Â
sfr CCAP0H      =   0xFA;   //0000,0000 PCA?¡ê?¨¦0¦Ì?2?¡Á?/¡À¨¨????¡ä??¡Â??¡Á??¨²
sfr CCAP1H      =   0xFB;   //0000,0000 PCA?¡ê?¨¦1¦Ì?2?¡Á?/¡À¨¨????¡ä??¡Â??¡Á??¨²
sfr CCAP2H      =   0xFC;   //0000,0000 PCA?¡ê?¨¦2¦Ì?2?¡Á?/¡À¨¨????¡ä??¡Â??¡Á??¨²

//¡À¨¨???¡Â¨¬?¨ºa1|?¨¹??¡ä??¡Â
sfr CMPCR1      =   0xE6;   //0000,0000 ¡À¨¨???¡Â??????¡ä??¡Â1
sfr CMPCR2      =   0xE7;   //0000,0000 ¡À¨¨???¡Â??????¡ä??¡Â2

//????D¨ªPWM2¡§D?¡¤¡é¨¦¨²?¡Â¨¬?¨ºa1|?¨¹??¡ä??¡Â
sfr PWMCFG      =   0xf1;   //x000,0000 PWM??????¡ä??¡Â
sfr PWMCR       =   0xf5;   //0000,0000 PWM??????¡ä??¡Â
sfr PWMIF       =   0xf6;   //x000,0000 PWM?D??¡À¨º????¡ä??¡Â
sfr PWMFDCR     =   0xf7;   //xx00,0000 PWM¨ªa2?¨°¨¬3¡ê?¨¬2a??????¡ä??¡Â

//¨¨???¨¬?¨ºa1|?¨¹??¡ä??¡Â??¨®¨²¨¤??1RAM??¨®¨°
//¡¤??¨º?aD???¡ä??¡Â,D¨¨?¨¨??P_SW2¦Ì?BIT7¨¦¨¨???a1,2??¨¦?y3¡ê?¨¢D¡ä
#define PWMC        (*(unsigned int  volatile xdata *)0xfff0)
#define PWMCH       (*(unsigned char volatile xdata *)0xfff0)
#define PWMCL       (*(unsigned char volatile xdata *)0xfff1)
#define PWMCKS      (*(unsigned char volatile xdata *)0xfff2)
#define PWM2T1      (*(unsigned int  volatile xdata *)0xff00)
#define PWM2T1H     (*(unsigned char volatile xdata *)0xff00)
#define PWM2T1L     (*(unsigned char volatile xdata *)0xff01)
#define PWM2T2      (*(unsigned int  volatile xdata *)0xff02)
#define PWM2T2H     (*(unsigned char volatile xdata *)0xff02)
#define PWM2T2L     (*(unsigned char volatile xdata *)0xff03)
#define PWM2CR      (*(unsigned char volatile xdata *)0xff04)
#define PWM3T1      (*(unsigned int  volatile xdata *)0xff10)
#define PWM3T1H     (*(unsigned char volatile xdata *)0xff10)
#define PWM3T1L     (*(unsigned char volatile xdata *)0xff11)
#define PWM3T2      (*(unsigned int  volatile xdata *)0xff12)
#define PWM3T2H     (*(unsigned char volatile xdata *)0xff12)
#define PWM3T2L     (*(unsigned char volatile xdata *)0xff13)
#define PWM3CR      (*(unsigned char volatile xdata *)0xff14)
#define PWM4T1      (*(unsigned int  volatile xdata *)0xff20)
#define PWM4T1H     (*(unsigned char volatile xdata *)0xff20)
#define PWM4T1L     (*(unsigned char volatile xdata *)0xff21)
#define PWM4T2      (*(unsigned int  volatile xdata *)0xff22)
#define PWM4T2H     (*(unsigned char volatile xdata *)0xff22)
#define PWM4T2L     (*(unsigned char volatile xdata *)0xff23)
#define PWM4CR      (*(unsigned char volatile xdata *)0xff24)
#define PWM5T1      (*(unsigned int  volatile xdata *)0xff30)
#define PWM5T1H     (*(unsigned char volatile xdata *)0xff30)
#define PWM5T1L     (*(unsigned char volatile xdata *)0xff31)
#define PWM5T2      (*(unsigned int  volatile xdata *)0xff32)
#define PWM5T2H     (*(unsigned char volatile xdata *)0xff32)
#define PWM5T2L     (*(unsigned char volatile xdata *)0xff33)
#define PWM5CR      (*(unsigned char volatile xdata *)0xff34)
#define PWM6T1      (*(unsigned int  volatile xdata *)0xff40)
#define PWM6T1H     (*(unsigned char volatile xdata *)0xff40)
#define PWM6T1L     (*(unsigned char volatile xdata *)0xff41)
#define PWM6T2      (*(unsigned int  volatile xdata *)0xff42)
#define PWM6T2H     (*(unsigned char volatile xdata *)0xff42)
#define PWM6T2L     (*(unsigned char volatile xdata *)0xff43)
#define PWM6CR      (*(unsigned char volatile xdata *)0xff44)
#define PWM7T1      (*(unsigned int  volatile xdata *)0xff50)        
#define PWM7T1H     (*(unsigned char volatile xdata *)0xff50)        
#define PWM7T1L     (*(unsigned char volatile xdata *)0xff51)
#define PWM7T2      (*(unsigned int  volatile xdata *)0xff52)
#define PWM7T2H     (*(unsigned char volatile xdata *)0xff52)
#define PWM7T2L     (*(unsigned char volatile xdata *)0xff53)
#define PWM7CR      (*(unsigned char volatile xdata *)0xff54)

/////////////////////////////////////////////////

#endif


