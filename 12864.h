#define uchar unsigned char
#define uint unsigned int
extern void lcd12864_init();
extern void lcd12864_show_string(uchar x,uchar y,uchar str[]);
extern void lcd12864_show_char(uchar x,uchar y,uchar ch);