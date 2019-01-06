#include <reg52.h>
#include "12864.h"
#include "key.h"

uchar code table1[]="1.密码开锁";
uchar code table2[]="2.指纹开锁";
uchar code table3[]="3.蓝牙开锁";
uchar code table4[]="4.设置";
uchar code table5[]="5.确定";

void init();

void main()
{
   init();//初始化，读取密码
//   display_init_lcd();//显示初始界面
//   /*
//     1 密码解锁
//	 2 蓝牙解锁
//	 3 指纹解锁
//	 4 设置
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
//			mimajiesuo();//密码解锁,可取消
//		}
//		if(key_num==2)
//		{
//			lanyajiesuo();//蓝牙解锁，可取消
//		}
//		if(key_num==3)
//		{  
//			zhiwenjiesuo();//指纹解锁，可取消
//		}
//		if(key_num==4)
//		{   
//			shezhi();	   // 设置，可取消
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