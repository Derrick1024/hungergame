/*
PA 0					PB 0
PA 1					PB 1
PA 2					PB 2
PA 3					PB 3
PA 4					PB 4
PA 5					PB 5
PA 6					PB 6
PA 7					PB 7
PA 8					PB 8
PA 9					PB 9
PA 10					PB 10
PA 11					PB 11
PA 12					PB 12
PA 13					PB 13
PA 14					PB 14
PA 15					PB 15



*/
#include "stm32f10x.h"
#include "systick_delay.h"
#include "bsp_usart1.h"
#include "TIM3_pwm_output.h"
#include "TIM4_pwm_output.h"
//#include "math.h"
#include "PS2.h"




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
	
	
	//判断是否为红灯模式，0为红灯模式，1为非红灯模式 
	if(PS2_RedLight())
	{
		;
	}
	else
	{
		;
	}
	while(1)
	{
		int i,key;
//		key=PS2_DataKey();
//		if(key!=0)                  
//    {
//			printf("  \r\n   %d  is  pressed  \r\n",key);
//    }
		for(i=0;i<100;i++)
		{
			key=PS2_DataKey();
			Delay_ms(5);
		}
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

