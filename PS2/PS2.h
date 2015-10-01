#include "stm32f10x.h"
#include "systick_delay.h"

//These are our button constants
#define PSB_SELECT      1
#define PSB_L3          2
#define PSB_R3          3
#define PSB_START       4
#define PSB_PAD_UP      5
#define PSB_PAD_RIGHT   6
#define PSB_PAD_DOWN    7
#define PSB_PAD_LEFT    8
#define PSB_L2         9
#define PSB_R2          10
#define PSB_L1          11
#define PSB_R1          12
#define PSB_GREEN       13
#define PSB_RED         14
#define PSB_BLUE        15
#define PSB_PINK        16
#define PSB_TRIANGLE    13
#define PSB_CIRCLE      14
#define PSB_CROSS       15
#define PSB_SQUARE      26

//These are stick values
#define PSS_RX 5                //��ҡ��X������
#define PSS_RY 6
#define PSS_LX 7
#define PSS_LY 8


#define DI   GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)           //PB12  ����

#define DO_H GPIO_SetBits(GPIOB, GPIO_Pin_13)        //����λ��
#define DO_L GPIO_ResetBits(GPIOB, GPIO_Pin_13)        //����λ��

#define CS_H GPIO_SetBits(GPIOB, GPIO_Pin_14)       //CS����
#define CS_L GPIO_ResetBits(GPIOB, GPIO_Pin_14)       //CS����

#define CLC_H GPIO_SetBits(GPIOB, GPIO_Pin_15)      //ʱ������
#define CLC_L GPIO_ResetBits(GPIOB, GPIO_Pin_15)      //ʱ������


void PS2_Init(void);
u8 PS2_RedLight(void);//�ж��Ƿ�Ϊ���ģʽ
void PS2_ReadData(void);
void PS2_Cmd(u8 CMD);		  //
u8 PS2_DataKey(void);		  //��ֵ��ȡ
u8 PS2_AnologData(u8 button); //�õ�һ��ҡ�˵�ģ����
void PS2_ClearData(void);	  //������ݻ�����
















