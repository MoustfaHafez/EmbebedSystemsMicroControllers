/*
 * Motor_Interface.h
 *
 * Created: 11/5/2022 2:35:16 PM
 *  Author: Admin
 */ 


#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_

#include "DIO_Interafce.h"
#include "Motor_cfg.h"
typedef enum
{
	M1,
	M2,
	M3,
	M4
}MOTOR_Type;

void MotorStop(MOTOR_Type motor);
void MotorCw(MOTOR_Type motor);
void MotorCCw(MOTOR_Type motor);

void MotorOn ();
void MotorOFF();
void HeaterOFF();
void HeaterON();
void OutletValveClose();
void OutletValveOpen();
void InletValveClose();
void InletValveOpen();



#endif /* MOTOR_INTERFACE_H_ */