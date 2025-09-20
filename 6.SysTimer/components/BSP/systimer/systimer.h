#ifndef __SYSTIMER_H__
#define __SYSTIMER_H__

#include "esp_timer.h"
#include "led.h"

extern esp_timer_handle_t systimer_handle;

void systimer_init(void);
void systimer_start_once(int timeout);
void systimer_start_period(int period);
void systimer_stop(void);


#endif // __SYSTIMER_H__
