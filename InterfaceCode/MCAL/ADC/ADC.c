
#include "STDTYPES.h"
#include "MemoryMap.h"
#include "MacrosLikeFunction.h"
#include "ADC.h"

void ADCInit(ADC_voltRef_Type Ref,ADC_Prescaler_Type Prescaler)
{
	
	//PRESCALER
 	 ADCSRA&=0XF8;
	 ADCSRA|=Prescaler;
	 
	 //READ ADJUSTMENT 
	 
	 RESETBIT(ADMUX,ADLAR);
	 
	// Vref 
	switch (Ref)
	{
		case VREF_AREF:
		RESETBIT(ADMUX,REFS0);
		RESETBIT(ADMUX,RESF1);
		break;
		case VREF_VCC:
		SETBIT(ADMUX,REFS0);
		RESETBIT(ADMUX,RESF1);
		break;
		case VREF_256:
		SETBIT(ADMUX,REFS0);
		SETBIT(ADMUX,RESF1);
		break;	
	}
	
	SETBIT(ADCSRA,ADEN);/// ENABLE ADC
	
}

u16 ADCRead(ADC_Channel_type ch)
{
	u16 value;
	ADMUX&=0XE0;
	ADMUX|=ch;
	SETBIT(ADCSRA,ADSC);//START CONVERSION
	while(ReadPin(ADCSRA,ADSC));	//BUSY WAIT
	//value=ADCH<<8 | ADCL
	value=ADC;
	return value;
}

u16 Readpotentiometer(ADC_Channel_type ch)
{
	u16 Adc=ADCRead(ch);
	u16 potentiometer=(((u32)Adc*100)/(1023));
	return potentiometer;
}

u16 ReadVolt(ADC_Channel_type ch)
{
	u16 Adc=ADCRead(ch);
	u16 Volt=(((u32)Adc*VREF)/1023);///mv
	return Volt;
}


