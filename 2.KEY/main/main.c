#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "led.h"
#include "driver/gpio.h"

void app_main(void)
{
    // 初始化LED
    led_init();

    while (1) 
    {
        led_toggle(); // 切换LED状态
        int current_level = gpio_get_level(GPIO_NUM_1);
        printf("LED Toggled - GPIO1 Level: %d\n", current_level);
        vTaskDelay(pdMS_TO_TICKS(1000)); // 延时1秒
    }
}
