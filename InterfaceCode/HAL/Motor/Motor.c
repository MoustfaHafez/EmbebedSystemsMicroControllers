
#include "Motor_Interface.h"
#include "STDTYPES.h"
#include "DIO_Interafce.h"
#include "Motor_cfg.h"
#include "Motor_Private.h"


void MotorStop(MOTOR_Type motor)
{
	switch(motor)
	{
		case M1:
		DIO_VidWritePin(M1_IN1,Low);
		DIO_VidWritePin(M1_IN2,Low);
		break;
		
		case M2:
		DIO_VidWritePin(M2_IN1,Low);
		DIO_VidWritePin(M2_IN2,Low);
		break;
		
		case M3:
		DIO_VidWritePin(M3_IN1,Low);
		DIO_VidWritePin(M3_IN2,Low);
		break;
		
		case M4:
		DIO_VidWritePin(M4_IN1,Low);
		DIO_VidWritePin(M4_IN2,Low);
		break;
	}
}
void MotorCw(MOTOR_Type motor)
{
	DIO_VidWritePin(MotorPinsArray[motor][EN1],Low);
	DIO_VidWritePin(MotorPinsArray[motor][EN2],High);	
}
void MotorCCw(MOTOR_Type motor)
{
	DIO_VidWritePin(MotorPinsArray[motor][EN1],High);
	DIO_VidWritePin(MotorPinsArray[motor][EN2],Low);
}

void MotorOn()
{
	DIO_VidWritePin(Motor,High);
}

void MotorOFF()
{
	DIO_VidWritePin(Motor,Low);
}
/**********************************************/
void HeaterON()
{
	DIO_VidWritePin(HEATER,High);
}
void HeaterOFF()
{
	DIO_VidWritePin(HEATER,Low);
}
/***************************************/
void InletValveOpen()
{
	DIO_VidWritePin(InletValve,High);
}
void InletValveClose()
{
	DIO_VidWritePin(InletValve,Low);
}
/**************************************/
void OutletValveOpen()
{
	DIO_VidWritePin(OutletValve,High);
}
void OutletValveClose()
{
	DIO_VidWritePin(OutletValve,Low);
}