/*
 * uart.h
 *
 *  Created on: Apr 19, 2024
 *      Author: msi
 */

#ifndef INC_UART_H_
#define INC_UART_H_

void usart_3_config();
char uart_read();
void usart_send_char(char a );
void usart_send_text(char* txt);



#endif /* INC_UART_H_ */
