
#include "STDTYPES.h"
#include "ADC.h"
#include "Sensors.h"
#include "Sensors_cfg.h"


u16 Temp_Read(void)
{
	u16 volt=ReadVolt(LM35_H);
	u16 Temp=volt ;
	return Temp;
}

u16 MPX415SmokeeRead()
{
	u16 Adc=ADCRead(MPX415);
	u16 Pressure=(1000*((u32)Adc-55))/(921)+150;
	return Pressure;
}

u16 MPX415ADCRead()
{
	u16 Adc=ADCRead(MPX415);
	return Adc;
}