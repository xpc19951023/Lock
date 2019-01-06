#include<reg52.h>
#include<intrins.h>
#include<stdlib.h>
#include"12864.h"


sbit rs = P2^6;
sbit rw = P2^5;
sbit LCD_EN = P2^7;
sbit PSB = P3^2; //可以直接高电平
//P0数据显示




void write_12864com(uchar com);
void write_12864dat(uchar dat);
void delay_ms(uint z);
void led_pos(uchar x,uchar y);
void lcd12864_init();
void lcd12864_show_string(uchar x,uchar y,uchar str[]);
void lcd12864_show_char(uchar x,uchar y,uchar ch);


void lcd12864_show_string(uchar x,uchar y,uchar str[])
{
	   uchar i;
		led_pos(x,y);
		i=0;
		while(str[i]!='\0')
		{
		  write_12864dat(str[i]);	  
		  i++;
		}
}

void write_12864com(uchar com)
{
rs = 0;
rw = 0;
LCD_EN = 0;
P0 = com;
delay_ms(5);
LCD_EN = 1;
delay_ms(5);
LCD_EN = 0;
}

void write_12864dat(uchar dat)
{
rs = 1;
rw = 0;
LCD_EN=0;
P0 = dat;
delay_ms(5);
LCD_EN = 1;
delay_ms(5);
LCD_EN = 0;
}

void delay_ms(uint z)
{
uint x,y;
for(x=z;x>0;x--)
for(y=110;y>0;y--);
}

void led_pos(uchar x,uchar y)
{
  uchar pos;
  if(x==0)
  {x=0x80;}
  else if(x==1)
  {x=0x90;}
  else if(x==2)
  {x=0x88;}
  else if(x==3)
  {x=0x98;}
  pos=x+y;
  write_12864com(pos);
 
}

void lcd12864_init()
{
  PSB=1;
  write_12864com(0x30);
  delay_ms(5);
  write_12864com(0x0c);
  delay_ms(5);
  write_12864com(0x01);
  delay_ms(5);
}

void lcd12864_show_char(uchar x,uchar y,uchar ch)
{
  	led_pos(x,y);
	 write_12864dat(ch);
}

