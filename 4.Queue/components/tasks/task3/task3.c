#include "task3.h"

TaskHandle_t htask3 = NULL;

void task3(void *pvParameters)
{
    led_init();
    while (1)
    {
        printf("task3 is Running!---------------------\n");
        led_toggle();
        vTaskDelay(1000);
    }
}
