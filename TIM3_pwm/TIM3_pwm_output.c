
/***************************
	PA.06: (TIM3_CH1)  
  PA.07: (TIM3_CH2)  
  PB.00: (TIM3_CH3) 
  PB.01: (TIM3_CH4)  
***************************/
#include "TIM3_pwm_output.h"

/*
 * ��������TIM3_GPIO_Config
 * ����  ������TIM3�������PWMʱ�õ���I/O
 * ����  ����
 * ���  ����
 * ����  ���ڲ�����
 */
static void TIM3_GPIO_Config(void) 
{
  GPIO_InitTypeDef GPIO_InitStructure;

	/* TIM3 clock enable */
	//PCLK1����2��Ƶ����ΪTIM3��ʱ��Դ����72MHz
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); 

  /* GPIOA and GPIOB clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE); 

  /*GPIOA Configuration: TIM3 channel 1 and 2 as alternate function push-pull */
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6|GPIO_Pin_7 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		    // �����������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

  GPIO_Init(GPIOA, &GPIO_InitStructure);
	/*GPIOB Configuration: TIM3 channel 3 and 4 as alternate function push-pull */
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0|GPIO_Pin_1 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		    // �����������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

  GPIO_Init(GPIOB, &GPIO_InitStructure);
}

/*
 * ��������TIM3_Mode_Config
 * ����  ������TIM3�����PWM�źŵ�ģʽ�������ڡ����ԡ�ռ�ձ�
 * ����  ����
 * ���  ����
 * ����  ���ڲ�����
 */

void TIM3_Mode_Config(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	/* Time base configuration */		 
  TIM_TimeBaseStructure.TIM_Period = 7199;       //����ʱ����0������7199����Ϊ7200�Σ�Ϊһ����ʱ����
	                                               //��������TIM�ϣ����pwmƵ�ʶ���Ϊ50Hz
  TIM_TimeBaseStructure.TIM_Prescaler =  199;	    //����Ԥ��Ƶ����Ƶ200����Ϊ360k
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;	//����ʱ�ӷ�Ƶϵ��������Ƶ
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //���ϼ���ģʽ

  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
}

void TIM3_CH1_Mode_Config(u16 CCR1_Val)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	/* PWM1 Mode configuration: Channel1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //����ΪPWMģʽ1
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	
  TIM_OCInitStructure.TIM_Pulse = CCR1_Val;	   //��������ֵ�������������������ֵʱ����ƽ��������
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //����ʱ������ֵС��CCR1_ValʱΪ�ߵ�ƽ

  TIM_OC1Init(TIM3, &TIM_OCInitStructure);	 //ʹ��ͨ��1
  TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
}
void TIM3_CH2_Mode_Config(u16 CCR2_Val)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	/* PWM1 Mode configuration: Channel2 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //����ΪPWMģʽ1
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	
  TIM_OCInitStructure.TIM_Pulse = CCR2_Val;	   //��������ֵ�������������������ֵʱ����ƽ��������
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //����ʱ������ֵС��CCR2_ValʱΪ�ߵ�ƽ

  TIM_OC2Init(TIM3, &TIM_OCInitStructure);	 //ʹ��ͨ��2
  TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
}
void TIM3_CH3_Mode_Config(u16 CCR3_Val)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	/* PWM1 Mode configuration: Channel3 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //����ΪPWMģʽ1
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	
  TIM_OCInitStructure.TIM_Pulse = CCR3_Val;	   //��������ֵ�������������������ֵʱ����ƽ��������
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //����ʱ������ֵС��CCR3_ValʱΪ�ߵ�ƽ

  TIM_OC3Init(TIM3, &TIM_OCInitStructure);	 //ʹ��ͨ��3
  TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
}
void TIM3_CH4_Mode_Config(u16 CCR4_Val)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	/* PWM1 Mode configuration: Channel4 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //����ΪPWMģʽ1
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	
  TIM_OCInitStructure.TIM_Pulse = CCR4_Val;	   //��������ֵ�������������������ֵʱ����ƽ��������
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //����ʱ������ֵС��CCR4_ValʱΪ�ߵ�ƽ

  TIM_OC4Init(TIM3, &TIM_OCInitStructure);	 //ʹ��ͨ��4
  TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
}

void TIM3_direction_gpio_config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; 

  /* GPIOA and GPIOA clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); 

  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_4|GPIO_Pin_5 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		    
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_ResetBits(GPIOA, GPIO_Pin_4);
	GPIO_ResetBits(GPIOA, GPIO_Pin_5);
	
}

void TIM3_PWM_Init(void)
{
	TIM3_GPIO_Config();
	TIM3_Mode_Config();
	
	TIM3_CH1_Mode_Config(0);
	TIM3_CH2_Mode_Config(0);
	TIM3_CH3_Mode_Config(0);
	TIM3_CH4_Mode_Config(0);
	
	TIM_ARRPreloadConfig(TIM3, ENABLE);			 // ʹ��TIM3���ؼĴ���ARR
  TIM_Cmd(TIM3, ENABLE);                   //ʹ�ܶ�ʱ��3	
	
	TIM3_direction_gpio_config();
	TIM3_servo(SERVO_ON);
}
//����Ϊ������ʼ������
/********************************************************************************************/

/********************************************************************************************/
//����Ϊ�߼��Զ��庯��

void TIM3_direction_action(int pwm_up_down)
{
	if(pwm_up_down == 0)
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_4);
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);
	}
		if(pwm_up_down < 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_4);
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);
		TIM3_CH1_Mode_Config(pwm_up_down);
	}
	if(pwm_up_down > 0)
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_4);
		GPIO_SetBits(GPIOA, GPIO_Pin_5);
		TIM3_CH1_Mode_Config(-pwm_up_down);
	}

}

//���ƶ���Ŀ��ϣ�state����ȡֵSERVO_ON(1)��SERVO_OFF(0)
void TIM3_servo(u8 state)
{
	//SERVO_ON SERVE_OFF��h�ļ����ж��壬Ϊ����ſ��ĽǶȶ�Ӧ��pwmֵ����Χ��179-539����ֵ��359
	if(state)
	{
		TIM3_CH2_Mode_Config(SERVO_ON_DEG);
	}
	else
	{
		TIM3_CH2_Mode_Config(SERVO_OFF_DEG);
	}
}

void TIM3_servo_deg(u8 deg)
{
	TIM3_CH2_Mode_Config(deg);
	
}


/******************* (C) COPYRIGHT 2012  *****END OF FILE************/
