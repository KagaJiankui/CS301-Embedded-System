#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"

//ʵ�飨�ģ�����ʵ��   

 int main(void)
 {	
	u8 t;
	u8 len;	
	u16 times=0; 
 
	delay_init();	    	 //��ʱ������ʼ��	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// �����ж����ȼ�����2
	uart_init(9600);	 //���ڳ�ʼ��Ϊ9600
	LED_Init();		  	 //��ʼ����LED���ӵ�Ӳ���ӿ� 
 
	while(1)
	{
		if(USART_RX_STA&0x8000)
		{				
			LED0=1;
			len=USART_RX_STA&0x3fff;
			printf("\r\n��ã�\r\n");
			for(t=0;t<len;t++)
			{
				USART1->DR=USART_RX_BUF[t];
				while((USART1->SR&0X40)==0);
			}
			printf("\r\n\r\n");//���뻻��
			USART_RX_STA=0;
			delay_ms(100);
			LED1=!LED1;
			delay_ms(100);
			LED1=!LED1;
		}else
		{
			times++;
			LED0=0;//����led
			delay_ms(10);   
		}
	}	 
}


