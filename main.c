#include <reg52.h>

void main()
{
   init();//��ʼ������ȡ����
   display_init_lcd();//��ʾ��ʼ����
   /*
     1 �������
	 2 ��������
	 3 ָ�ƽ���
	 4 ����
   */
   key_num=get_keynum();
	while(1)
	{
		if(key_num==1)
		{  
			mimajiesuo();//�������
		}
		if(key_num==2)
		{
			lanyajiesuo();//	��������
		}
		if(key_num==3)
		{  
			zhiwenjiesuo();//ָ�ƽ���
		}
		if(key_num==4)
		{   
			shezhi();	  //  ����
		}
	   
	}
}