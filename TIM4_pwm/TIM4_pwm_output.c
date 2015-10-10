
/***************************
	PB.06: (TIM4_CH1)  
  PB.07: (TIM4_CH2)  
  PB.08: (TIM4_CH3) 
  PB.09: (TIM4_CH4)  
***************************/
#include "TIM4_pwm_output.h"

/*
 * 函数名：TIM4_GPIO_Config
 * 描述  ：配置TIM4复用输出PWM时用到的I/O
 * 输入  ：无
 * 输出  ：无
 * 调用  ：内部调用
 */
static void TIM4_GPIO_Config(void) 
{
  GPIO_InitTypeDef GPIO_InitStructure;

	/* TIM4 clock enable */
	//PCLK1经过2倍频后作为TIM4的时钟源等于72MHz
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE); 

  /* GPIOA and GPIOB clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE); 

  /*GPIOA Configuration: TIM4 channel 1 and 2 as alternate function push-pull */
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		    // 复用推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

  GPIO_Init(GPIOB, &GPIO_InitStructure);

}

/*
 * 函数名：TIM4_Mode_Config
 * 描述  ：配置TIM4输出的PWM信号的模式，如周期、极性、占空比
 * 输入  ：无
 * 输出  ：无
 * 调用  ：内部调用
 */
void TIM4_Mode_Config(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	/* Time base configuration */		 
  TIM_TimeBaseStructure.TIM_Period = 512;       //当定时器从0计数到999，即为1000次，为一个定时周期
  TIM_TimeBaseStructure.TIM_Prescaler = 8;	    //设置预分频：不预分频，即为72MHz
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;	//设置时钟分频系数：不分频
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //向上计数模式

  TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	
}

void TIM4_CH1_Mode_Config(u16 CCR1_Val)
{
	
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //配置为PWM模式1
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //当定时器计数值小于CCR1_Val时为高电平
	
	/* PWM1 Mode configuration: Channel3 */
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = CCR1_Val;	  //设置通道1的电平跳变值，输出另外一个占空比的PWM

  TIM_OC1Init(TIM4, &TIM_OCInitStructure);	  //使能通道1
  TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);
	
}

void TIM4_CH2_Mode_Config(u16 CCR2_Val)
{
	
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //配置为PWM模式1
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //当定时器计数值小于CCR2_Val时为高电平
	
	/* PWM1 Mode configuration: Channel3 */
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = CCR2_Val;	  //设置通道2的电平跳变值，输出另外一个占空比的PWM

  TIM_OC2Init(TIM4, &TIM_OCInitStructure);	  //使能通道2
  TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);
	
}

void TIM4_CH3_Mode_Config(u16 CCR3_Val)
{
	
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //配置为PWM模式1
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //当定时器计数值小于CCR3_Val时为高电平
	
	/* PWM1 Mode configuration: Channel3 */
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = CCR3_Val;	  //设置通道3的电平跳变值，输出另外一个占空比的PWM

  TIM_OC3Init(TIM4, &TIM_OCInitStructure);	  //使能通道3
  TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);
		
}

void TIM4_CH4_Mode_Config(u16 CCR4_Val)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //配置为PWM模式1
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //当定时器计数值小于CCR4_Val时为高电平
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = CCR4_Val;	  //设置通道4的电平跳变值，输出另外一个占空比的PWM

  TIM_OC4Init(TIM4, &TIM_OCInitStructure);	  //使能通道4
  TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);

}

void TIM4_direction_gpio_config(void)
{	
	GPIO_InitTypeDef GPIO_InitStructure; 
  /* GPIOA GPIOB clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB , ENABLE); 
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_13 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		    
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		    
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

  GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_ResetBits(GPIOA, GPIO_Pin_0);
	GPIO_ResetBits(GPIOA, GPIO_Pin_1);
	GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	GPIO_ResetBits(GPIOA, GPIO_Pin_3);
	GPIO_ResetBits(GPIOA, GPIO_Pin_13);
	GPIO_ResetBits(GPIOB, GPIO_Pin_3);
	GPIO_ResetBits(GPIOB, GPIO_Pin_4);
	GPIO_ResetBits(GPIOB, GPIO_Pin_5);
	
}

void TIM4_PWM_Init(void)
{
	TIM4_GPIO_Config();
	TIM4_Mode_Config();
	
	TIM4_CH1_Mode_Config(0);
	TIM4_CH2_Mode_Config(0);
	TIM4_CH3_Mode_Config(0);
	TIM4_CH4_Mode_Config(0);
	
	TIM_ARRPreloadConfig(TIM4, ENABLE);			 // 使能TIM4重载寄存器ARR
  TIM_Cmd(TIM4, ENABLE);                   //使能定时器4	
	
	TIM4_direction_gpio_config();
	
}

void TIM4_forward_action(int pwm_forward)
{
	//判断pwm_forward	
	if(pwm_forward == 0)
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_4);
		GPIO_ResetBits(GPIOB, GPIO_Pin_5);
	}
	else 
		if(pwm_forward > 0)
		{
			GPIO_ResetBits(GPIOB, GPIO_Pin_5);
			GPIO_SetBits(GPIOB, GPIO_Pin_4);
			TIM4_CH1_Mode_Config(pwm_forward);
		}
		else 
			if(pwm_forward < 0)
			{
				GPIO_SetBits(GPIOB, GPIO_Pin_5);
				GPIO_ResetBits(GPIOB, GPIO_Pin_4);
				TIM4_CH1_Mode_Config(-pwm_forward);
			}
			
}

void TIM4_backward_action(int pwm_backward)
{
	if(pwm_backward == 0)
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_3);
		GPIO_ResetBits(GPIOA, GPIO_Pin_13);
	}
	else 
		if(pwm_backward > 0)
		{
			GPIO_ResetBits(GPIOB, GPIO_Pin_3);
			GPIO_SetBits(GPIOA, GPIO_Pin_13);
			TIM4_CH2_Mode_Config(pwm_backward);
		}
		else 
			if(pwm_backward < 0)
			{
				GPIO_SetBits(GPIOB, GPIO_Pin_3);
				GPIO_ResetBits(GPIOA, GPIO_Pin_13);
				TIM4_CH2_Mode_Config(-pwm_backward);
			}
}

void TIM4_left_action(int pwm_left)
{
	//判断pwm_left	
	if(pwm_left == 0)
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_0);
		GPIO_ResetBits(GPIOA, GPIO_Pin_1);
	}
	else 
		if(pwm_left > 0)
		{
			GPIO_ResetBits(GPIOA, GPIO_Pin_0);
			GPIO_SetBits(GPIOA, GPIO_Pin_1);
			TIM4_CH3_Mode_Config(pwm_left);
		}
		else 
			if(pwm_left < 0)
			{
				GPIO_SetBits(GPIOA, GPIO_Pin_0);
				GPIO_ResetBits(GPIOA, GPIO_Pin_1);
				TIM4_CH3_Mode_Config(-pwm_left);
			}
}

void TIM4_right_action(int pwm_right)
{
	//判断pwm_right	
	if(pwm_right == 0)
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);
		GPIO_ResetBits(GPIOA, GPIO_Pin_3);
	}
	else 
		if(pwm_right > 0)
		{
			GPIO_ResetBits(GPIOA, GPIO_Pin_2);
			GPIO_SetBits(GPIOA, GPIO_Pin_3);
			TIM4_CH4_Mode_Config(pwm_right);
		}
		else 
			if(pwm_right < 0)
			{
				GPIO_SetBits(GPIOA, GPIO_Pin_2);
				GPIO_ResetBits(GPIOA, GPIO_Pin_3);
				TIM4_CH4_Mode_Config(-pwm_right);
			}
}

void TIM4_fblr_action(int pwm_forward,int pwm_backward,int pwm_left,int pwm_right)
{
	TIM4_forward_action(pwm_forward);
	TIM4_backward_action(pwm_backward);
	TIM4_left_action(pwm_left);
	TIM4_right_action(pwm_right);
}










/******************* (C) COPYRIGHT 2012  *****END OF FILE************/
