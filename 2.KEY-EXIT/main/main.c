#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "led.h"
#include "key.h"

void app_main(void)
{
    // 初始化LED
    led_init();

    TickType_t start_time, end_time;
    while (1) 
    {
        start_time = xTaskGetTickCount();
        led_toggle();       // 切换LED状态
        vTaskDelay(1000);   // 延时1秒
        end_time = xTaskGetTickCount();
        printf("Delay time: %lu ms\n", (end_time - start_time) * portTICK_PERIOD_MS);
    }
}
