#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BLINK_GPIO GPIO_NUM_1

void app_main(void)
{
    // 配置 GPIO 为输出模式
    gpio_config_t io_conf = {
        .pin_bit_mask = 1ULL << BLINK_GPIO,
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = 0,
        .pull_down_en = 0,
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&io_conf);

    while (1) {
        // 点亮 LED
        gpio_set_level(BLINK_GPIO, 1);
        vTaskDelay(pdMS_TO_TICKS(500));  // 延时 500ms
        printf("LED ON\n");

        // 熄灭 LED
        gpio_set_level(BLINK_GPIO, 0);
        vTaskDelay(pdMS_TO_TICKS(500));
        printf("LED OFF\n");
    }
}
