#include "task2.h"

TaskHandle_t htask2 = NULL;

void task2(void *pvParameters)
{
    uint8_t info;
    while (1)
    {
        printf("task2 is Running!\n");
        esp_rom_delay_us(10000); // 延时0.01秒
        xQueueReceive(hqueueOfInfo, &info, 1000);
        printf("task2 received info: %d\n", info);
        // vTaskDelay(1000);
    }
}
