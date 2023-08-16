
#include "MOVE.h"
#include "DIO_Interafce.h"
#include "Motor_Interface.h"


void MOVE_Init(void)
{
	//do nothing
}

void Move_Runable(void)
{
	if(DIO_LowHighReadPin(Forward_PB)==Low)
	{
		MoveForward();
	}
	if(DIO_LowHighReadPin(Back_PB)==Low)
	{
		MoveBack();
	}
	if(DIO_LowHighReadPin( Right_PB)==Low)
	{
		MoveRight();
		while(DIO_LowHighReadPin( Right_PB)==Low);
		MoveStop();
	}
	if(DIO_LowHighReadPin( Left_PB)==Low)
	{
		Moveleft();
		while(DIO_LowHighReadPin( Left_PB)==Low);
		MoveStop();
	}
}

void MoveForward(void)
{
	MotorCw(FRONT_LEFT);
	MotorCw(FRONT_RIGHT);
	MotorCw(BACK_LEFT);
	MotorCw(BACK_RIGHT);
}

void MoveBack(void)
{
	MotorCCw(FRONT_LEFT);
	MotorCCw(FRONT_RIGHT);
	MotorCCw(BACK_LEFT);
	MotorCCw(BACK_RIGHT);
}
///Need to change name of motors
void Moveleft(void)
{
	MotorCCw(FRONT_LEFT);
	MotorCCw(FRONT_LEFT);
	MotorCw(FRONT_LEFT);
	MotorCw(FRONT_LEFT);
}
///Need to change name of motors
void MoveRight(void)
{
	MotorCw(FRONT_LEFT);
	MotorCw(FRONT_LEFT);
	MotorCw(FRONT_LEFT);
	MotorCw(FRONT_LEFT);

}

void MoveStop(void)
{
	MotorStop(FRONT_LEFT);
	MotorStop(FRONT_RIGHT);
	MotorStop(BACK_LEFT);
	MotorStop(BACK_RIGHT);	
}