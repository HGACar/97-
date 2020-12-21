#include "common.h"
#include "include.h"


#define BM_SWITCH1  PTD5
#define BM_SWITCH2  PTD4
#define BM_SWITCH3  PTD3
#define BM_SWITCH4  PTD2
#define MENU_PAGE_MAX 3	//显示页面数
uint8 menu_page=0;//OLED显示页面

uint8 dis_buff1[20]={0};  //OLED显示缓存
KEY_MSG_t keymsg;

/************************显示开机画面**************************/
void display_logo(void)
{		    
	Draw_BMP();	//动态刷新显示图片 
    OLED_Clear();
 //   OLED_Fill(0,0,127,63,1);
  //  while(1);
}



/***********************按键处理*******************************/
void key_msg_process(void)
{
if(get_key_msg(&keymsg) == 1)
{
           if(keymsg.key == KEY_U && keymsg.status ==1)
     {
        led (LED0,LED_ON); 
        ref_speed+=5;
        ErrorS=(ref_speed-16)/18;
        DELAY_MS(500); 
        led (LED0,LED_OFF);
     }

        
        
     if(keymsg.key == KEY_D && keymsg.status ==1)     {
       led (LED1,LED_ON);
       ref_speed-=5;
        //ErrorS=(ref_speed-16)/18;       
        DELAY_MS(500); 
        led (LED1,LED_OFF);
     }//可以 调 延时时间，除非 FIFO满溢出，不然不会出现漏识别按键
          if(keymsg.key == KEY_R && keymsg.status ==1)
     {
        led (LED2,LED_ON); 
        ErrorD+=5;
        DELAY_MS(500);  
        led (LED2,LED_OFF);
     }

    if(keymsg.key == KEY_L&& keymsg.status ==1)     {
       led (LED3,LED_ON);
       ErrorD-=5;       
        DELAY_MS(500); 
        led (LED3,LED_OFF);
     }//可以 调 延时时间，除非 FIFO满溢出，不然不会出现漏识别按键
      
     if(keymsg.key == KEY_START && keymsg.status ==1)
     {
        led (LED2,LED_ON); 
        ErrorS+=0.05;
        DELAY_MS(500);  
        led (LED2,LED_OFF);
     }

       
     if(keymsg.key == KEY_PUSH&& keymsg.status ==1)     {
       led (LED0,LED_ON);
       ref_speed=0;
        DELAY_MS(500); 
        led (LED0,LED_OFF);
     }//可以 调 延时时间，除非 FIFO满溢出，不然不会出现漏识别按键
      
          if(keymsg.key == KEY_STOP&& keymsg.status ==1)     {
       led (LED3,LED_ON);
       ErrorS-=0.05;       
        DELAY_MS(500); 
        led (LED3,LED_OFF);
     }//可以 调 延时时间，除非 FIFO满溢出，不然不会出现漏识别按键
      

	}
        
}

/***********************拨码开关处理*******************************/
void switch_msg_process(void)
{
	
}


/***********************OLED显示处理*******************************/
void OLED_process(void)
{
	/*switch(menu_page)
	{
		case 0://显示第1页面
	 	 	update_display0();
	 	break;
		case 1://显示第2页面
	 	 	update_display1();
	 	break;
		case 2://显示第3页面
	 	 	update_display2();
	 	break;
		case 3://显示第4页面
          show_pic_on_oled();
       //   update_display3();
	 	break;
	}*/
	
        show_pic_on_oled();
	
}


/***********************LCD显示处理*******************************/
void LCD_process(void)
{
	
}

/**********************初始化拨码开关*******************************/
void bm_switch_init(void)
{
  gpio_init  (BM_SWITCH1, GPI, 0);
  gpio_init  (BM_SWITCH2, GPI, 0);
  gpio_init  (BM_SWITCH3, GPI, 0);
  gpio_init  (BM_SWITCH4, GPI, 0);
}

/***********************返回拨码开关状态 0-3位分别代表BM1-BM4*******************************/
uint8 get_sw_status(void)
{
  uint8 sw_status=0;
  if(gpio_get(BM_SWITCH1) == 0)
     sw_status|=0x08;
  if(gpio_get(BM_SWITCH2) == 0)
     sw_status|=0x04;
  if(gpio_get(BM_SWITCH3) == 0)
     sw_status|=0x02;
  if(gpio_get(BM_SWITCH4) == 0)
     sw_status|=0x01;
  return sw_status;
}








