#include "InterruptIn.h"
#include "PinNames.h"
#include "mbed.h"

DigitalOut oled1(LED1);
InterruptIn ibutton1(BUTTON1);

static auto sleep_time = 1000ms;
int r = 0;

Ticker toggle_led_ticker;

void led_ticker()
{
    oled1 = !oled1;

}

void pressed()
{
// Управление скоростью мерцания светодиода
    if (r < 2) \
        r++;
        else
            r=0;

    // toggle_led_ticker.detach(); // открепляет таймер

    // sleep_time += 1000ms;
    // if (sleep_time > 5000ms) sleep_time = 100ms;
    // // *** ваш код для обработки прерывания ***
    // toggle_led_ticker.attach(&led_ticker, sleep_time); // прикрепляет

}


// main() runs in its own thread in the OS
int main()
{

    //toggle_led_ticker.attach(&led_ticker, sleep_time);
    //toggle_led_ticker.attach(&led3_ticker, sleep_time + 1000ms);
// Прикрепляем функцию для обработки нажатия
    ibutton1.rise(&pressed);

    while (true) {
        if (r==0) {
           
            oled1 = 1; // Включение светодиода
            ThisThread::sleep_for(100ms); // Задержка в 0,1 секунду
            oled1=0;
            ThisThread::sleep_for(100ms);

            //oled1=0;
        }
        if (r==1) {
            
            oled1 = 1; 
            0
			oled1 = 1;
			ThisThread::sleep_for(500ms); // Задержка в 0,5 секунду
			oled1 = 0;
			ThisThread::sleep_for(500ms);
			oled1 = 1;
			ThisThread::sleep_for(500ms); // Задержка в 0,5 секунду
			oled1 = 0;
			ThisThread::sleep_for(500ms);
        }
        if (r==2) {
            
            oled1 = 1; 
            ThisThread::sleep_for(1000ms); // Задержка в 1 секунду
            oled1=0;
            ThisThread::sleep_for(1000ms);
			oled1 = 1;
			ThisThread::sleep_for(800ms);
			oled1 = 0;
			ThisThread::sleep_for(800ms);
			oled1 = 1;
			ThisThread::sleep_for(600ms);
			oled1 = 0;
			ThisThread::sleep_for(600ms);
			oled1 = 1;
			ThisThread::sleep_for(400ms);
			oled1 = 0;
			ThisThread::sleep_for(400ms);
			oled1 = 1;
			ThisThread::sleep_for(200ms);
			oled1 = 0;
			ThisThread::sleep_for(200ms);
        }
    }
}
