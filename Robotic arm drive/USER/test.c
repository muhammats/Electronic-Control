#include "sys.h"
#include "usart.h"		
#include "delay.h"	
#include "timer.h" 
//ALIENTEK Mini STM32�����巶������8
//PWM���ʵ��   
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾

int main(void)
{			
// 	u16 pwmval=0;    
	int ang=0; u8 len,serial_num=1;
	
	Stm32_Clock_Init(9); //ϵͳʱ������
	delay_init(72);	     //��ʱ��ʼ��
	uart_init(72,9600);  //���ڳ�ʼ�� 
	TIM2_3_PWM_Init(2000-1,720-1);//PWMƵ��100k ����20ms
	delay_ms(1000);
	Rds_Control(0,5);

	while(1)
	{
		if(USART_RX_STA&0X8000)
		{	
			len = USART_RX_STA&0X3FFF;			//�õ��˴ν������ݵĳ���
			ang = USART_RX_BUF[1] + USART_RX_BUF[2]*16;
			serial_num = USART_RX_BUF[0];
			Rds_Control(ang,5);
			printf("len %d num %d ang %d",len,serial_num,ang);
			printf("\r\n\r\n");						//���뻻��
			USART_RX_STA = 0;
		}
		else delay_ms(10);
	}

}


