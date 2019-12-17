/*
 * UART.h
 *
 *  Created on: Dec 1, 2019
 *      Author: crist
 */

#ifndef UART_H_
#define UART_H_


void config_UART();


void UART_1byte(uint8_t data);

void UART_send(uint8_t * data, uint32_t lenght);

void LCD_reset();

uint16_t IRread();


#endif /* UART_H_ */
