#include<reg51.h>
#include<intrins.h>
#include<stdlib.h>

#define uchar unsigned char
#define uint unsigned int

sbit rs = P2^6;
sbit rw = P2^5;
sbit LCD_EN = P2^7;
sbit PSB = P3^2; //可以直接高电平
//P0数据显示


uchar code table1[]="江苏理工学院";
uchar code table2[]="电气信息工程学院";

void write_12864com(uchar com);
void write_12864dat(uchar dat);
void delay_ms(uint z);
void led_pos(uchar x,uchar y);
void init();

void main()
{
uchar i;
init();
led_pos(1,0);
i=0;
while(table1[i]!='\0')
{
  write_12864dat(table1[i]);	  
  i++;
}
led_pos(2,0);
i=0;
while(table2[i]!='\0')
{
  write_12864dat(table2[i]);	  
  i++;
}
while(1);
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

void init()
{
  PSB=1;
  write_12864com(0x30);
  delay_ms(5);
  write_12864com(0x0c);
  delay_ms(5);
  write_12864com(0x01);
  delay_ms(5);
}

