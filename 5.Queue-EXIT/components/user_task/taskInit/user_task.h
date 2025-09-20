#ifndef __USER_TASK_H__
#define __USER_TASK_H__

#include "task1.h"
#include "task2.h"
#include "task3.h"

void task_init(void);

#endif  // __USER_TASK_H__

/*
 * 优先级设置（数字越大优先级越高）：
 * - StartTask:  优先级 24 (最高)
 * - task3:      优先级 3 
 * - task2:      优先级 2
 * - task1:      优先级 1 (最低)
 * 
 * 执行时序分析：
 * 1. vTaskStartScheduler() 启动调度器
 * 2. StartTask开始执行（优先级24最高）
 * 3. 创建task1（优先级1 < 24），StartTask继续执行，不会被抢占
 * 4. 创建task2（优先级2 < 24），StartTask继续执行，不会被抢占  
 * 5. 创建task3（优先级3 < 24），StartTask继续执行，不会被抢占
 * 6. vTaskDelete(NULL)删除StartTask自身
 * 7. 现在task3优先级最高（3），开始执行task3
 * 
 * 潜在问题场景：
 * 如果任何一个新创建的任务优先级 > StartTask优先级24，比如：
 * xTaskCreate(task1, "task1", 128, NULL, 25, &htask1);  // 优先级25 > 24
 * 那么task1创建后会立即抢占StartTask，导致后续的task2和task3无法创建！
 * 
 * 解决方案：
 * 1. 保持StartTask优先级最高（当前做法✓）
 * 2. 使用临界区保护整个创建过程
 * 3. 暂时禁用调度器：vTaskSuspendAll() / xTaskResumeAll()
 * 
 * 注意：ESP32默认最大优先级为25
 */