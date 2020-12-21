#include "common.h"
#include  "enter.h"
#include "VCAN_key.h"
#include "VCAN_menu.h"




result_e menu_deal(Site_t site,menu_t *menu,uint8 tab,uint8 *new_tab,uint8 max_tab)
{
    KEY_MSG_t keymsg;

    while(get_key_msg(&keymsg) == 1)
    {
        if(keymsg.status == KEY_DOWN)
        {
            switch(keymsg.key)
            {
            case KEY_D:
                {
                    if(*new_tab < max_tab-1)
                    {
                        (*new_tab)++;
                        menu_display(site,menu,*new_tab - 1 ,*new_tab,max_tab);
                    }
                    else
                    {
                        *new_tab=0;
                        menu_display(site,menu,max_tab - 1 ,*new_tab,max_tab);
                    }
                    menu_display(site,menu,*new_tab ,*new_tab,max_tab);
                    break;
                }
            case KEY_U:
                {
                    if(*new_tab == 0)
                    {
                        *new_tab = max_tab - 1;
                        menu_display(site,menu,0 ,*new_tab,max_tab);
                    }
                    else
                    {
                        (*new_tab)--;
                        menu_display(site,menu,*new_tab + 1 ,*new_tab,max_tab);
                    }
                    menu_display(site,menu,*new_tab ,*new_tab,max_tab);
                    break;
                }
            case KEY_A:
                {
                    return RESULT_INIT;
                }
            case KEY_B:
                {
                    return menu[*new_tab].pfunc();
                }

            default:
                break;

            }

        }
    }

    return RESULT_NULL;
}

