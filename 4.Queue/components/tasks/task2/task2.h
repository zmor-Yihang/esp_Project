#ifndef __TASK2_H__
#define __TASK2_H__

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>
#include "user_queue.h"
#include "esp_timer.h"

extern TaskHandle_t htask2;

void task2(void *pvParameters);

#endif // __TASK2_H__
