#include "uart.h"
#include "stm32f407xx.h"
#include "stdio.h"

void usart_3_config() {
	RCC->AHB1ENR |=(1<<2);    //clock for GPIOC
	RCC->APB1ENR |=(1<<18);   //clock for USART3
	GPIOC->MODER |=(1<<21);   //PC10 as AF
	GPIOC->MODER |=(1<<23);   //PC11 as AF
	GPIOC->AFR[1] |=(0x7<<8);
	GPIOC->AFR[1] |=(0x7<<12);
	USART3->BRR =0x341;       //baudrate=9600
	USART3->CR1 |=(1<<13);    //enable the USART3
	USART3->CR1 |=(1<<3);     //RX enable

}

char uart_read(void) {
	while( !(USART3->SR & (1<<5)) );//make sure the receive data register is not empty
	return USART3->DR;
}

void usart_send_char(char a) {
	while( ! (USART3->SR & (1<<7)) );//wait for the TX buffer to be emtpy
	USART3->DR = a;
	while( ! (USART3->SR & (1<<6)) );//wait for the transmission to be completed
}


void usart_send_text(char* txt) {
	while(*txt) {
		usart_send_char(*txt);
		txt++;
	}
}
