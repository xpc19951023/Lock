#include <reg52.h>
#include "12864.h"
#include "key.h"

uchar code table1[]="1.���뿪��";
uchar code table2[]="2.ָ�ƿ���";
uchar code table3[]="3.��������";
uchar code table4[]="4.����";
uchar code table5[]="5.ȷ��";
uchar code table6[]="10.delete";
uchar code table7[]="11ȷ��";
uchar code table8[]="12�˳�";

uchar code table11[]="�������û�����";
uchar code table21[]="�������û�ָ��";
uchar code table31[]="�����������豸";
uchar code table41[]="    ���ý���  ";
uchar code table00[]="                  ";

uchar  index=0;
uchar mima[6]={0};		  //����
uchar mima_edit[6]={0};	  //�û����������

uchar flag_function=0;
uchar flag_mimakaisuo=0;
uchar flag_zhiwenkaisuo=0;
uchar flag_lanyakaisuo=0;
uchar flag_shezhijiemian=0;
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
	
	while(1)
	{
		 KeyDown();

		 //һ���˵�
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
					  lcd12864_show_char(1,index,KeyValue+'0');
					  KeyValue=17;
					  }else
					  {
					  //�Ѿ������������ˣ�����������
					  }
					
				  }else
				  {
				    if(KeyValue==10)
					{
					   //ɾ��һλ
					}else if(KeyValue==11)
					{
					 //ȷ��
					}
					else if(KeyValue==12)
					{
					  //�˳�
					}else
					{
					  //���ְ�������Ч
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
	   
	   }

	   	//�����˵� ��������������������
	   if(flag_shezhijiemian==1)
	   {
	   
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
	mima[0]=1;
	mima[1]=2;
	mima[2]=3;
	mima[3]=4;
	mima[4]=5;
	mima[5]=6;
}