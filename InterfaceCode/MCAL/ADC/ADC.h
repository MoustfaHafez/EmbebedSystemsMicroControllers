


#ifndef ADC_H_
#define ADC_H_

#define VREF  5000    //VOLT

typedef enum
{
	VREF_AREF,
	VREF_VCC,
	VREF_256
}ADC_voltRef_Type;

typedef enum
{
	ADC_SCALER_2=1,
	ADC_SCALER_4,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128,
	
}ADC_Prescaler_Type;

typedef enum{
	CH_0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7
}ADC_Channel_type;

void ADCInit(ADC_voltRef_Type Ref,ADC_Prescaler_Type Prescaler);

u16 ADCRead(ADC_Channel_type Ch);

u16 Readpotentiometer(ADC_Channel_type ch);

u16 ReadVolt(ADC_Channel_type ch);


#endif /* ADC_H_ */