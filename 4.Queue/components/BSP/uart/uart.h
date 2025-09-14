#ifndef __UART_H__
#define __UART_H__

#include "driver/uart.h"
#include "driver/gpio.h"
#include <string.h>

/* UART接收缓冲区长度 */
#define lengthOfUartReceive 64

/* UART发送缓冲区长度 */
#define lengthOfUartSend 64

/* UART接收缓冲区 */
extern uint8_t bufferOfUartReceive[lengthOfUartReceive];

/* UART发送缓冲区 */
extern uint8_t bufferOfUartSend[lengthOfUartSend];

void uart_init(void);

void uart_send_bytes(uint8_t *sendBuffer);

int uart_receive_bytes(uint8_t *receiveBuffer);

#endif /* __UART_H__ */
