
#ifndef __MAIN_H
#define __MAIN_H	



typedef struct
{
    uint8 c1;//使用摄像头
    uint8 c2;   //使用LCD
    uint8 c3;//使用串口输出
    uint8 c4;//使用无线模块
} sys_con;


void show_pic_on_oled(void);//在OLED上显示图像

extern float speed_right;//帧数累计标志
extern float ErrorP;//保存速度的变量
extern float ErrorS;//保存速度的变量
extern float ErrorD;//保存速度的变量
extern float Error;//保存速度的变量
extern float  ExpectSpeed;
extern float  mid_val;
extern float  MINK;
extern int turn;//保存速度的变量
extern float ref_speed;
#endif  