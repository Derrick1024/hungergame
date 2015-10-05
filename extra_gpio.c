#include "extra_gpio.h"


void extra_gpio_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC , ENABLE); 
	//限位开关
	GPIO_InitStructure.GPIO_Pin=GPIO_SWITCH1|GPIO_SWITCH2;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_2MHz; 
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;
	GPIO_Init(PORT_SWITCH,&GPIO_InitStructure);
	
	//led
	GPIO_InitStructure.GPIO_Pin=GPIO_LED1|GPIO_LED2;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_10MHz; 
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(PORT_LED1,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_LED3|GPIO_LED4|GPIO_LED5;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_10MHz; 
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(PORT_LED2,&GPIO_InitStructure);
	
}

void led_action(int led[])
{
//	if(led[0])
//		GPIO_SetBits(PORT_LED, GPIO_LED1);
//	else
//		GPIO_ResetBits(PORT_LED, GPIO_LED1);
//	if(led[1])
//		GPIO_SetBits(PORT_LED, GPIO_LED2);
//	else
//		GPIO_ResetBits(PORT_LED, GPIO_LED2);
//	if(led[2])
//		GPIO_SetBits(PORT_LED, GPIO_LED3);
//	else
//		GPIO_ResetBits(PORT_LED, GPIO_LED3);
//	if(led[3])
//		GPIO_SetBits(PORT_LED, GPIO_LED4);
//	else
//		GPIO_ResetBits(PORT_LED, GPIO_LED4);
//	if(led[4])
//		GPIO_SetBits(PORT_LED, GPIO_LED5);
//	else
//		GPIO_ResetBits(PORT_LED, GPIO_LED5);
	int i;
	for(i=0;i<5;i++)
	{
		if(led[i])
			led_on(i+1);
		else
			led_off(i+1);
	}
}

void led_on(int a)
{
	switch (a)
	{
		case 1: GPIO_SetBits(PORT_LED1, GPIO_LED1);break;
		case 2: GPIO_SetBits(PORT_LED1, GPIO_LED2);break;
		case 3: GPIO_SetBits(PORT_LED2, GPIO_LED3);break;
		case 4: GPIO_SetBits(PORT_LED2, GPIO_LED4);break;
		case 5: GPIO_SetBits(PORT_LED2, GPIO_LED5);break;
	}
		
}

void led_off(int a)
{
	switch (a)
	{
		case 1: GPIO_ResetBits(PORT_LED1, GPIO_LED1);break;
		case 2: GPIO_ResetBits(PORT_LED1, GPIO_LED2);break;
		case 3: GPIO_ResetBits(PORT_LED2, GPIO_LED3);break;
		case 4: GPIO_ResetBits(PORT_LED2, GPIO_LED4);break;
		case 5: GPIO_ResetBits(PORT_LED2, GPIO_LED5);break;
	}
		
}

int state_switch1(void)
{
	if(GPIO_ReadInputDataBit(PORT_SWITCH,GPIO_SWITCH1)== Bit_SET)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int state_switch2(void)
{
	if(GPIO_ReadInputDataBit(PORT_SWITCH,GPIO_SWITCH2)== Bit_SET)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void led_twinkle(void)
{
		int led[5]={0},i;
		
			for(i=0;i<5;i++)
			{
				led[i]=1;
			}
			led_action(led);
			Delay_ms(300);
			for(i=0;i<5;i++)
			{
				led[i]=0;
			}
			led_action(led);
			Delay_ms(300);
}











