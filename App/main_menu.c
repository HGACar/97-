//可供参考的菜单函数模版

#include "main_menu.h"

uint16 BCOLOUR_1=RED;
uint16 BCOLOUR_2=RED;
uint16 BCOLOUR_3=RED;
uint16 BCOLOUR_4=RED;
uint16 BCOLOUR_5=RED;
uint16 BCOLOUR_6=RED;

char buff[20];                                          //LCD显示数组

uint8 dis_flag=0;
uint8 dis_menu_flag=1;
uint8 pid_flag=1;



void main_task(void)
{
  
 /* if(TIME0flag_10ms == 1)
      {
//        if(dis_flag==0)
//        {
          dis_right += speed_right;
          dis_left += speed_left;
          dis = (int)((dis_right + dis_left)/2)/100;
          if( (dis>=(annular_dis-100)) && (dis<=(annular_dis+100)) )
          {
            
          }
//        }
//         key_IRQHandler();                       //把按键扫描程序加入到定时中断复位函数里，定时执行
         
        TIME0flag_10ms = 0;
      }*/
      
  eagle_run();
  
  if(TIME0flag_5ms == 1)
  {  
    serve_motor_control();
    TIME0flag_5ms = 0;
  }
  
  if(TIME0flag_20ms == 1)
  {  
    speed_control();

      led(LED0, LED_ON);
        start_flag=1;
      
    //        speed_get();
    TIME0flag_20ms = 0;
  }
  
  if(TIME0flag_1s == 1)
  {  
//    if(stop_flag)
//    {
//      stop_time++;
//    }
    if(start_flag==1)
    {
      start_time++;
    }

//    if(stop_time > 2)
//    {
//        stop_time = 2;
//    }
//    if(stop_time == 2)
//    {
////      motor_B(20);
//      ExpectSpeed = 0;
//    }
  
    
    TIME0flag_1s = 0;
  }
}

void main_menu_task(void)
{
  
                              //菜单结构体
  KEY_MSG_t keymsg;

   MAIN_INIT:
      while(get_key_msg(&keymsg) == 1);      //清空按键消息
  while(1)
  {
    

      main_task();
      

  }
}

