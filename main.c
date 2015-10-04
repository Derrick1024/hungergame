#include "main.h"


int main(void)
{
	//usart1初始化
	USART1_Config();
	//TIM3初始化
	TIM3_PWM_Init();
	//TIM4初始化
	TIM4_PWM_Init();
	//PS2手柄初始化
	PS2_Init();
	//其他GPIO初始化(led & switch)
	extra_gpio_init();
	
	//判断是否为红灯模式，0为红灯模式，1为非红灯模式 
	if(PS2_RedLight())
	{
		int led[5]={0},i;
		
		while(1)
		{
			led_action(led);
			if(PS2_RedLight())
			{
				break;
			}
			Delay_ms(300);
			for(i=0;i<5;i++)
			{
				led[i]=1;
			}
			led_action(led);
			if(PS2_RedLight())
			{
				break;
			}
			Delay_ms(300);
			for(i=0;i<5;i++)
			{
				led[i]=0;
			}
			
		}
		
	}
	else
	{
		while(1)
		{
			int i,key;
			int lx=0,ly=0,rx=0,ry=0;
			//获取lx ly rx ry 范围-127~128
			lx = (int)PS2_AnologData(PSS_LX)-127;
			ly = (int)PS2_AnologData(PSS_LY)-127;
			rx = (int)PS2_AnologData(PSS_RX)-127;
			ry = (int)PS2_AnologData(PSS_RY)-127;
			printf(" %5d %5d %5d %5d\n",lx,ly,rx,ry);
			
			
			
		}
		
	}
	while(1)
	{
		int i,key;
//		key=PS2_DataKey();
//		if(key!=0)                  
//    {
//			printf("  \r\n   %d  is  pressed  \r\n",key);
//    }

		printf(" %5d %5d %5d %5d\n",PS2_AnologData(PSS_LX),PS2_AnologData(PSS_LY),
		                              PS2_AnologData(PSS_RX),PS2_AnologData(PSS_RY) );
//		TIM4_CH1_Mode_Config(PS2_AnologData(PSS_LX)*3);
//		TIM4_CH2_Mode_Config(PS2_AnologData(PSS_LX)*3);
//		TIM4_CH3_Mode_Config(PS2_AnologData(PSS_LX)*3);
//		TIM4_CH4_Mode_Config(PS2_AnologData(PSS_LX)*3);
//		TIM3_CH1_Mode_Config(PS2_AnologData(PSS_LX)*3);
//		TIM3_CH2_Mode_Config(PS2_AnologData(PSS_LX)*3);
//		TIM3_CH3_Mode_Config(PS2_AnologData(PSS_LX)*3);
//		TIM3_CH4_Mode_Config(PS2_AnologData(PSS_LX)*3);
//      Delay_ms(50);
		
			                                   
	}
}

