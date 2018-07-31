#include "led.h"
#include "delay.h"
#include "sys.h"
#include "key.h"
//��Ƕ��ʽ��΢��ԭ��ʵ�飨����
//��������LED��_IO�������		   

 int main(void)
 {	
	u8 t=0;	  
	delay_init();	      //��ʱ������ʼ��	  
	LED_Init();		  	 	//��ʼ����LED���ӵ�Ӳ���ӿ�
	KEY_Init();        	//��ʼ���밴�����ӵ�Ӳ���ӿ�
	LED0=1;
    LED1=1;				 
	while(1)
	{
		t=KEY_Scan(0);		//�õ���ֵ
		switch(t)
		{				 
			case KEY0_PRES:
				LED0=0;
				break;
			case KEY1_PRES:
				LED1=0;
				break;
			case WKUP_PRES:				
				LED0=1;
				LED1=1;
				break;
			default:
				delay_ms(10);	
		} 
	}		 
}
