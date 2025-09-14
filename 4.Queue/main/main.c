#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "user_task.h"

void app_main(void)
{
    queue_init();
    task_init();

    vTaskDelete(NULL); // 删除主任务main
}
