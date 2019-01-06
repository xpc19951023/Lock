#include <reg52.h>

void main()
{
   init();//初始化，读取密码
   display_init_lcd();//显示初始界面
   /*
     1 密码解锁
	 2 蓝牙解锁
	 3 指纹解锁
	 4 设置
   */
   key_num=get_keynum();
	while(1)
	{
		if(key_num==1)
		{  
			mimajiesuo();//密码解锁
		}
		if(key_num==2)
		{
			lanyajiesuo();//	蓝牙解锁
		}
		if(key_num==3)
		{  
			zhiwenjiesuo();//指纹解锁
		}
		if(key_num==4)
		{   
			shezhi();	  //  设置
		}
	   
	}
}