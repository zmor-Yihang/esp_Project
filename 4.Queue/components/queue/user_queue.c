#include "user_queue.h"
#include "esp_log.h"

/* 消息队列句柄 */
QueueHandle_t hqueueOfInfo = NULL;

void queue_init(void)
{
    /* 创建消息队列 */
    hqueueOfInfo = xQueueCreate(10, sizeof(uint8_t));
}
