#include "key.h"

void key_init(void)
{
    gpio_config_t io_conf = {0};

    io_conf.intr_type = GPIO_INTR_DISABLE; // 禁用中断
    io_conf.mode = GPIO_MODE_INPUT; // 设置为输入模式
    io_conf.pin_bit_mask = (1ULL << KEY_BOOT); // 配置KEY0引脚
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE; // 禁用下拉
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE; // 启用上拉
    gpio_config(&io_conf); // 初始化
}

void key_pressed(void)
{
    // 处理按键按下事件
    int current_level = gpio_get_level(KEY_BOOT);
    printf("Key Pressed - KEY_BOOT Level: %d\n", current_level);
}

