#ifndef __TASK1_H__
#define __TASK1_H__

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>
#include "esp_timer.h"
#include "user_queue.h"

extern TaskHandle_t htask1;

void task1(void *pvParameters);

#endif // __TASK1_H__

