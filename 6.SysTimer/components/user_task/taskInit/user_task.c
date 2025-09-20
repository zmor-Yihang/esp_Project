#include "user_task.h"

void task_init(void)
{
    vTaskSuspendAll(); /* 挂起调度器，防止在创建任务过程中被切换 */

    xTaskCreate(task1, "task1", 2048, NULL, 2, &task1_handle);
    xTaskCreate(task2, "task2", 2048, NULL, 3, &task2_handle);
    xTaskCreate(task3, "task3", 2048, NULL, 4, &task3_handle);

    xTaskResumeAll(); /* 恢复调度器 */
}