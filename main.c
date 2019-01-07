#include <reg52.h>
#include "12864.h"
#include "key.h"

uchar code table1[]="1.密码开锁";
uchar code table2[]="2.指纹开锁";
uchar code table3[]="3.蓝牙开锁";
uchar code table4[]="4.设置";
uchar code table5[]="5.确定";
uchar code table6[]="10.delete";
uchar code table7[]="11确认";
uchar code table8[]="12退出";

uchar code table11[]="请输入用户密码";
uchar code table21[]="请输入用户指纹";
uchar code table31[]="请连接蓝牙设备";
uchar code table41[]="    设置界面  ";
uchar code table00[]="                  ";

uchar  index=0;
uchar mima[6]={0};		  //密码
uchar mima_edit[6]={0};	  //用户输入的密码

uchar flag_function=0;
uchar flag_mimakaisuo=0;
uchar flag_zhiwenkaisuo=0;
uchar flag_lanyakaisuo=0;
uchar flag_shezhijiemian=0;
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
//
	
	while(1)
	{
		 KeyDown();

		 //一级菜单
		 if(flag_mimakaisuo==0&&flag_zhiwenkaisuo==0&&flag_lanyakaisuo==0&&flag_shezhijiemian==0)
		 {
		 if(KeyValue==0)
		 {
		 	flag_function=1;
			lcd12864_show_char(0,0,'*');
			lcd12864_show_char(1,0,' ');
		   	lcd12864_show_char(2,0,' ');
			lcd12864_show_char(3,0,' ');
			lcd12864_show_char(3,4,' ');
						
		 }	

		  if(KeyValue==1)
		 {
		 	flag_function=2;
			lcd12864_show_char(0,0,' ');
			lcd12864_show_char(1,0,'*') ;
		   	lcd12864_show_char(2,0,' ');
			lcd12864_show_char(3,0,' ');
			lcd12864_show_char(3,4,' ');
						
		
		 }	

		  if(KeyValue==2)
		 {
			flag_function=3;
			lcd12864_show_char(0,0,' ');
			lcd12864_show_char(1,0,' ') ;
		   	lcd12864_show_char(2,0,'*');
			lcd12864_show_char(3,0,' ');
			lcd12864_show_char(3,4,' ');
	
		 }	

		  if(KeyValue==3)
		 {
		   	flag_function=4;
			lcd12864_show_char(0,0,' ');
			lcd12864_show_char(1,0,' ');
		   	lcd12864_show_char(2,0,' ');
			lcd12864_show_char(3,0,'*');
			lcd12864_show_char(3,4,' ');

		 }
		 	

		  if( KeyValue==4 && flag_function==1 )
		 {
		   
			flag_mimakaisuo=1;
	     lcd12864_show_string(0,0,table11);
	     lcd12864_show_string(1,0,table00);
	     lcd12864_show_string(2,1,table6);
         lcd12864_show_string(3,1,table7);
		 lcd12864_show_string(3,5,table8);
     
		}	

		  if( KeyValue==4 && flag_function==2 )
		 {
		   
		    //lcd12864_init();
			flag_zhiwenkaisuo=1;
   	     //   lcd12864_show_string(0,0,table21);
	      //  lcd12864_show_string(1,0,table00);
	      //  lcd12864_show_string(2,0,table00);
          //  lcd12864_show_string(3,0,table00);
     
		}	

		  if( KeyValue==4 && flag_function==3 )
		 {
		   
		    //lcd12864_init();
			flag_lanyakaisuo=1;
   	        lcd12864_show_string(0,0,table31);
	        lcd12864_show_string(1,0,table00);
	        lcd12864_show_string(2,0,table00);
            lcd12864_show_string(3,0,table00);
     
		}	

		  if( KeyValue==4 && flag_function==4 )
		 {
		   
		    //lcd12864_init();
			flag_shezhijiemian=1;
   	        lcd12864_show_string(0,0,table41);
	        lcd12864_show_string(1,0,table00);
	        lcd12864_show_string(2,0,table00);
            lcd12864_show_string(3,0,table00);
     
		}
		   KeyValue=17;
	}

	  //二级菜单 ————密码开锁界面
	   if(flag_mimakaisuo==1)
	   {
	      if(KeyValue!=17)
		  {		 
				  if(KeyValue<10)
				  {
				      if(index<6)
					  {
					   	   mima_edit[index++]=KeyValue;
					  lcd12864_show_char(1,index,KeyValue+'0');
					  KeyValue=17;
					  }else
					  {
					  //已经输入六个数了，无需再输入
					  }
					
				  }else
				  {
				    if(KeyValue==10)
					{
					   //删除一位
					}else if(KeyValue==11)
					{
					 //确认
					}
					else if(KeyValue==12)
					{
					  //退出
					}else
					{
					  //此种按键码无效
					}
				  }

			 
		  }
		 

	   }

	   	//二级菜单 ————指纹开锁界面
	   if(flag_zhiwenkaisuo==1)
	   {
	   
	   }

	   	//二级菜单 ————蓝牙开锁界面
	   if(flag_lanyakaisuo==1)
	   {
	   
	   }

	   	//二级菜单 ————蓝牙开锁界面
	   if(flag_shezhijiemian==1)
	   {
	   
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
	mima[0]=1;
	mima[1]=2;
	mima[2]=3;
	mima[3]=4;
	mima[4]=5;
	mima[5]=6;
}