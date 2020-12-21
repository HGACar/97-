#include "common.h"
#include "include.h"


#define BM_SWITCH1  PTD5
#define BM_SWITCH2  PTD4
#define BM_SWITCH3  PTD3
#define BM_SWITCH4  PTD2
#define MENU_PAGE_MAX 3	//��ʾҳ����
uint8 menu_page=0;//OLED��ʾҳ��

uint8 dis_buff1[20]={0};  //OLED��ʾ����
KEY_MSG_t keymsg;

/************************��ʾ��������**************************/
void display_logo(void)
{		    
	Draw_BMP();	//��̬ˢ����ʾͼƬ 
    OLED_Clear();
 //   OLED_Fill(0,0,127,63,1);
  //  while(1);
}



/***********************��������*******************************/
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
     }//���� �� ��ʱʱ�䣬���� FIFO���������Ȼ�������©ʶ�𰴼�
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
     }//���� �� ��ʱʱ�䣬���� FIFO���������Ȼ�������©ʶ�𰴼�
      
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
     }//���� �� ��ʱʱ�䣬���� FIFO���������Ȼ�������©ʶ�𰴼�
      
          if(keymsg.key == KEY_STOP&& keymsg.status ==1)     {
       led (LED3,LED_ON);
       ErrorS-=0.05;       
        DELAY_MS(500); 
        led (LED3,LED_OFF);
     }//���� �� ��ʱʱ�䣬���� FIFO���������Ȼ�������©ʶ�𰴼�
      

	}
        
}

/***********************���뿪�ش���*******************************/
void switch_msg_process(void)
{
	
}


/***********************OLED��ʾ����*******************************/
void OLED_process(void)
{
	/*switch(menu_page)
	{
		case 0://��ʾ��1ҳ��
	 	 	update_display0();
	 	break;
		case 1://��ʾ��2ҳ��
	 	 	update_display1();
	 	break;
		case 2://��ʾ��3ҳ��
	 	 	update_display2();
	 	break;
		case 3://��ʾ��4ҳ��
          show_pic_on_oled();
       //   update_display3();
	 	break;
	}*/
	
        show_pic_on_oled();
	
}


/***********************LCD��ʾ����*******************************/
void LCD_process(void)
{
	
}

/**********************��ʼ�����뿪��*******************************/
void bm_switch_init(void)
{
  gpio_init  (BM_SWITCH1, GPI, 0);
  gpio_init  (BM_SWITCH2, GPI, 0);
  gpio_init  (BM_SWITCH3, GPI, 0);
  gpio_init  (BM_SWITCH4, GPI, 0);
}

/***********************���ز��뿪��״̬ 0-3λ�ֱ����BM1-BM4*******************************/
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








