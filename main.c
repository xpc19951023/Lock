#include <reg52.h>
#include "12864.h"
#include "key.h"
#include "intrins.h"
typedef unsigned char BYTE;
typedef unsigned int WORD;


uchar code table1[]="1.���뿪��";
uchar code table2[]="2.ָ�ƿ���";
uchar code table3[]="3.��������";
uchar code table4[]="4.����";
uchar code table5[]="5.ȷ��";
uchar code table6[]="10.delete";
uchar code table7[]="11ȷ��";
uchar code table8[]="12�˳�";
uchar code table9[]="    �����ɹ�    ";


uchar code table11[]="  ����������    ";
uchar code table21[]="  ������ָ��    ";
uchar code table31[]="  ����������    ";
uchar code table41[]="    ���ý���  ";
uchar code table00[]="                  ";



uchar  index=0;
uchar mima[6]={0};		  //����
uchar mima_edit[6]={0xff,0xff,0xff,0xff,0xff,0xff};	  //�û����������


#define FOSC 12000000L      //System frequency
#define BAUD 9600           //UART baudrate

/*Define UART parity mode*/
#define NONE_PARITY     0   //None parity
#define ODD_PARITY      1   //Odd parity
#define EVEN_PARITY     2   //Even parity
#define MARK_PARITY     3   //Mark parity
#define SPACE_PARITY    4   //Space parity

#define PARITYBIT NONE_PARITY   //Testing even parity

bit busy;

void SendData(BYTE dat);
void SendString(char *s);

void UsartConfiguration();

uchar flag_function=0;
uchar flag_mimakaisuo=0;
uchar flag_zhiwenkaisuo=0;
uchar flag_lanyakaisuo=0;
uchar flag_shezhijiemian=0;
uchar checkmima(uchar mima[],uchar mima_edit[]);
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
//
	UsartConfiguration();
	while(1)
	{
		 KeyDown();
			
		 //һ���˵�
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

	  //�����˵� �����������뿪������
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
					   //ɾ��һλ
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
					   //indexΪ0��������
					   }
					   
					}
					
					else if(KeyValue==11)
					{
					 //ȷ��
					  KeyValue=17;
					   if(checkmima(mima,mima_edit))
					   {
						  //������ȷ����,��ʾ
	                    lcd12864_show_string(0,0,table9);	             
	                    lcd12864_show_string(1,0,table00);
	                    lcd12864_show_string(2,0,table00);
                        lcd12864_show_string(3,0,table00);
						 
					   } else
					   {
						 //���������ʾ,���������
						 uchar i;
						 for(i=0;i<6;i++)
						 lcd12864_show_char(1,i,' ');
						 index=0;
						
					   }
					   //������������
					   	mima_edit[0]=0xff;
						mima_edit[1]=0xff;
						mima_edit[2]=0xff;
						mima_edit[3]=0xff;
						mima_edit[4]=0xff;
						mima_edit[5]=0xff;
					}

					else if(KeyValue==12)
					{
					  //�˳�
					   KeyValue=17;
					   flag_mimakaisuo=0;
					   lcd12864_show_string(0,1,table1);
	                   lcd12864_show_string(1,1,table2);
	                   lcd12864_show_string(2,1,table3);
                       lcd12864_show_string(3,1,table4);
                       lcd12864_show_string(3,5,table5);

					   //������������
					    mima_edit[0]=0xff;
						mima_edit[1]=0xff;
						mima_edit[2]=0xff;
						mima_edit[3]=0xff;
						mima_edit[4]=0xff;
						mima_edit[5]=0xff;
					
					}else
					{
					  //���ְ�������Ч
					   KeyValue=17;
					}
				  }

			 
		  }
		 

	   }

	   	//�����˵� ��������ָ�ƿ�������
	   if(flag_zhiwenkaisuo==1)
	   {
	   
	   }

	   	//�����˵� ��������������������
	   if(flag_lanyakaisuo==1)
	   {
	     	if(KeyValue==12)
			{
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

	   	//�����˵� �����������ý���
	   if(flag_shezhijiemian==1)
	   {
	   
	   }
	



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

	SCON=0X50;			//����Ϊ������ʽ1
	TMOD=0X20;			//���ü�����������ʽ2
	PCON=0X00;			//�����ʼӱ�
	TH1=0XFd;		    //��������ʼֵ���ã�ע�Ⲩ������9600��
	TL1=0XFd;
	ES=1;						//�򿪽����ж�
	EA=1;						//�����ж�
	TR1=1;					    //�򿪼�����
}

void Usart() interrupt 4
{
	unsigned char receiveData;
	receiveData=SBUF; //��ȥ���յ�������
	RI = 0;           //��������жϱ�־λ
	SBUF=receiveData; //�����յ������ݷ��뵽���ͼĴ���
	while(!TI);		  //�ȴ������������
	TI=0;			  //���������ɱ�־λ
}

