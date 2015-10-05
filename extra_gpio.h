#include "stm32f10x.h"
#include "systick_delay.h"

#define PORT_SWITCH GPIOC
#define GPIO_SWITCH1 GPIO_Pin_13
#define GPIO_SWITCH2 GPIO_Pin_14
//#define GPIO_SWITCH3 GPIO_Pin_15

#define PORT_LED1 GPIOA
#define PORT_LED2 GPIOB
#define GPIO_LED1 GPIO_Pin_4
#define GPIO_LED2 GPIO_Pin_5
#define GPIO_LED3 GPIO_Pin_2
#define GPIO_LED4 GPIO_Pin_11
#define GPIO_LED5 GPIO_Pin_10

void extra_gpio_init(void);
void led_action(int led[]);
void led_on(int a);
void led_off(int a);
int state_switch1(void);
int state_switch2(void);
void led_twinkle(void);









