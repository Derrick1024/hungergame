#include "main.h"


int main(void)
{
	int state[3]={1,-1,0};	//״̬������һλ�ǵ��̵��ٶȵ�λ���ڶ�λ��צ�����µĵ�λ������λ�Ǽ��ӵĿ���
												//��һλΪ���̣�����λ0Ϊ�ſ���1Ϊ�н�
	//usart1��ʼ��
	USART1_Config();
	//TIM3��ʼ��
	TIM3_PWM_Init();
	//TIM4��ʼ��
	TIM4_PWM_Init();
	//���õ����Զ˿� jtag & swd�����ص�ʱ��Ҫ��ס��λ��
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable , ENABLE);
//	GPIO_PinRemapConfig(GPIO_Remap_SWJ_NoJTRST , ENABLE);
	//PS2�ֱ���ʼ��
	PS2_Init();
	//����GPIO��ʼ��(led & switch)
	extra_gpio_init();
	
	//�ж��Ƿ�Ϊ���ģʽ��0Ϊ���ģʽ��1Ϊ�Ǻ��ģʽ 
	while(1)
	{
		while(!PS2_RedLight())
		{
			int i=0,key=0;
			int lx=0,ly=0,rx=0,ry=0;
			int pwm_forward=0,pwm_backward=0,pwm_left=0,pwm_right=0,pwm_ud=0;
			
			Delay_ms(50);
			//��ȡkey��ֵ
			key=PS2_DataKey();
			//��ȡlx ly rx ry ��Χ-127~128
			lx = (int)PS2_AnologData(PSS_LX)-127;
			ly = (int)PS2_AnologData(PSS_LY)-127;
			rx = (int)PS2_AnologData(PSS_RX)-127;
			ry = (int)PS2_AnologData(PSS_RY)-127;
			
//			printf("%5d %5d %5d %5d %5d\n",lx,ly,rx,ry,key);
			//�Ի�ȡ�����ݽ����ںϺ��ж�
			switch(key)
			{
				case 11: state[0]=0;	break;//��ǰ1
				case 9:  state[0]=1;	break;//��ǰ2
				
				case 5:  state[1]=0;	break;//����
				case 7:  state[1]=1;	break;//����
				
				case 10: state[2]=0;	break;//��ǰ2
				case 12: state[2]=1;	break;//��ǰ1		
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
			if(state[0]==1)//û�и���
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

