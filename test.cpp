#include "Polonium/Element.h"
#include "Polonium/Page.h"
#include "Polonium/Elements/TextElements.h"
#include <iostream>
using namespace std;

extern "C"
{
#include "./oled.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include "./GCFK.h"
#include <stdio.h>
#include <string.h>
#include "stdlib.h"
}

void Init()
{
    wiringPiSetup();
    int fd = wiringPiI2CSetup(SlaveAddress);
    FILE *pf = fopen("./oled_fd.ini", "w");
    fprintf(pf, "%d", fd);
    fclose(pf);
    pf = NULL;
    OLED_Init();
    OLED_Clear();
    cout << "Inited" << endl;
    system(STTY_US TTY_PATH);
}

int main()
{
    Init();
    InputTextBox textbox(5, 5, 10, 10, 24);
    TextLine text(5, 40, 10, 10, "HELLO", 8);
    Page page;
    page.AddElement(&textbox);
    page.AddElement(&text);
    page.MainLoop();
    return 0;
}