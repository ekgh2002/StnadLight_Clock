#include "View.h"
#include <wiringPi.h>
#include <LCD.h>

View::View(Led *led1, Led *led2, Led *led3, Led *led4, Led *led5, LCD *Lcd)
{
    this->lcd = Lcd;
    light1 = led1;
    light2 = led2;
    light3 = led3;
    light4 = led4;
    light5 = led5;
    lightState = LIGHT_OFF;
}

View::~View()
{

}
void View::setState(int state)
{
    lightState = state;
}

void View::lightView()
{
    switch (lightState)
    {
        case LIGHT_OFF:
            lightOff();
            LCDplay0();
        break;
        case LIGHT_1:
            lightOn_1();
            LCDplay1();
        break;
        case LIGHT_2:
            lightOn_2();
            LCDplay2();        
        break;
        case LIGHT_3:
            lightOn_3();
            LCDplay3();
        break;
        case LIGHT_4:
            lightOn_4();
            LCDplay4();
        break;
        case LIGHT_5:
            lightOn_5();
            LCDplay5();
        break;    
    }
}

void View::lightOn_1()
{
    light1->On();
    light2->Off();
    light3->Off();
    light4->Off();
    light5->Off();
}

void View::lightOn_2()
{
    light1->On();
    light2->On();
    light3->Off();
    light4->Off();
    light5->Off();
}

void View::lightOn_3()
{
    light1->On();
    light2->On();
    light3->On();
    light4->Off();
    light5->Off();
}

void View::lightOn_4()
{
    light1->On();
    light2->On();
    light3->On();
    light4->On();
    light5->Off();
}

void View::lightOn_5()
{
    light1->On();
    light2->On();
    light3->On();
    light4->On();
    light5->On();
}

void View::lightOff()
{
    light1->Off();
    light2->Off();
    light3->Off();
    light4->Off();
    light5->Off();
}

void View::LCDplay0()
{
    lcd->WriteStringXY(0, 0, "      OFF   ");
}

void View::LCDplay1()
{
    lcd->WriteStringXY(0, 0, "     power1");
}

void View::LCDplay2()
{
    lcd->WriteStringXY(0, 0, "     power2");
}

void View::LCDplay3()
{
    lcd->WriteStringXY(0, 0, "     power3");
}

void View::LCDplay4()
{
    lcd->WriteStringXY(0, 0, "     power4");
}

void View::LCDplay5()
{
    lcd->WriteStringXY(0, 0, "     power5");
}