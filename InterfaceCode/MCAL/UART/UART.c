

#include "STDTYPES.h"
#include "MemoryMap.h"
#include "MacrosLikeFunction.h"
#include "UART.h"


static void(*UART_RX_Fptr)(void)=0;
static void(*UART_TX_Fptr)(void)=0;

void  UART_VoidInit(void)
{
	UBRRL=51;	          //BUADRate 9600
	RESETBIT(UCSRA,U2X);  //normal  Speed 
	//default frame data length 8 bit parity bit none no of stop bit is 1
	SETBIT(UCSRB,TXEN);// enable transmitter TX
	SETBIT(UCSRB,RXEN);// enable Receiver    Rt	
}

void  UART_VoidWriteDataChar(u8 data)
{
	while(ReadPin(UCSRA,UDRE)==0);// if UDRE ==0 buffer is full wait unit become empty
	UDR=data;
}


u8 UART_U8ReadData(void)
{
	while(ReadPin(UCSRA,RXC)==0); // if RXC ==0 BUFFER IS EMPTY NO DATA Wait till become have data RXC=1;
	return UDR;
}

u8 UART_ReadDataPeriodicCheck(u8 *pdata)
{
	if(ReadPin(UCSRA,RXC)==1)
	{
	   *pdata=UDR;
		return 1;
	}
	return 0;
}


/*********************************************************/
void UART_RXComplete_InterruptEnable()
{
	SETBIT(UCSRB,RXCIE);
}
void UART_RXComplete_InterruptDisable()
{
	RESETBIT(UCSRB,RXCIE);
}
void UART_TXComplete_InterruptEnable()
{
	SETBIT(UCSRB,TXCIE);
}
void UART_TXComplete_InterruptDisable()
{
	RESETBIT(UCSRB,TXCIE);
}


void UART_SendByteNoBlock(u8 data)
{
	UDR = data;
}

u8 UART_ReceiveByteNoBlock(void)
{
	return UDR;
}

void UART_RXCIE_SetCallBack(void(*ptr)(void))
{
	UART_RX_Fptr=ptr;
}
void UART_TXCIE_SetCallBack(void(*ptr)(void))
{

	UART_TX_Fptr=ptr;
}

ISR(USART_RXC_vect)
{
	if(UART_RX_Fptr!=0)
	{
		UART_RX_Fptr();
	}
}

/*ISR(USART_TXC_vect)
{
	if(UART_TX_Fptr!=0)
	{
		UART_TX_Fptr();
	}
}*/

