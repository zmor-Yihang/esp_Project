#include "key.h"

/* 按键中断标志 */
volatile bool FlagOfButtonPressed = false;

/**
 * @brief GPIO中断服务程序, 仅设置中断标志位
 * 
 * @param arg 
 */
static void IRAM_ATTR gpio_isr_handler(void* arg)
{
    FlagOfButtonPressed = true;  // 置中断标志
}

/**
 * @brief 按键初始化
 * @note  配置KEY0引脚为输入模式, 上拉, 下降沿中断，
 * 
 */
void key_init(void)
{
    gpio_config_t io_conf = {0};

    io_conf.pin_bit_mask = (1ULL << KEY_BOOT);    // 配置KEY0引脚
    io_conf.mode = GPIO_MODE_INPUT;               // 设置为输入模式
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;      // 启用上拉
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE; // 禁用下拉
    io_conf.intr_type = GPIO_INTR_NEGEDGE;        // 启用中断
    gpio_config(&io_conf);                        // 初始化GPIO

    gpio_install_isr_service(0);                  // 安装GPIO中断服务, 相当于使能NVIC [HAL_NVIC_EnableIRQ(EXTI0_IRQn)]

    gpio_isr_handler_add(KEY_BOOT, gpio_isr_handler, (void *)KEY_BOOT); // 注册中断处理函数
}

/**
 * @brief 获取按键状态
 * @note  按键消抖在主循环中处理
 * @return uint8_t 按键状态, 0表示按下, 1表示未按下
 */
uint8_t key_get_state(void)
{
    return gpio_get_level(KEY_BOOT);
}
