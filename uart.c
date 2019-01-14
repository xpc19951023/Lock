#include"uart.h"
#include<reg52.h>

void Uart_Init(void)
{
    SCON=0x50;   //UART��ʽ1:8λUART;   REN=1:������� 
    PCON=0x00;   //SMOD=0:�����ʲ��ӱ� 
    TMOD=0x20;   //T1��ʽ2,����UART������ 
    TH1=0xFD; 
    TL1=0xFD;   //UART����������:FDFD��9600;FFFF,57600
    TR1=1;	 //����T1���� 
    EA=1;
}


void Uart_Send_Byte(unsigned char c)//UART Send a byte
{
	SBUF = c;
	while(!TI);		//������Ϊ1 
	TI = 0;
}

unsigned char Uart_Receive_Byte()//UART Receive a byteg
{	
	unsigned char dat;
	while(!RI);	 //������Ϊ1 
	RI = 0;
	dat = SBUF;
	return (dat);
}
