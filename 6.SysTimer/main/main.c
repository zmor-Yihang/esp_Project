#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "systimer.h"

void app_main(void)
{
    // queue_init();
    // task_init();
    led_init();
    systimer_init();
    systimer_start_period(1000); // 启动周期性定时器

    vTaskDelete(NULL); // 删除主任务main
}
