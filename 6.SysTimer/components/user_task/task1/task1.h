#ifndef __TASK1_H__
#define __TASK1_H__

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

extern TaskHandle_t task1_handle;

void task1(void *pvParameters);

#endif // __TASK1_H__

