#include"key.h"


/*******************************************************************************
* �� �� ��         : KeyDown
* ��������		   : ����а������²���ȡ��ֵ
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/

void KeyDown(void)
{
	char a = 0;
	GPIO_KEY=0x0f;
	if(GPIO_KEY!=0x0f)//��ȡ�����Ƿ���
	{
		Delay10ms(1);//��ʱ10ms��������
		if(GPIO_KEY!=0x0f)//�ٴμ������Ƿ���
		{
			
			//������
			GPIO_KEY=0X0F;
			switch(GPIO_KEY)
			{
				case(0X07):	KeyValue=0;break;
				case(0X0b):	KeyValue=4;break;
				case(0X0d): KeyValue=8;break;
				case(0X0e):	KeyValue=12;break;
			}
			//������
			GPIO_KEY=0XF0;
			switch(GPIO_KEY)
			{
				case(0X70):	KeyValue=KeyValue+3;break;
				case(0Xb0):	KeyValue=KeyValue+2;break;
				case(0Xd0): KeyValue=KeyValue+1;break;
				case(0Xe0):	KeyValue=KeyValue;break;
			}
			while((a<50) && (GPIO_KEY!=0xf0))	 //��ⰴ�����ּ��
			{
				Delay10ms(1);
				a++;
			}
		}
	}
}

/*******************************************************************************
* �� �� ��         : Delay10ms
* ��������		   : ��ʱ��������ʱ10ms
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/

void Delay10ms(unsigned int c)   //��� 0us
{
    unsigned char a, b;

	//--c�Ѿ��ڴ��ݹ�����ʱ���Ѿ���ֵ�ˣ�������for����һ��Ͳ��ø�ֵ��--//
    for (;c>0;c--)
	{
		for (b=38;b>0;b--)
		{
			for (a=130;a>0;a--);
		}          
	}       
}