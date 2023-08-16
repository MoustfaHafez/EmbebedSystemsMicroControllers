/*
 * UARTService.h
 *
 * Created: 12/10/2022 4:47:18 PM
 *  Author: Admin
 */ 


#ifndef UARTSERVICE_H_
#define UARTSERVICE_H_

u32   UART_ReadNumber1(void);
u32   UART_ReadNumber(void);
void  UART_WriteNumber(u32 num);
void  UART_VoidReadString(u8 *str);
void  UART_VoidWriteString(char *str);


#endif /* UARTSERVICE_H_ */