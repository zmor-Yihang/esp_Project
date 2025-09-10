#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "led.h"
#include "uart.h"
#include <string.h>

void app_main(void)
{
    led_init();
    uart_init();

    bufferOfUartSend[0] = 'A';
    bufferOfUartSend[1] = 'B';
    bufferOfUartSend[2] = '\0';

    while (1)
    {
        uart_send_bytes(bufferOfUartSend); /* 发送字符串"AB"到串口 */

        uart_receive_bytes(bufferOfUartReceive); /* 从串口接收数据到缓冲区 */

        printf("\n%s\n", bufferOfUartReceive); /* 打印接收到的数据 */

        printf("hello world\n"); /* 打印调试信息 */
        led_toggle();            /* 切换LED状态 */
        vTaskDelay(1000);        /* 延时1000ms，控制循环执行频率 */
    }
}
