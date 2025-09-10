#ifndef __LED_H__
#define __LED_H__

#include "driver/gpio.h"

// LED引脚定义
#define LED_PIN GPIO_NUM_1

// LED状态定义
#define LED_ON  0
#define LED_OFF 1

void led_init(void);

void led_on(void);

void led_off(void);

void led_toggle(void);

#endif /* __LED_H__ */
