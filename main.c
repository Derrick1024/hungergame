#include "main.h"


int main(void)
{
	int state[3]={1,-1,0};	//状态机，第一位是底盘的速度档位，第二位是爪子上下的档位，第三位是夹子的开合
												//第一位为底盘，第三位0为张开，1为夹紧
	//usart1初始化
	USART1_Config();
	//TIM3初始化
	TIM3_PWM_Init();
	//TIM4初始化
	TIM4_PWM_Init();
	//禁用掉调试端口 jtag & swd，下载的时候要按住复位键
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable , ENABLE);
//	GPIO_PinRemapConfig(GPIO_Remap_SWJ_NoJTRST , ENABLE);
	//PS2手柄初始化
	PS2_Init();
	//其他GPIO初始化(led & switch)
	extra_gpio_init();
	
	//判断是否为红灯模式，0为红灯模式，1为非红灯模式 
	while(1)
	{
		while(!PS2_RedLight())
		{
			int i=0,key=0;
			int lx=0,ly=0,rx=0,ry=0;
			int pwm_forward=0,pwm_backward=0,pwm_left=0,pwm_right=0,pwm_ud=0;
			
			Delay_ms(50);
			//获取key的值
			key=PS2_DataKey();
			//获取lx ly rx ry 范围-127~128
			lx = (int)PS2_AnologData(PSS_LX)-127;
			ly = (int)PS2_AnologData(PSS_LY)-127;
			rx = (int)PS2_AnologData(PSS_RX)-127;
			ry = (int)PS2_AnologData(PSS_RY)-127;
			
//			printf("%5d %5d %5d %5d %5d\n",lx,ly,rx,ry,key);
			//对获取的数据进行融合和判断
			switch(key)
			{
				case 11: state[0]=0;	break;//左前1
				case 9:  state[0]=1;	break;//左前2
				
				case 5:  state[1]=0;	break;//左上
				case 7:  state[1]=1;	break;//左下
				
				case 10: state[2]=0;	break;//右前2
				case 12: state[2]=1;	break;//右前1		
			}
			if(state[0]==0)
			{
				pwm_forward=(rx+lx)*4;
				pwm_backward=(rx-lx)*4;
				pwm_left=(ry-lx)*4;
				pwm_right=(ry+lx)*4;
				
				if(pwm_forward>512)
					pwm_forward=512;
				if(pwm_forward<-508)
					pwm_forward=-508;
				if(pwm_backward>512)
					pwm_backward=512;
				if(pwm_backward<-508)
					pwm_backward=-508;
				if(pwm_left>512)
					pwm_left=512;
				if(pwm_left<-508)
					pwm_left=-508;
				if(pwm_right>512)
					pwm_right=512;
				if(pwm_right<-508)
					pwm_right=-508;
				pwm_ud=(ly-10)*40;
			}
			if(state[0]==1)//没有改完
			{
				pwm_forward=(int)((rx+lx)*2.6);
				pwm_backward=(int)((rx-lx)*2.6);
				pwm_left=(int)((ry-lx)*2.8);
				pwm_right=(int)((ry+lx)*2.8);
				if(pwm_forward>350)
					pwm_forward=350;
				if(pwm_forward<-350)
					pwm_forward=-350;
				if(pwm_backward>350)
					pwm_backward=350;
				if(pwm_backward<-350)
					pwm_backward=-350;
				if(pwm_left>350)
					pwm_left=350;
				if(pwm_left<-350)
					pwm_left=-350;
				if(pwm_right>350)
					pwm_right=350;
				if(pwm_right<-350)
					pwm_right=-350;
				pwm_ud=(ly-22)*20;
			}					
			if(state[2]==0)
			{
				TIM3_CH2_Mode_Config(SERVO_ON_DEG);
			}
			if(state[2]==1)
			{
				TIM3_CH2_Mode_Config(SERVO_OFF_DEG);
			}
			if(state[1]==0)
			{
				TIM3_ud_action(-1500);
				Delay_ms(100);
				state[1]=-1;
			}
			if(state[1]==1)
			{
				TIM3_ud_action(800);
				Delay_ms(100);
				state[1]=-1;	
			}
//			while(state_switch1());
//			while(state_switch2());
			
			TIM4_fblr_action(pwm_forward,pwm_backward,pwm_left,pwm_right);
			TIM3_ud_action(pwm_ud);
//			printf("%5d %5d %5d %5d\n",pwm_forward,pwm_backward,pwm_left,pwm_right);
		}
		
		led_twinkle();
		Delay_ms(200);
	}


	
}

