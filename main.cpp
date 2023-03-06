#include "mbed.h"

// main() runs in its own thread in the OS
int main()
{
    DigitalIn mypin(BUTTON1);
    DigitalOut myled(LED1);
    DigitalOut success(LED2);

    if (mypin.is_connected())
    {
        printf("mypin is connected and initialized! \n\r");
    }
    int push = 0;
    int not_push = 0;
    while (true) {
        success = 1;
        ThisThread::sleep_for(500ms);
        if (mypin == 0)
            push++;
        if (push == 3){
            myled = 1;
            push = 0;
            not_push = 0;
        }
        if (mypin == 1)
            not_push++;
        if (not_push == 3){
            myled = 0;
            push = 0;
            not_push = 0;
        }
        success = 0;
        ThisThread::sleep_for(500ms);
    }
}

