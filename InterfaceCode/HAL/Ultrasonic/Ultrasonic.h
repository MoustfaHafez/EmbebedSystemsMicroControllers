/*
 * Ultrasonic.h
 *
 * Created: 12/3/2022 1:50:44 PM
 *  Author: Admin
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#define F_CPU 8000000
#include <util/delay.h>

void ULTRASONIC_Init(void);
u8 ULTRASONIC_GetDistance(void);
static void Func_ICU(void);
static void Func_OVF(void);

#define Ultrasonic PINC5

#endif /* ULTRASONIC_H_ */