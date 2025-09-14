#include "task1.h"

/* 任务句柄 */
TaskHandle_t htask1 = NULL;

void task1(void *pvParameters)
{
    static uint8_t count = 0;
    while (1)
    {
        printf("task1 is Running!\n");
        count++;
        esp_rom_delay_us(10000); // 延时0.01秒
        xQueueSend(hqueueOfInfo, &count, 1000);
    }
}
