#include "sys.h"
#include "usart.h"		
#include "delay.h"	
#include "timer.h" 
//ALIENTEK Mini STM32开发板范例代码8
//PWM输出实验   
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司

int main(void)
{			
// 	u16 pwmval=0;    
	int ang=0; u8 len,serial_num=1;
	
	Stm32_Clock_Init(9); //系统时钟设置
	delay_init(72);	     //延时初始化
	uart_init(72,9600);  //串口初始化 
	TIM2_3_PWM_Init(2000-1,720-1);//PWM频率100k 周期20ms
	delay_ms(1000);
	Rds_Control(0,5);

	while(1)
	{
		if(USART_RX_STA&0X8000)
		{	
			len = USART_RX_STA&0X3FFF;			//得到此次接收数据的长度
			ang = USART_RX_BUF[1] + USART_RX_BUF[2]*16;
			serial_num = USART_RX_BUF[0];
			Rds_Control(ang,5);
			printf("len %d num %d ang %d",len,serial_num,ang);
			printf("\r\n\r\n");						//插入换行
			USART_RX_STA = 0;
		}
		else delay_ms(10);
	}

}


