#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "led.h"
#include "key.h"

void app_main(void)
{
    // 初始化LED
    led_init();
    
    // 初始化按键
    key_init();

    while (1) 
    {
        if (FlagOfButtonPressed) 
        {
            vTaskDelay(pdMS_TO_TICKS(50)); // 简单消抖
            if (key_get_state() == 0) // 确认按键仍然按下
            {
                while (key_get_state() == 0); // 等待按键释放
                led_toggle();                 // 切换LED状态
                FlagOfButtonPressed = false;  // 清除按键标志
            }
            /* 误触 */
            FlagOfButtonPressed = false; // 如果按键已释放，仍然清除标志
        }
    }
}
