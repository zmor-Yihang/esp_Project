#include "key.h"

volatile bool FlagOfButtonPressed = false;

static void IRAM_ATTR gpio_isr_handler(void* arg)
{
    FlagOfButtonPressed = true;  // 置中断标志
}

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

uint8_t key_get_state(void)
{
    return gpio_get_level(KEY_BOOT);
}
