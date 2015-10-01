#include "stm32f10x.h"
#include "systick_delay.h"
#include "bsp_usart1.h"
#include "TIM3_pwm_output.h"
#include "TIM4_pwm_output.h"
#include "pid.h"
#include "math.h"
#include "PS2.h"

//#define BYTE0(dwTemp)       (*(char *)(&dwTemp))
//#define BYTE1(dwTemp)       (*((char *)(&dwTemp) + 1))
//#define BYTE2(dwTemp)       (*((char *)(&dwTemp) + 2))
//#define BYTE3(dwTemp)       (*((char *)(&dwTemp) + 3))

//#define q30  1073741824.0f


int main(void)
{
	u8 key;

	//usart1初始化
	USART1_Config();
	//TIM3初始化
	TIM3_PWM_Init();
	//TIM4初始化
	TIM4_PWM_Init();
	//
	PS2_Init();

	
	while(1)
	{
		
		key=PS2_DataKey();
		if(key!=0)                  
    	{
            printf("  \r\n   %d  is  pressed  \r\n",key);
    	}
		printf(" %5d %5d %5d %5d\n",PS2_AnologData(PSS_LX),PS2_AnologData(PSS_LY),
		                              PS2_AnologData(PSS_RX),PS2_AnologData(PSS_RY) );
       Delay_ms(50);
		
			                                   
	}
}

