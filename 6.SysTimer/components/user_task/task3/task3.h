#ifndef __TASK3_H__
#define __TASK3_H__

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

extern TaskHandle_t task3_handle;

void task3(void *pvParameters);

#endif // __TASK3_H__
