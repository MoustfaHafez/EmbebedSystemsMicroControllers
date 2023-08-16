/*
 * DIO_Interafce.h
 *
 * Created: 11/1/2022 2:38:18 PM
 *  Author: Admin
 */ 


#ifndef DIO_INTERAFCE_H_
#define DIO_INTERAFCE_H_

typedef enum
{
	OUTPUT,
	INFREE,
	INPULL	
}DIO_PinStatus_Type;


typedef enum
{
	PA,
	PB,
	PC,
	PD	
}DIO_PortName_Type;

typedef enum
{
	Low=0,
	High, 
}DIO_PinVoltage_Type;

typedef enum
{
	PINA0=0,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	PINTOTAL
	
}DIO_Pinnumber_Type;

 void DIO_VidInitPin(DIO_Pinnumber_Type pin ,DIO_PinStatus_Type Status);
 void DIO_VidWritePin(DIO_Pinnumber_Type pin,DIO_PinVoltage_Type volt);
 void DIO_VidTogglePin(DIO_Pinnumber_Type pin);
 DIO_PinVoltage_Type DIO_ReadPin(DIO_Pinnumber_Type pin);
 
 

#endif /* DIO_INTERAFCE_H_ */