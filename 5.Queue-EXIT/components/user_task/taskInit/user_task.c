#include "user_task.h"

void task_init(void)
{
    vTaskSuspendAll(); /* 挂起调度器，防止在创建任务过程中被切换 */

    // xTaskCreate(task1, "task1", 2048, NULL, 2, &htask1);
    // xTaskCreate(task2, "task2", 2048, NULL, 3, &htask2);
    xTaskCreate(task3, "task3", 2048, NULL, 4, &htask3);

    xTaskResumeAll(); /* 恢复调度器 */
}