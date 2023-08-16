
#include "MacrosLikeFunction.h"
#include "MemoryMap.h"
#include "DIO_Interafce.h"
#include "STDTYPES.h"
#include "DIO_Private.h"
#include "DIO.h"



 void DIO_VidInitPin(DIO_Pinnumber_Type pin ,DIO_PinStatus_Type Status)
 {
	DIO_PortName_Type Port=pin/8;
	pin=pin%8;

	switch(Status)
	{
		
		case OUTPUT:
		{
			switch(Port)
			{
				case PA:
				SETBIT(DDRA,pin);
				RESETBIT(PORTA,pin);
				break;
				case PB:
				SETBIT(DDRB,pin);
				RESETBIT(PORTB,pin);
				break;
				case PC:
				SETBIT(DDRC,pin);
				RESETBIT(PORTC,pin);
				break;
				case PD:
				SETBIT(DDRD,pin);
				RESETBIT(PORTD,pin);
				break;				
			}
			
		}break;
		
		case INFREE:
		{
			switch(Port)
			{
				case PA:
				RESETBIT(DDRA,pin);
				RESETBIT(PORTA,pin);
				break;
				case PB:
				RESETBIT(DDRB,pin);
				RESETBIT(PORTB,pin);
				break;
				case PC:
				RESETBIT(DDRC,pin);
				RESETBIT(PORTC,pin);
				break;
				case PD:
				RESETBIT(DDRD,pin);
				RESETBIT(PORTD,pin);
				break;
			}	
		}break;
		
		case INPULL:
		{
			switch(Port)
			{
				case PA:
				RESETBIT(DDRA,pin);
				SETBIT(PORTA,pin);
				break;
				case PB:
				RESETBIT(DDRB,pin);
				SETBIT(PORTB,pin);
				break;
				case PC:
				RESETBIT(DDRC,pin);
				SETBIT(PORTC,pin);
				break;
				case PD:
				RESETBIT(DDRD,pin);
				SETBIT(PORTD,pin);
				break;
			}
		}break;
			
	}
	 
 }
 
void DIO_VidWritePin(DIO_Pinnumber_Type pin ,DIO_PinVoltage_Type volt)
{
	DIO_PortName_Type Port=pin/8;
	  pin=pin%8;
	
	switch(volt)
	{
		case Low:
		{
			switch(Port)
			{
				case PA:
				RESETBIT(PORTA,pin);
				break;
				case PB:
				RESETBIT(PORTB,pin);
				break;
				case PC:
				RESETBIT(PORTC,pin);
				break;
				case PD:
				RESETBIT(PORTD,pin);
				break;
				
			}
		}break;
		
		
		
		case High:
		{
			
			switch(Port)
			{
				case PA:
				SETBIT(PORTA,pin);
				break;
				case PB:
				SETBIT(PORTB,pin);
				break;
				case PC:
				SETBIT(PORTC,pin);
				break;
				case PD:
				SETBIT(PORTD,pin);
				break;
				
			}
			
			
		}break;
	}
}

void DIO_VidTogglePin(DIO_Pinnumber_Type pin_num)
{
	DIO_PortName_Type port=pin_num/8;
	u8 pin=pin_num%8;
	
	switch(port)
	{
		case PA:
		TOGGLEBIT(PORTA,pin);
		break;
		case PB:
		TOGGLEBIT(PORTB,pin);
		break;
		case PC:
		TOGGLEBIT(PORTC,pin);
		break;
		case PD:
		TOGGLEBIT(PORTD,pin);
		break;
	}
		
}

 
DIO_PinVoltage_Type DIO_LowHighReadPin(DIO_Pinnumber_Type pin)
{
	DIO_PortName_Type Port=pin/8;
	pin=pin%8;
	
	DIO_PinVoltage_Type Volt;
	switch( Port)
	{
		case PA:
		Volt=ReadPin(PINA,pin);
		break;
		case PB:
		Volt=ReadPin(PINB,pin);
		break;
		case PC:
		Volt=ReadPin(PINC,pin);
		break;
		case PD:
		Volt=ReadPin(PIND,pin);
		break;
	}
	return Volt;
}


void DIO_vidIntPort(DIO_PortName_Type port,u8 value)
{
	switch(port)
	{
		case PA:
		DDRA=value;
		break;
		case PB:
		DDRB=value;
		break;
		case PC:
		DDRC=value;
		break;
		case PD:
		DDRD=value;
		break;
	}
}
void DIO_VidWritePort(DIO_PortName_Type port,u8 value)
{
	switch(port)
	{
		case PA:
		PORTA=value;
		break;
		case PB:
		PORTB=value;
		break;
		case PC:
		PORTC=value;
		break;
		case PD:
		PORTD=value;
		break;
	}
}

void DIO_VidTogglePort(DIO_PortName_Type port)
{
	switch(port)
	{
		case PA:
		PORTA=PORTA^0xff;
		break;
		case PB:
		PORTB=PORTB^0xff;
		break;
		case PC:
		PORTC=PORTC^0xff;
		break;
		case PD:
		PORTD=PORTD^0xff;
		break;
	}
}

u8 DIO_u8ReadPort(DIO_PortName_Type port)
{
	u8 PortValue;
	switch(port)
	{
		case PA:
		PortValue=PINA;
		break;
		case PB:
		PortValue=PINB;
		break;
		case PC:
		PortValue=PINC;
		break;
		case PD:
		PortValue=PIND;
		break;
	}
	return PortValue;
}

void DIO_VidIntallPins()
{
	DIO_Pinnumber_Type i=PINA0;
	for(i=PINA0;i<PINTOTAL;i++)
	{
		DIO_VidInitPin(i,pinsStatusArr[i]);
	}
}


