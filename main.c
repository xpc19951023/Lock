#include <reg52.h>
#include "12864.h"
uchar code table1[]="江苏理工学院";
uchar code table2[]="电气信息工程学院";
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
	lcd12864_show_string(0,0,table1);
	lcd12864_show_string(0,1,table2);
	while(1)
	{
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
}