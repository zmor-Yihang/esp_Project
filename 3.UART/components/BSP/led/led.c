#include "led.h"

/**
 * @brief LED初始化
 * @param None
 * @retval None
 */
void led_init(void)
{
    gpio_config_t io_conf = {0};

    io_conf.intr_type = GPIO_INTR_DISABLE; // 禁用中断
    io_conf.mode = GPIO_MODE_INPUT_OUTPUT; // 设置为输出模式
    io_conf.pin_bit_mask = (1ULL << LED_PIN); // 配置LED引脚
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE; // 禁用下拉
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE; // 禁用上拉
    gpio_config(&io_conf); // 初始化

    led_off(); // 初始化时关闭LED
}

/**
 * @brief LED开启
 * @param None
 * @retval None
 */
void led_on(void)
{
    gpio_set_level(LED_PIN, LED_ON);
}

/**
 * @brief LED关闭
 * @param None
 * @retval None
 */
void led_off(void)
{
    gpio_set_level(LED_PIN, LED_OFF);
}

/**
 * @brief LED状态切换
 * @param None
 * @retval None
 */
void led_toggle(void)
{
    gpio_set_level(LED_PIN, !gpio_get_level(LED_PIN));
}
