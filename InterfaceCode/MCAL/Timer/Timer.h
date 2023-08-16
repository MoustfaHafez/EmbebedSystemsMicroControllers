

#ifndef TIMER_H_
#define TIMER_H_
#include "MemoryMap.h"
typedef enum
{
	TIMER0_STOP=0,
	TIMER0_SCALAR_1,
	TIMER0_SCALAR_8,
	TIMER0_SCALAR_64,
	TIMER0_SCALAR_256,
	TIMER0_SCALAR_1024,
	TIMER0_ExClockOnFallingEdge,
	TIMER0_ExClockOnRaisingEdge	
}TTIMER0_Prescaler_Type;

typedef enum
{
	TIMER0_NormalMode=0,
	TIMER0_PWM_PhaseCorrectMode,
	TIMER0_CTCMOde,
	TIMER0_FastPWMMode,	
}TIMER0_ModeOperation_Type;

typedef enum
{
	OCO_DISCONNECTED=0,
	OCO_TOGGLE,
	OCO_NON_INVERTING,
	OCO_INVERTING
}OC0Mode_type;

void TIMER0_Init(TTIMER0_Prescaler_Type Scaler,TIMER0_ModeOperation_Type Mode);
void TIMER0_OV_InterruptEnable(void);
void TIMER0_OV_InterruptDisable(void);
void TIMER0_OC_InterruptEnable(void);
void TIMER0_OC_InterruptDisable(void);
void TIMER0_OC0PinMode(OC0Mode_type OC0Mode);
void TIMER0_OC_SetCallBack(void (*LocalPtr) (void));
void TIMER0_OV_SetCallBack(void(*LocalPtr)(void));



#define TIMER0_Read()              TCNT0
#define TIMER0_SET_TCNT0(value)    TCNT0=value
#define TIMER0_SET_OCR0(value)     OCR0=value

/*****************************************************/

typedef enum{
	TIMER1_STOP=0,
	TIMER1_SCALER_1,
	TIMER1_SCALER_8,
	TIMER1_SCALER_64,
	TIMER1_SCALER_256,
	TIMER1_SCALER_1024,
	EXTERNAL0_FALLING,
	EXTERNAL0_RISING
}TIMER1_PRESCALER_type;

typedef enum
{
	TIMER1_NORMALMODE=0,
	TIMER1_CTCMODE_OCR1A_TOP_MODE=4,
	TIMER1_CTCMODE_ICR1_TOP_MODE=12,
	TIMER1_FASTPWM_ICR1_TOP_MODE=14,
	TIMER1_FASTPWM_OCR1A_TOP_MODE=15
	
}TIMER1_MODE_Type;


typedef enum
{
	TIMER1_OC1A_DisconnectedMode=0,
	TIMER1_OC1A_TOGGLE_OC_Mode,
	TIMER1_OC1A_NONINVERTING_Mode,
	TIMER1_OC1A_INVERTING_Mode,
	
}TIMER1_OC1A_MODE_Type;

typedef enum
{
	TIMER1_OC1B_DisconnectedMode=0,
	TIMER1_OC1B_TOGGLE_OC_Mode,
	TIMER1_OC1B_NONINVERTING_Mode,
	TIMER1_OC1B_INVERTING_Mode,

}TIMER1_OC1B_MODE_Type;

typedef enum
{
	Positive_Edge,
	Negative_Edge
}ICU_Trigger_Type;


void TIMER1_INIT(TIMER1_MODE_Type Mode,TIMER1_PRESCALER_type Scaler);
void TIMER1_OC1A_Mode(TIMER1_OC1A_MODE_Type OC1A_MODE);
void TIMER1_OC1B_Mode(TIMER1_OC1B_MODE_Type OC1B_MODE);
void TIMER1_OVF_InterruptEnable();
void TIMER1_OVF_InterruptDisable();
void TIMER1_OCA_InterruptEnable();
void TIMER1_OCA_InterruptDisable();
void TIMER1_OCB_InterruptEnable();
void TIMER1_OCB_InterruptDisable();
void TIMER1_ICU_InterruptEnable();
void TIMER1_ICU_InterruptDisable();
void TIMER1_ICU_Trigger(ICU_Trigger_Type Mode);
void TIMER1_ICU_SetCallBack(void (*ptr)(void));
void PWM_Measure(u32* Pfreq,u8* Pduty);
static void Func_ICU(void);

#define TIMER1_READ()                   TCNT1 
#define TIMER1_SETStartingTime(value)   TCNT1=value;
#define TIMER1_Set_OCR1A(value)         OCR1A=value
#define TIMER1_Set_OCR1B(value)         OCR1B=value
#define TIMER1_Set_ICR1(value)          ICR1=value

void TIMER1_OVF_SetCallBack(void(*LocalFptr)(void));
void TIMER1_OC1A_SetCallBack(void (*LocalFptr)(void));
void TIMER1_OC1B_SetCallBack(void(*LocalFptr)(void));
void TIMER1_ICU_SetCallBack(void (*ptr)(void));

#endif 