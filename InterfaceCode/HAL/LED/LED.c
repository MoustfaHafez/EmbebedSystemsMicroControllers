
#include "STDTYPES.h"
#include "DIO_Interafce.h"
#include "LED.h"
#include "LED_Cfg.h"


void LEDON(DIO_Pinnumber_Type  PIN)
{
	DIO_VidWritePin(PIN,High);
}

void LEDOFF(DIO_Pinnumber_Type PIN)
{
	DIO_VidWritePin(PIN,Low);
}