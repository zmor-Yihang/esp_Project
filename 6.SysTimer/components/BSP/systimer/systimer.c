#include "systimer.h"

/* 系统定时器句柄 */
esp_timer_handle_t systimer_handle = NULL;

/**
 * @brief 定时器回调函数
 * @details 当定时器到期时调用此函数。
 * @param arg 指向传入数据的指针
 */
static void systimer_callback(void* arg)
{
    // Timer callback function
    printf("Timer callback executed\n");
    led_toggle();
}

/**
 * @brief 初始化系统定时器
 * @details 定时器配置为在任务上下文中运行，不跳过未处理的事件。
 */
void systimer_init(void)
{
    esp_timer_create_args_t create_args = {0};

    create_args.callback = systimer_callback;
    create_args.arg = NULL;
    create_args.name = "systimer";
    create_args.dispatch_method = ESP_TIMER_TASK;
    create_args.skip_unhandled_events = false;

    esp_timer_create(&create_args, &systimer_handle);
}

/**
 * @brief 启动定时器进行一次执行
 * @param timeout 超时时间（毫秒）
 */
void systimer_start_once(int timeout)
{
    esp_timer_start_once(systimer_handle, timeout * 1000);
}

/**
 * @brief 启动定时器进行周期性执行
 * @param period 定时器执行间隔（毫秒）
 */
void systimer_start_period(int period)
{
    esp_timer_start_periodic(systimer_handle, period * 1000);
}

/**
 * @brief 停止系统定时器
 */
void systimer_stop(void)
{
    esp_timer_stop(systimer_handle);
}