#include <reg52.h>
#include "12864.h"
uchar code table1[]="������ѧԺ";
uchar code table2[]="������Ϣ����ѧԺ";
void init();
void main()
{
   init();//��ʼ������ȡ����
//   display_init_lcd();//��ʾ��ʼ����
//   /*
//     1 �������
//	 2 ��������
//	 3 ָ�ƽ���
//	 4 ����
//   */
//   key_num=get_keynum();
	lcd12864_show_string(0,0,table1);
	lcd12864_show_string(0,1,table2);
	while(1)
	{
//		if(key_num==1)
//		{  
//			mimajiesuo();//�������,��ȡ��
//		}
//		if(key_num==2)
//		{
//			lanyajiesuo();//������������ȡ��
//		}
//		if(key_num==3)
//		{  
//			zhiwenjiesuo();//ָ�ƽ�������ȡ��
//		}
//		if(key_num==4)
//		{   
//			shezhi();	   // ���ã���ȡ��
//		}
	}
}

void init()
{
   lcd12864_init();
}