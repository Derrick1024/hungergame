#ifndef __PWM4_OUTPUT_H
#define	__PWM4_OUTPUT_H

#include "stm32f10x.h"

void TIM4_Mode_Config(void);
void TIM4_CH1_Mode_Config(u16 CCR1_Val);
void TIM4_CH2_Mode_Config(u16 CCR2_Val);
void TIM4_CH3_Mode_Config(u16 CCR3_Val);
void TIM4_CH4_Mode_Config(u16 CCR4_Val);
void TIM4_direction_action(int pwm_forward,int pwm_backward,int pwm_left,int pwm_right);
void TIM4_direction_gpio_config(void);
void TIM4_PWM_Init(void);

#endif /* __PWM4_OUTPUT_H */

