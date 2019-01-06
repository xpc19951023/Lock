#ifndef __KEY_H_
#define __KEY_H_

#include<reg52.h>

#define GPIO_KEY P1
#define uchar unsigned char
extern uchar KeyValue;
//用来存放读取到的键值

//--声明全局函数--//
void Delay10ms(unsigned int c);    //延时10ms
void KeyDown();		              //检测按键函数
#endif 