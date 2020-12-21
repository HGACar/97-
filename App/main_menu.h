//��������������ɽ��๦������Զ����ɣ������޸ġ� 

#ifndef _MAIN_MENU_H_
#define _MAIN_MENU_H_

#include "common.h"
#include "include.h"



extern Site_t site;
extern Size_t size;
extern Size_t imgsize;

extern Site_t site_dis;                                        //LCD��ʾ����
extern uint8 imgbuff[CAMERA_SIZE];                             //����洢����ͼ�������
extern uint8 img[CAMERA_H][CAMERA_W];
extern float cam_ratio;

extern uint8 pid_flag;
extern float SpeedP;
extern float SpeedI;
extern float SpeedD;
extern float TurnP;
extern float TurnD;
extern float ref_speed;            //�ο��ٶ�

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
extern uint32 mid_dis;                            //�����ᳵ�ľ��룬�ɸ�����������
extern uint32 meet_dis;
extern uint32 whole_dis;                          //�ܾ���
extern uint32 dis_right;                          //���ֵľ���
extern uint32 dis_left;                           //���ֵľ���
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

extern void speed_get();                               //�������ٶȻ��
extern void speed_control();                           //���PID����
extern void motor_F(float n);                            //���ǰ��
extern void motor_B(float n);                            //�������

extern void serve_motor_control();                      //���PID����
extern void serve_motor_turn(float n);	                //���ת��

extern void main_menu_task(void);
extern void switch_gpio_get();
extern void switch_gpio_init();





/***************************************** ����Ϊ�û���������  **************************************/



/****************************************����Ϊ�˵���������************************************/

//              wxj
//extern void        menu_dis_deal(void);
//extern void        menu_pid_deal(void);
//extern void        menu_cam_deal(void);
//extern void        menu_speed_deal(void);
//extern void        main_menu_task(void);

#endif   //#ifndef_MAIN_MENU_H_
