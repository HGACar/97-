
#ifndef __MAIN_H
#define __MAIN_H	



typedef struct
{
    uint8 c1;//ʹ������ͷ
    uint8 c2;   //ʹ��LCD
    uint8 c3;//ʹ�ô������
    uint8 c4;//ʹ������ģ��
} sys_con;


void show_pic_on_oled(void);//��OLED����ʾͼ��

extern float speed_right;//֡���ۼƱ�־
extern float ErrorP;//�����ٶȵı���
extern float ErrorS;//�����ٶȵı���
extern float ErrorD;//�����ٶȵı���
extern float Error;//�����ٶȵı���
extern float  ExpectSpeed;
extern float  mid_val;
extern float  MINK;
extern int turn;//�����ٶȵı���
extern float ref_speed;
#endif  