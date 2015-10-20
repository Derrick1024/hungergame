#ifndef __PWM3_OUTPUT_H
#define	__PWM3_OUTPUT_H

#include "stm32f10x.h"

#define SERVO_ON 1
#define SERVO_OFF 0
#define SERVO_ON_DEG 440
#define SERVO_OFF_DEG 590


void TIM3_PWM_Init(void);
void TIM3_Mode_Config(void);
void TIM3_CH1_Mode_Config(u16 CCR1_Val);
void TIM3_CH2_Mode_Config(u16 CCR2_Val);
void TIM3_CH3_Mode_Config(u16 CCR3_Val);
void TIM3_CH4_Mode_Config(u16 CCR4_Val);
void TIM3_direction_gpio_config(void);
void TIM3_ud_action(int pwm_up_down);
void TIM3_servo(uint16_t state);
void TIM3_servo_deg(uint16_t deg);

#endif /* __PWM3_OUTPUT_H */

