#include <reg52.h>
#include "12864.h"
#include "key.h"

uchar code table1[]="1.���뿪��";
uchar code table2[]="2.ָ�ƿ���";
uchar code table3[]="3.��������";
uchar code table4[]="4.����";
uchar code table5[]="5.ȷ��";

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
//	lcd12864_show_string(0,1,table1);
//	lcd12864_show_string(1,1,table2);
//	lcd12864_show_string(2,1,table3);
//	lcd12864_show_string(3,1,table4);
//	lcd12864_show_string(3,5,table5);

	
	while(1)
	{
		 KeyDown();
		 
		 if(KeyValue==0)
		 {
		 
			lcd12864_show_char(0,0,'*');
			lcd12864_show_char(1,0,' ');
		   	lcd12864_show_char(2,0,' ');
			lcd12864_show_char(3,0,' ');
			lcd12864_show_char(3,4,' ');
						
		 }	

		  if(KeyValue==1)
		 {
		 	
			lcd12864_show_char(0,0,' ');
			lcd12864_show_char(1,0,'*') ;
		   	lcd12864_show_char(2,0,' ');
			lcd12864_show_char(3,0,' ');
			lcd12864_show_char(3,4,' ');
						
		
		 }	

		  if(KeyValue==2)
		 {
			lcd12864_show_char(0,0,' ');
			lcd12864_show_char(1,0,' ') ;
		   	lcd12864_show_char(2,0,'*');
			lcd12864_show_char(3,0,' ');
			lcd12864_show_char(3,4,' ');
	
		 }	

		  if(KeyValue==3)
		 {
		   
			lcd12864_show_char(0,0,' ');
			lcd12864_show_char(1,0,' ') ;
		   	lcd12864_show_char(2,0,' ');
			lcd12864_show_char(3,0,'*');
			lcd12864_show_char(3,4,' ');


		 }	

		  if(KeyValue==4)
		 {
		   
			lcd12864_show_char(0,0,' ');
			lcd12864_show_char(1,0,' ') ;
		   	lcd12864_show_char(2,0,' ');
			lcd12864_show_char(3,0,' ');
			lcd12864_show_char(3,4,'*');

		

		 }	
	//	 if()


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
   	lcd12864_show_string(0,1,table1);
	lcd12864_show_string(1,1,table2);
	lcd12864_show_string(2,1,table3);
	lcd12864_show_string(3,1,table4);
	lcd12864_show_string(3,5,table5);
}