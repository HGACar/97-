//声明：本代码由山外多功能软件自动生成，请勿修改。 

#ifndef _MAIN_MENU_H_
#define _MAIN_MENU_H_

#include "common.h"
#include "include.h"



extern Site_t site;
extern Size_t size;
extern Size_t imgsize;

extern Site_t site_dis;                                        //LCD显示变量
extern uint8 imgbuff[CAMERA_SIZE];                             //定义存储接收图像的数组
extern uint8 img[CAMERA_H][CAMERA_W];
extern float cam_ratio;

extern uint8 pid_flag;
extern float SpeedP;
extern float SpeedI;
extern float SpeedD;
extern float TurnP;
extern float TurnD;
extern float ref_speed;            //参考速度

extern float Error;
extern float ErrorS;
extern float ErrorT;
extern float ExpectSpeed;

extern uint8 TIME0flag_5ms   ;
extern uint8 TIME0flag_10ms  ;
extern uint8 TIME0flag_15ms  ;
extern uint8 TIME0flag_20ms  ;
extern uint8 TIME0flag_50ms  ;
extern uint8 TIME0flag_80ms  ;
extern uint8 TIME0flag_100ms ;
extern uint8 TIME0flag_1s;
extern uint8 TimeCount;

extern uint8 PTD5_data;
extern uint8 PTD4_data;
extern uint8 PTD3_data;
extern uint8 PTD2_data;

extern uint8 start_count;
extern uint32 stop_time;
extern uint8 stop_flag;

/*extern uint8 menu_flag;
extern uint32 mid_dis;                            //两车会车的距离，可根据赛道调节
extern uint32 meet_dis;
extern uint32 whole_dis;                          //总距离
extern uint32 dis_right;                          //右轮的距离
extern uint32 dis_left;                           //左轮的距离
extern uint32 dis;
extern uint8 meet_flag_a;
extern uint8 meet_flag_b;
extern uint32 meet_times;*/

extern uint32 annular_dis;

extern uint8 start_flag;
extern uint32 start_time;



extern float speed_left;
extern float speed_right;
extern float speed;

extern void image_analyze();
extern void eagle_run();
extern void pointline(void);

extern void speed_get();                               //编码器速度获得
extern void speed_control();                           //电机PID控制
extern void motor_F(float n);                            //电机前进
extern void motor_B(float n);                            //电机后退

extern void serve_motor_control();                      //舵机PID控制
extern void serve_motor_turn(float n);	                //舵机转向

extern void main_menu_task(void);
extern void switch_gpio_get();
extern void switch_gpio_init();





/***************************************** 下列为用户函数配置  **************************************/



/****************************************下列为菜单函数配置************************************/

//              wxj
//extern void        menu_dis_deal(void);
//extern void        menu_pid_deal(void);
//extern void        menu_cam_deal(void);
//extern void        menu_speed_deal(void);
//extern void        main_menu_task(void);

#endif   //#ifndef_MAIN_MENU_H_
