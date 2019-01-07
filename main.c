#include <reg52.h>
#include "12864.h"
#include "key.h"
#include "intrins.h"
typedef unsigned char BYTE;
typedef unsigned int WORD;


uchar code table1[]="1.密码开锁";
uchar code table2[]="2.指纹开锁";
uchar code table3[]="3.蓝牙开锁";
uchar code table4[]="4.设置";
uchar code table5[]="5.确定";
uchar code table6[]="10.delete";
uchar code table7[]="11确认";
uchar code table8[]="12退出";
uchar code table9[]="    开锁成功    ";


uchar code table11[]="  请输入密码    ";
uchar code table21[]="  请输入指纹    ";
uchar code table31[]="  蓝牙开锁中    ";
uchar code table32[]="  蓝牙开锁成功  ";
uchar code table33[]="  蓝牙开锁失败  ";
uchar code table41[]="    设置界面  ";
uchar code table00[]="                  ";



uchar  index=0;
uchar mima[6]={0};		  //密码
uchar mima_edit[6]={0xff,0xff,0xff,0xff,0xff,0xff};	  //用户输入的密码

uchar buff_lanya[20];
uchar num_laya_i=0;
uchar num_laya_bao=0;
uchar flag_lanyakaisuo_bao=0;//数据包已经足够，可以判断开锁
uchar flag_success_laya=0;


void UsartConfiguration();
void sendchar(uchar ch);
void sendstring(uchar *s);

uchar flag_function=0;
uchar flag_mimakaisuo=0;
uchar flag_zhiwenkaisuo=0;
uchar flag_lanyakaisuo=0;
uchar flag_shezhijiemian=0;
uchar checkmima(uchar mima[],uchar mima_edit[]);
uchar checklanay(uchar buff_lanya[20]);
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
	UsartConfiguration();
	while(1)
	{	  	uchar i;
		 KeyDown();
		
		 //一级菜单
		 if(flag_mimakaisuo==0&&flag_zhiwenkaisuo==0&&flag_lanyakaisuo==0&&flag_shezhijiemian==0)
		 {
		 if(KeyValue==0 )
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
			lcd12864_show_string(3,5,table8);
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
						   lcd12864_show_char(1,index-1,KeyValue+'0');
						   KeyValue=17;
					  }
					
				  }else
				  {
				    if(KeyValue==10)
					{	 	KeyValue=17;
					   //删除一位
					   if(index>0 && index<=6)
					   {
						mima_edit[index-1]=0Xff;
					    lcd12864_show_char(1,index-1,' ');
					    index-=1;
					
					   }
					   
					   else if(index>6)
					   {   
					   	index=6;
					    lcd12864_show_char(1,index-1,' ');
					    mima_edit[index-1]=0Xff;
					    index-=1;
					   
					   }else
					   {
					   //index为0，不操作
					   }
					   
					}
					
					else if(KeyValue==11)
					{
					 //确认
					  KeyValue=17;
					   if(checkmima(mima,mima_edit))
					   {
						  //密码正确开锁,提示
	                    lcd12864_show_string(0,0,table9);	             
	                    lcd12864_show_string(1,0,table00);
	                    lcd12864_show_string(2,0,table00);
                        lcd12864_show_string(3,0,table00);
					
						 
					   } else
					   {
						 //密码错误，提示,并清空密码
						 uchar i;
						 for(i=0;i<6;i++)
						 lcd12864_show_char(1,i,' ');
						 index=0;
						 
					   }
					   //清除输入的密码
					   	mima_edit[0]=0xff;
						mima_edit[1]=0xff;
						mima_edit[2]=0xff;
						mima_edit[3]=0xff;
						mima_edit[4]=0xff;
						mima_edit[5]=0xff;
					}

					else if(KeyValue==12)
					{
					  //退出
					   KeyValue=17;
					   flag_mimakaisuo=0;
					   lcd12864_show_string(0,1,table1);
	                   lcd12864_show_string(1,1,table2);
	                   lcd12864_show_string(2,1,table3);
                       lcd12864_show_string(3,1,table4);
                       lcd12864_show_string(3,5,table5);

					   //清除输入的密码
					    mima_edit[0]=0xff;
						mima_edit[1]=0xff;
						mima_edit[2]=0xff;
						mima_edit[3]=0xff;
						mima_edit[4]=0xff;
						mima_edit[5]=0xff;
					
					}else
					{
					  //此种按键码无效
					   KeyValue=17;
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
	   		if(flag_lanyakaisuo_bao)
			{
			 	 if(checklanay(buff_lanya)&&flag_success_laya==0)
				 {
				 //开锁成功
                       lcd12864_show_string(0,1,table32);
	                   lcd12864_show_string(1,1,table00);
	                   lcd12864_show_string(2,1,table00);
                       lcd12864_show_string(3,1,table00);
                   	    sendstring("#C!");//成功回复
						sendstring("#C!");
						sendstring("#C!");
						sendstring("#C!");
						sendstring("#C!");
						flag_success_laya=1;

				 }
				
				 for(i=0;i<20;i++)
				 {
				  buff_lanya[i]=0;
				  }
				
				 num_laya_i=0;
				 num_laya_bao=0;
				 flag_lanyakaisuo_bao=0;//数据包已经足够，可以判断开锁
				 
			}
	     	if(KeyValue==12)
			{			   flag_success_laya=0;
				       flag_lanyakaisuo=0;
				       KeyValue=17;
					   flag_lanyakaisuo=0;
					   lcd12864_show_string(0,1,table1);
	                   lcd12864_show_string(1,1,table2);
	                   lcd12864_show_string(2,1,table3);
                       lcd12864_show_string(3,1,table4);
                       lcd12864_show_string(3,5,table5);

			}

	   }

	   	//二级菜单 ————设置界面
	   if(flag_shezhijiemian==1)
	   {
	   
	   }
}

   }

 uchar checkmima(uchar mima[],uchar mima_edit[])
 {
  	    uchar i=0,j=0;
	  	for(i=0;i<6;i++)
		{
		   if(mima[i]==mima_edit[i])
		   {
				 j++;
		   }
		}
		
	  	if(j==6)
		   return 1;
		else
			return 0;
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



void UsartConfiguration()
{

	SCON=0X50;			//设置为工作方式1
	TMOD=0X20;			//设置计数器工作方式2
	PCON=0X00;			//波特率加倍
	TH1=0XFd;		    //计数器初始值设置，注意波特率是9600的
	TL1=0XFd;
	ES=1;						//打开接收中断
	EA=1;						//打开总中断
	TR1=1;					    //打开计数器
}

void Usart() interrupt 4
{
	uchar receiveData;
	receiveData=SBUF; //接收到的数据
		//蓝牙开锁界面
	
	   if(flag_lanyakaisuo_bao==0 && flag_lanyakaisuo==1)
	   {
	   	   buff_lanya[num_laya_i++]= receiveData;
		   if(receiveData=='#')
		      	num_laya_bao++; 
			if(num_laya_bao>2)
			   flag_lanyakaisuo_bao=1;  
	   }
	   	//	指纹开锁界面
	   if(flag_zhiwenkaisuo==1)
	   {
	   
	   }
//	RI = 0;           //清除接收中断标志位
//	SBUF=receiveData; //将接收到的数据放入到发送寄存器
//	while(!TI);		  //等待发送数据完成
//	TI=0;			  //清除发送完成标志位
}


void sendchar(uchar ch)
{
	SBUF=ch; //将接收到的数据放入到发送寄存器
	while(!TI);		  //等待发送数据完成
	TI=0;	
}


void sendstring(uchar *s)
{
   while (*s)              
    {
        sendchar(*s++);     
    }
}


uchar checklanay(uchar buff_lanya[])
{
	uchar i=0;
	   for(i=0;i<20-3;i++)
	   {
		   if(buff_lanya[i]=='#')
		   {
		       if(buff_lanya[i+1]=='K'&&buff_lanya[i+2]=='!')
			   {
				  return 1;
			   }
		   }
	   }
	   return 0;
}
