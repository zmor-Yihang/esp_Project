#ifndef __KEY_H__
#define __KEY_H__

#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define KEY_BOOT GPIO_NUM_0

extern volatile bool FlagOfButtonPressed;

void key_init(void);
uint8_t key_get_state(void);

#endif // __KEY_H__