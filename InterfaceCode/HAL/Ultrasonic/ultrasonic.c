
#include "STDTYPES.h"
#include "Timer.h"
#include "DIO_Interafce.h"
#include "Ultrasonic.h"

static volatile u16 t1,t2,flag=0,c=0;

void ULTRASONIC_Init(void)
{
	TIMER1_INIT(TIMER1_NORMALMODE,TIMER1_SCALER_8);
	TIMER1_ICU_SetCallBack(&Func_ICU);	
	TIMER1_OVF_SetCallBack(&Func_OVF);	
}

u8 ULTRASONIC_GetDistance()
{
	u8 distance;
	u16 time;
	flag=0;
	DIO_VidWritePin(Ultrasonic,High);
	_delay_us(10);
	DIO_VidWritePin(Ultrasonic,Low);
	TIMER1_ICU_Trigger(Positive_Edge);
	TIMER1_ICU_InterruptEnable();
	TIMER1_OVF_InterruptEnable();
	while (flag<2);
	time=(t2-t1)+((u32)c*65535);
	distance=time/58;
	TIMER1_ICU_InterruptDisable();
	return distance;
}

static void Func_ICU(void)
{
	if(flag==0)
	{
		c=0;
		t1=ICR1;
		TIMER1_ICU_Trigger(Negative_Edge);
		flag=1;
	}
	else if(flag==1)
	{
		t2=ICR1;
		TIMER1_ICU_Trigger(Positive_Edge);
		TIMER1_ICU_InterruptDisable();
		TIMER1_OVF_InterruptDisable();
		flag=2;
	}
}

static void Func_OVF(void)
{
	c++;
}