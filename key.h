#ifndef __KEY_H_
#define __KEY_H_

#include<reg52.h>

#define GPIO_KEY P1
#define uchar unsigned char
extern uchar KeyValue;
//������Ŷ�ȡ���ļ�ֵ

//--����ȫ�ֺ���--//
void Delay10ms(unsigned int c);    //��ʱ10ms
void KeyDown();		              //��ⰴ������
#endif 