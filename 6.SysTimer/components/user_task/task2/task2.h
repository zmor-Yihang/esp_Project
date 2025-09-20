#ifndef __TASK2_H__
#define __TASK2_H__

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

extern TaskHandle_t task2_handle;

void task2(void *pvParameters);

#endif // __TASK2_H__
