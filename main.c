#include <reg52.h>
#include "12864.h"
#include "key.h"
#include "intrins.h"
#include "i2c.h"
typedef unsigned char BYTE;
typedef unsigned int WORD;


uchar code table1[]="0.密码开锁";
uchar code table2[]="1.指纹开锁";
uchar code table3[]="2.蓝牙开锁";
uchar code table4[]="3.设置";
uchar code table5[]="4.确定";
uchar code table6[]="10.delete   ";
uchar code table7[]="11确认";
uchar code table8[]="12退出";
uchar code table9[]="    开锁成功    ";


uchar code table11[]="  请输入密码    ";
uchar code table21[]="  请输入指纹    ";
uchar code table31[]="  蓝牙开锁中    ";
uchar code table32[]="  蓝牙开锁成功  ";
uchar code table33[]="  蓝牙开锁失败  ";
uchar code table41[]="    设置界面    ";
uchar code table42[]="    0.设置密码   ";
uchar code table43[]="    1.设置指纹   ";

//uchar code table45[]="  2.设置指纹  ";
uchar code table00[]="                  ";


uchar zhiwen_in[12]={0xef,0x01,0xff,0xff,0xff,0xff,0x01,0x00,0x03,0x01,0x00,0x05};
uchar zhiwen_product[13]={0xEf,0x01,0xff,0xff,0xff,0xff,0x01,0x00,0x04,0x02,0x01,0x00,0x08};
uchar zhiwen_product2[13]={0xEf,0x01,0xff,0xff,0xff,0xff,0x01,0x00,0x04,0x02,0x02,0x00,0x09};
uchar zhiwen_match[12]={0xef,0x01,0xff,0xff,0xff,0xff,0x01,0x00,0x03,0x03,0x00,0x07};
uchar zhiwen_get[12]={0xef,0x01,0xff,0xff,0xff,0xff,0x01,0x00,0x03,0x05,0x00,0x09};
uchar zhiwen_str[15]={0xef,0x01,0xff,0xff,0xff,0xff,0x01,0x00,0x06,0x06,0x01,0x00,0x00,0x00,0x0d};



uchar  index=0;
uchar mima[6]={0};		  //密码
uchar mima_edit[6]={0xff,0xff,0xff,0xff,0xff,0xff};	  //用户输入的密码
uchar mima_set[6]={0};
uchar buff_lanya[20];
uchar num_laya_i=0;
uchar num_laya_bao=0;
uchar flag_lanyakaisuo_bao=0;//数据包已经足够，可以判断开锁
uchar flag_zhiwenkaisuo_bao=0;
uchar flag_success_laya=0;
uchar shezhi_mima=0;
uchar num_test=0;

void delay10ms();
void UsartConfiguration();
void sendchar(uchar ch);
void sendstring(uchar *s);

uchar buff_zhiwen[20]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
uchar num_zhiwen_i=0;

uchar flag_function=0;
uchar flag_mimakaisuo=0;
uchar flag_zhiwenkaisuo=0;
uchar flag_lanyakaisuo=0;
uchar flag_shezhijiemian=0;
uchar checkmima(uchar mima[],uchar mima_edit[]);
uchar checklanay(uchar buff_lanya[20]);
void init();
void sendstring_zhiwen(uchar *s ,uchar length);
void Delay100ms();	


void main()
{
     init();//初始化，读取密码

	delay10ms();
	UsartConfiguration();
	//EEPROM测试

	delay10ms();
	mima[0]=At24c02Read(0x00);
	delay10ms();
	mima[1]=At24c02Read(0x01);
	delay10ms();
	mima[2]=At24c02Read(0x02);
	delay10ms();
	mima[3]=At24c02Read(0x03);
	delay10ms();
	mima[4]=At24c02Read(0x04);
	delay10ms();
	mima[5]=At24c02Read(0x05);

//	lcd12864_show_char(0,0,mima[0]+'0');
//	lcd12864_show_char(0,1,mima[1]+'0');
//	lcd12864_show_char(0,2,mima[2]+'0');
//	lcd12864_show_char(0,3,mima[3]+'0');
//	lcd12864_show_char(0,4,mima[4]+'0');
//	lcd12864_show_char(0,5,mima[5]+'0');
//	while(1);
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
	        lcd12864_show_string(1,0,table42);
	        lcd12864_show_string(2,0,table43);
			lcd12864_show_string(3,0,table00);
            lcd12864_show_string(3,5,table8);
     
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
					  }else
					  {

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
						index=0;
						 
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
						index=0;
					
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
	   
	     	if(KeyValue==0 && shezhi_mima==0)
		    {  
		//密码设置	   请输入密码：	    10 删除	   11 确认     12 取消
			KeyValue=17;  
			shezhi_mima=1;
		   //flag_shezhijiemian=0;
		    lcd12864_show_string(0,1,table11);
			lcd12864_show_string(1,1,table00);
	        lcd12864_show_string(2,1,table6);
	        lcd12864_show_string(3,1,table7);
            lcd12864_show_string(3,5,table8);
			}
			if(shezhi_mima==1)
			{	  if(KeyValue<10)
				  {
					//KeyValue=17;
					if(index<6)
					   {
						mima_set[index++]=KeyValue;
					    lcd12864_show_char(1,index-1,KeyValue+'0');
						KeyValue=17;
					   }
					   else 
					   {  

					   }
				  }
				  else if(KeyValue==10)
				  {
					    KeyValue=17;
					    if(index>0 && index<=6)
					   {
						mima_set[index-1]=0Xff;
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

				  }	else if(KeyValue==11)
				  {
					    KeyValue=17;
					    At24c02Write(0x00,mima_set[0]);
						delay10ms();
						At24c02Write(0x01,mima_set[1]);
						delay10ms();
						At24c02Write(0x02,mima_set[2]);
						delay10ms();
						At24c02Write(0x03,mima_set[3]);
						delay10ms();
						At24c02Write(0x04,mima_set[4]);
						delay10ms();
						At24c02Write(0x05,mima_set[5]);
						delay10ms();
						mima[0]=mima_set[0];
						mima[1]=mima_set[1];
						mima[2]=mima_set[2];
						mima[3]=mima_set[3];
						mima[4]=mima_set[4];
						mima[5]=mima_set[5];


				  }	else if(KeyValue==12)
				  {
					   KeyValue=17;
					   index=0;
					  // shezhi_mima=0;
					   flag_shezhijiemian=0;
					   lcd12864_show_string(1,0,table00);
					   lcd12864_show_string(0,1,table1);
	                   lcd12864_show_string(1,1,table2);
	                   lcd12864_show_string(2,1,table3);
                       lcd12864_show_string(3,1,table4);
                       lcd12864_show_string(3,5,table5);

				  }else
				  {
					 // KeyValue=17;
				  }
				  
			}
			if(KeyValue==1)
			{
			     //指纹设置
			   KeyValue=17;
			   lcd12864_show_string(0,0,"请录入指纹  ");
	           lcd12864_show_string(1,1,table00);
	           lcd12864_show_string(2,1,table00);
               lcd12864_show_string(3,1,table00);
               //lcd12864_show_string(3,5,table5);
        	   
	           sendstring_zhiwen(zhiwen_in,12);
               //UART_SendDat();
	           Delay100ms();
	           Delay100ms();
	           Delay100ms();
	           if(buff_zhiwen[9]==0x00)
	           {
	             num_test=0;
		         lcd12864_show_string(1,0,"11");
		         while(1);
//		  sendstring_zhiwen(zhiwen_product,13);
//		  Delay100ms();
//	      Delay100ms();
//		   if(buff_zhiwen[9]==0x00)
//		  {
//		     lcd12864_show_string(0,0,"22");
//			 sendstring_zhiwen(zhiwen_in,12);
//			  Delay100ms();
//	          Delay100ms();
//			   if(buff_zhiwen[9]==0x00)
//			  {
//			  	  sendstring_zhiwen(zhiwen_product2,13);
//				  Delay100ms();
//	              Delay100ms();
//				   if(buff_zhiwen[9]==0x00)
//				  {
//				     sendstring_zhiwen(zhiwen_match,12);
//				     Delay100ms();
//	                 Delay100ms();
//					  if(buff_zhiwen[9]==0x00)
//					 {
//					 	sendstring_zhiwen(zhiwen_get,12);
//						 Delay100ms();
//	                     Delay100ms();
//						  if(buff_zhiwen[9]==0x00)
//						 {
//						   	 sendstring_zhiwen(zhiwen_str,15);
//						     Delay100ms();
//	                         Delay100ms();
//							  if(buff_zhiwen[9]==0x00)
//							  {
//							    lcd12864_show_string(0,0,"指纹生成完成");
//							  }
//						 }
//
//					 }
//				  }
//			  }
		  }	
		  else{
	        sendstring_zhiwen(zhiwen_in,12);
		    num_test=0;
		    Delay100ms();
		    Delay100ms();
			Delay100ms();
	   }		       
					  
			}
	   		if(KeyValue==12)
			{
					//退出
					   KeyValue=17;
					   flag_shezhijiemian=0;
					   
					   lcd12864_show_string(0,1,table1);
	                   lcd12864_show_string(1,1,table2);
	                   lcd12864_show_string(2,1,table3);
                       lcd12864_show_string(3,1,table4);
                       lcd12864_show_string(3,5,table5);
			}
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

//	SCON=0X50;			//设置为工作方式1
//	TMOD=0X20;			//设置计数器工作方式2
//	PCON=0X00;			//波特率加倍
//	TH1=0XFd;		    //计数器初始值设置，注意波特率是9600的
//	TL1=0XFd;
//	ES=1;						//打开接收中断
//	EA=1;						//打开总中断
//	TR1=1;					    //打开计数器

	PCON &= 0x7F;		//波特率不倍速
	SCON = 0x50;		//8位数据,可变波特率
	TMOD &= 0x0F;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xFD;		//设定定时初值
	TH1 = 0xFD;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
	ES=1;
	EA=1;
}

//void Usart() interrupt 4
//{
//	uchar receiveData;
//	receiveData=SBUF; //接收到的数据
//		//蓝牙开锁界面
//	
//	   if(flag_lanyakaisuo_bao==0 && flag_lanyakaisuo==1)
//	   {
//	   	   buff_lanya[num_laya_i++]= receiveData;
//		   if(receiveData=='#')
//		      	num_laya_bao++; 
//			if(num_laya_bao>2)
//			   flag_lanyakaisuo_bao=1;  
//	   }
//	   	//	指纹开锁界面
//	   if(flag_zhiwenkaisuo==1)
//	   {
//	   
//	   }
//	RI = 0;           //清除接收中断标志位
////	SBUF=receiveData; //将接收到的数据放入到发送寄存器
////	while(!TI);		  //等待发送数据完成
////	TI=0;			  //清除发送完成标志位
//}

void Usart() interrupt 4
{
   	uchar receiveData,receiveData_zhiwen;
	receiveData=SBUF;
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
	  if(RI)
	   {
		  	receiveData_zhiwen=SBUF;
			buff_zhiwen[num_test++]= receiveData_zhiwen;
		    RI = 0;
			flag_zhiwenkaisuo_bao=1;

	   }
     
	RI = 0; 
//	EA=1;          //清除接收中断标志位
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

void sendstring_zhiwen(uchar *s ,uchar length)
{
   while (length!=0)              
    {
        sendchar(*s++);
		length--;     
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

void delay10ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 108;
	j = 145;
	do
	{
		while (--j);
	} while (--i);
}


void Delay100ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 5;
	j = 52;
	k = 195;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


