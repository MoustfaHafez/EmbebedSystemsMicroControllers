


#ifndef UART_H_
#define UART_H_



void  UART_VoidInit(void);
void  UART_VoidWriteDataChar(u8 data);
u8    UART_U8ReadData(void);
u8    UART_ReadDataPeriodicCheck(u8 *pdata);
void  UART_RXComplete_InterruptEnable();
void  UART_RXComplete_InterruptDisable();
void  UART_TXComplete_InterruptEnable();
void  UART_TXComplete_InterruptDisable();






#endif /* UART_H_ */