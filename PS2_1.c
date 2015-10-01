#ifndef __PS2_JOYPAD_H
#define __PS2_JOYPAD_H
#include "sys.h"
#include "delay.h"
#include "usart.h"

#define PS2_JOYPAD_DATA  PCin(0)
#define PS2_JOYPAD_CMND PCout(1)
#define PS2_JOYPAD_ATT PCout(2)
#define PS2_JOYPAD_CLOCK PCout(3)
#define PS2_JOYPAD_ACK PCin(4)

#define PS2_JOYPAD_CMND_START  0X01  //起始命令 
#define PS2_JOYPAD_CMND_DEMAND 0X42 //数据请求
#define PS2_JOYPAD_CMND_NOP   0X00   //idle

void PS2_Wireless_JOYPAD_Init(void);
u16 PS2_Wireless_JOYPAD_DATA(void);

#endif




#include "ps2_joypad.h"



//PS2无线手柄的初始化
//初始化成功返回0，失败返回1
void PS2_Wireless_JOYPAD_Init(void)
{
RCC->APB2ENR|=1<<4; //先使能外设PORTC时钟
GPIOC->CRL&=0XFFF00000;
GPIOC->CRL|=0X00083338;   
GPIOC->ODR|=1<<4;
GPIOC->ODR|=1<<3;
GPIOC->ODR|=1<<2;
GPIOC->ODR|=1<<1;
GPIOC->ODR|=1<<0;
PS2_JOYPAD_CLOCK=1;
PS2_JOYPAD_CMND=1;
PS2_JOYPAD_ATT=1;
delay_ms(10);
}

u8 PS2_Wireless_JOYPAD_WriteRead(u8 cmd)
{
u8 i=0;
u8 value=0;
u8 CMD=cmd;
for(i=0;i<8;i++)
{
PS2_JOYPAD_CLOCK=1;
if(CMD&0x01)PS2_JOYPAD_CMND=1;
else PS2_JOYPAD_CMND=0;
CMD>>=1;
delay_us(10);
PS2_JOYPAD_CLOCK=0;
delay_us(15);
value>>=1;
if(PS2_JOYPAD_DATA)value|=0x80; //0000 0000
}
PS2_JOYPAD_CLOCK=1;
return value;
}

//检测应答函数
//有应答信号返回0，无应答信号返回1
u8 PS2_Wireless_JOYPAD_ACK(void)
{
u8 i=0;
PS2_JOYPAD_CLOCK=1;
delay_us(5);
PS2_JOYPAD_CLOCK=0;
while(i<100)
{
if(0==PS2_JOYPAD_ACK)break;
i++;
}
PS2_JOYPAD_CLOCK=1;
return i<100?0:1;
}

//读取数据函数
//成功返回0，失败返回1
u16 PS2_Wireless_JOYPAD_DATA(void)
{
u8 PS2_JOYPAD_ID=0;
u8 table[3]={0};
//LEFT DOWN RGHT UP STRT X X SLCT       正方形 叉 圆形三角形 R1 L1 R2 L2 
u16 PS2_VALUE=0XFFFF;

PS2_JOYPAD_ATT=0;//片选使能
delay_us(10);

PS2_Wireless_JOYPAD_WriteRead(PS2_JOYPAD_CMND_START);
if(1==PS2_Wireless_JOYPAD_ACK())return 1;
//手柄ID号，我的是数字手柄返回0X41
PS2_JOYPAD_ID=PS2_Wireless_JOYPAD_WriteRead(PS2_JOYPAD_CMND_DEMAND);
if(1==PS2_Wireless_JOYPAD_ACK())return 1;
table[0]=PS2_Wireless_JOYPAD_WriteRead(PS2_JOYPAD_CMND_NOP);//0x5a
if(1==PS2_Wireless_JOYPAD_ACK())return 1;
table[1]=PS2_Wireless_JOYPAD_WriteRead(PS2_JOYPAD_CMND_NOP);//data1
if(1==PS2_Wireless_JOYPAD_ACK())return 1;
table[2]=PS2_Wireless_JOYPAD_WriteRead(PS2_JOYPAD_CMND_NOP);//data2

PS2_VALUE=(table[1]<<8)|table[2];

delay_us(10);
PS2_JOYPAD_ATT=1;

return PS2_VALUE;
}
