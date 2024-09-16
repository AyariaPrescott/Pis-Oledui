#include <iostream>
#include <cstring>
extern "C"
{
    #include <wiringPi.h>
    #include <wiringPiI2C.h>
    #include "oled.h"
    #include "GCFK.h"
    #include <stdio.h>
    #include <string.h>
}
using namespace std;


void InitScreen()	//画上四分之一部分的框
{
    OLED_DrawLine(0,0,127,0,1);
    OLED_DrawLine(0,15,127,15,1);
    OLED_DrawLine(0,0,0,15,1);
    OLED_DrawLine(127,0,127,15,1);
    OLED_Refresh();
}

string GSFK() //Get String From Keyboard
{
    string get_st;
    int ch_num;
    system(STTY_US TTY_PATH);
    while(true)
    {
        ch_num = GetChar();
        if(ch_num == 127)
        {
            get_st.pop_back();
        }
        else if(ch_num >= 32 && ch_num <= 126)
        {
            get_st.push_back(char(ch_num));
        }
        if(ch_num == 3)
        {
            system(STTY_DEF TTY_PATH);
            break;
        }
        OLED_ShowString(1,1,(unsigned char *)get_st.c_str(),12,1);
        InitScreen();
        OLED_Refresh();
    }
    return get_st;
}

int Init()
{
    int fd;
    if(wiringPiSetup() < 0) //当使用这个函数初始化树莓派引脚时，程序使用的是wiringPi 引脚编号表。
        return 1;
    fd = wiringPiI2CSetup (SlaveAddress);
    if(fd < 0)
    {
        printf("IIC初始化失败\r\n");
        return fd;
    }
    return 0;
}

int main()
{
    if(Init() != 0) return Init();
    OLED_Init();
    OLED_Clear();

    cout << GSFK() << '\n';
    return 0;
}