#include "uart.h"

/* UART接收缓冲区 */
uint8_t bufferOfUartReceive[lengthOfUartReceive] = {0};

/* UART发送缓冲区 */
uint8_t bufferOfUartSend[lengthOfUartSend] = {0};


/**
 * @brief UART串口初始化函数
 * @details 配置并初始化UART0串口，设置通信参数和引脚映射
 * @note 函数内部会自动分配内存创建环形缓冲区
 */
void uart_init(void) /* UART串口初始化函数 */
{
    uart_config_t uart_config = {0}; /* 创建UART配置结构体并初始化为0 */

    uart_config.baud_rate = 115200;                   /* 设置波特率为115200 */
    uart_config.data_bits = UART_DATA_8_BITS;         /* 设置数据位为8位 */
    uart_config.stop_bits = UART_STOP_BITS_1;         /* 设置停止位为1位 */
    uart_config.parity = UART_PARITY_DISABLE;         /* 设置校验位：无校验 */
    uart_config.source_clk = UART_SCLK_APB;           /* 设置时钟源为APB时钟 */
    uart_config.flow_ctrl = UART_HW_FLOWCTRL_DISABLE; /* 关闭硬件流控 */
    uart_config.rx_flow_ctrl_thresh = 0;              /* 设置接收流控阈值（流控关闭时不生效） */

    uart_param_config(UART_NUM_0, &uart_config); /* 将配置结构体参数传入UART0初始化函数 */

    /* 设置UART0的引脚 */
    uart_set_pin(UART_NUM_0, GPIO_NUM_43, GPIO_NUM_44, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);

    /* 该函数内部会自动调用 heap_caps_malloc() 等函数分配内存，创建环形缓冲区 */
    uart_driver_install(UART_NUM_0, 512, 512, 20, NULL, 0);
}

/**
 * @brief UART发送字节函数
 * @details 通过UART0端口发送指定缓冲区中的数据
 * 
 * @param buffer 指向要发送数据的缓冲区指针，数据必须以'\0'结尾
 * @note 发送的数据长度由strlen()函数计算得出
 * @note 函数会阻塞直到所有数据发送完成
 */
void uart_send_bytes(uint8_t *buffer) /* UART发送函数 */
{
    uart_write_bytes(UART_NUM_0, (char *)buffer, strlen((char *)buffer));
}

/**
 * @brief UART接收字节函数
 * @param[out] buffer 指向接收数据缓冲区的指针，用于存储接收到的数据
 * @return int 实际接收到的字节数
 * @note 接收数据之前会清空接收缓冲区
 * @note 函数会自动在接收到的数据末尾添加字符串结束符'\0'
 */
int uart_receive_bytes(uint8_t *buffer) /* UART接收函数 */
{
    memset(bufferOfUartReceive, 0, lengthOfUartReceive);       /* 清空接收缓冲区，全部填充为0 */
    int bytes_read = uart_read_bytes(UART_NUM_0, (char *)buffer, lengthOfUartReceive - 1, 1000);

    if (bytes_read > 0)
    {
        buffer[bytes_read] = '\0'; // 添加字符串结束符
    }
    return bytes_read;
}