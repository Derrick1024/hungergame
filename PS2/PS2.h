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
#define PSS_RX 5                //右摇杆X轴数据
#define PSS_RY 6
#define PSS_LX 7
#define PSS_LY 8


#define DI   GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)           //PB12  输入

#define DO_H GPIO_SetBits(GPIOB, GPIO_Pin_13)        //命令位高
#define DO_L GPIO_ResetBits(GPIOB, GPIO_Pin_13)        //命令位低

#define CS_H GPIO_SetBits(GPIOB, GPIO_Pin_14)       //CS拉高
#define CS_L GPIO_ResetBits(GPIOB, GPIO_Pin_14)       //CS拉低

#define CLC_H GPIO_SetBits(GPIOB, GPIO_Pin_15)      //时钟拉高
#define CLC_L GPIO_ResetBits(GPIOB, GPIO_Pin_15)      //时钟拉低


void PS2_Init(void);
u8 PS2_RedLight(void);//判断是否为红灯模式
void PS2_ReadData(void);
void PS2_Cmd(u8 CMD);		  //
u8 PS2_DataKey(void);		  //键值读取
u8 PS2_AnologData(u8 button); //得到一个摇杆的模拟量
void PS2_ClearData(void);	  //清除数据缓冲区
















