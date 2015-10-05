#include "main.h"


int main(void)
{
	
	//usart1初始化
	USART1_Config();
	//TIM3初始化
	TIM3_PWM_Init();
	//TIM4初始化
	TIM4_PWM_Init();
	//清除调试口jtag & swd，下载的时候要按住复位键
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable , ENABLE);
//	GPIO_PinRemapConfig(GPIO_Remap_SWJ_NoJTRST , ENABLE);
	//PS2手柄初始化
	PS2_Init();
	//其他GPIO初始化(led & switch)
	extra_gpio_init();
	
//	//判断是否为红灯模式，0为红灯模式，1为非红灯模式 
//	while(1)
//	{
////		while(!PS2_RedLight())
//		{
//			int i,key;
//			int lx=0,ly=0,rx=0,ry=0;
//			int pwm_forward=0,pwm_backward=0,pwm_left=0,pwm_right=0;
//			
//			Delay_ms(50);
//			//获取key的值
//			key=PS2_DataKey();
//			//获取lx ly rx ry 范围-127~128
//			lx = (int)PS2_AnologData(PSS_LX)-127;
//			ly = (int)PS2_AnologData(PSS_LY)-127;
//			rx = (int)PS2_AnologData(PSS_RX)-127;
//			ry = (int)PS2_AnologData(PSS_RY)-127;
//			
////			printf("%5d %5d %5d %5d\n",lx,ly,rx,ry);
//			//对获取的数据进行融合
//			pwm_forward=(rx+lx)*3;
//			pwm_backward=(rx-lx)*3;
//			pwm_left=(ry-lx)*3;
//			pwm_right=(ry+lx)*3;
//			if(pwm_forward>512)
//				pwm_forward=512;
//			if(pwm_forward<-508)
//				pwm_forward=-508;
//			if(pwm_backward>512)
//				pwm_backward=512;
//			if(pwm_backward<-508)
//				pwm_backward=-508;
//			if(pwm_left>512)
//				pwm_left=512;
//			if(pwm_left<-508)
//				pwm_left=-508;
//			if(pwm_right>512)
//				pwm_right=512;
//			if(pwm_right<-508)
//				pwm_right=-508;
////			while(state_switch1());
////			while(state_switch2());

//			TIM4_fblr_action(pwm_forward,pwm_backward,pwm_left,pwm_right);
//			printf("%5d %5d %5d %5d\n",pwm_forward,pwm_backward,pwm_left,pwm_right);
//		}
//		
//		led_twinkle();
//		Delay_ms(200);
//	}
while(1)
{
	TIM4_fblr_action(500,500,500,500);
	Delay_ms(1000);
	TIM4_fblr_action(-500,-500,-500,-500);
	Delay_ms(1000);
}

	
}

