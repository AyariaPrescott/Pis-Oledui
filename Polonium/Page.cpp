#include "Page.h"
#include <iostream>
extern "C"
{
#include "../oled.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include "../GCFK.h"
#include <stdio.h>
#include <string.h>
#include "stdlib.h"
}

void Page::MainLoop()
{
    while (true)
    {
        for (auto it = items_.begin(); it != items_.end(); it++)
        {
            (*it)->Render();
        }
        OLED_Refresh();
        for (auto it = items_.begin(); it != items_.end(); it++)
        {
            (*it)->Test();
        }
    }
}