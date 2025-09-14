#ifndef __USER_QUEUE_H__
#define __USER_QUEUE_H__

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

extern QueueHandle_t hqueueOfInfo;

void queue_init(void);

#endif  // __USER_QUEUE_H__
