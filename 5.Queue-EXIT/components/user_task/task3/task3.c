#include "task3.h"

TaskHandle_t htask3 = NULL;

void task3(void *pvParameters)
{
    key_init();
    led_init();
    uint8_t Info = 0;
    while (1)
    {
        printf("task3 is Running!---------------------\n");
        xQueueReceive(hqueueOfInfo, &Info, portMAX_DELAY); /* 等待按键事件 */
        led_toggle();
    }
}
