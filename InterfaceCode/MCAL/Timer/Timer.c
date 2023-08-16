
#include "STDTYPES.h"
#include "MemoryMap.h"
#include "MacrosLikeFunction.h"
#include "Timer.h"

u16 static volatile t1,t2,t3,flag=0;

static void(*Ptr_TIMER0_OV)(void)=0;
static void(*Ptr_TIMER0_OC)(void)=0;

static void(*PtrTo_TIMER1_OVF)(void)=0;
static void(*PtrTo_TIMER1_OC1A)(void)=0;
static void(*PtrTo_TIMER1_OC1B)(void)=0;
static void(*PtrT0_TIMER1_ICU)(void)=0;


void TIMER0_Init(TTIMER0_Prescaler_Type Scaler,TIMER0_ModeOperation_Type Mode)
{
	
	
	switch(Mode)
	{
		case TIMER0_NormalMode:
		RESETBIT(TCCR0,WGM00);
		RESETBIT(TCCR0,WGM01);
		break;
		case TIMER0_PWM_PhaseCorrectMode:
		SETBIT(TCCR0,WGM00);
		RESETBIT(TCCR0,WGM01);
		break;
		case TIMER0_CTCMOde:
		RESETBIT(TCCR0,WGM00);
		SETBIT(TCCR0,WGM01);
		break;
		case TIMER0_FastPWMMode:
		SETBIT(TCCR0,WGM00);
		SETBIT(TCCR0,WGM01);
		break;	
	}	
	
	TCCR0&=0xF8;
	TCCR0|=Scaler;
	
}

void TIMER0_OV_InterruptEnable(void)
{
	SETBIT(TIMSK,TOIE0);// set overflow interrupt enable
}
void TIMER0_OV_InterruptDisable(void)
{
	RESETBIT(TIMSK,TOIE0);
}
void TIMER0_OC_InterruptEnable(void)
{
	SETBIT(TIMSK,OCIE0);
}
void TIMER0_OC_InterruptDisable(void)
{
	RESETBIT(TIMSK,OCIE0);
}


void TIMER0_OC0PinMode(OC0Mode_type OC0Mode)
{
	switch (OC0Mode)
	{
		case OCO_DISCONNECTED:
		RESETBIT(TCCR0,COM00);
		RESETBIT(TCCR0,COM01);
		break;
		case OCO_TOGGLE:
		SETBIT(TCCR0,COM00);
		RESETBIT(TCCR0,COM01);
		break;
		case OCO_NON_INVERTING:
		RESETBIT(TCCR0,COM00);
		SETBIT(TCCR0,COM01);
		break;		
		case OCO_INVERTING:
		SETBIT(TCCR0,COM00);
		SETBIT(TCCR0,COM01);
		break;
	}
}

void TIMER0_OV_SetCallBack(void(*LocalPtr)(void))
{
	Ptr_TIMER0_OV=LocalPtr;
}
void TIMER0_OC_SetCallBack(void (*LocalPtr) (void))
{
	Ptr_TIMER0_OC=LocalPtr;
}

ISR(TIMER0_OVF_vect)
{
	if(Ptr_TIMER0_OV!=0)
	{
		Ptr_TIMER0_OV();
	}
}

ISR(TIMER0_OC_vect)
{
	if(Ptr_TIMER0_OC!=0)
	{
		Ptr_TIMER0_OC();
	}
}
/*************************************************************************************/
void TIMER1_INIT(TIMER1_MODE_Type Mode,TIMER1_PRESCALER_type Scaler)
{
	switch (Mode)
	{
		case TIMER1_NORMALMODE:
		RESETBIT(TCCR1A,WGM10);
		RESETBIT(TCCR1A,WGM11);
		RESETBIT(TCCR1B,WGM12);
		RESETBIT(TCCR1B,WGM13);
		break;
		case TIMER1_CTCMODE_ICR1_TOP_MODE:
		RESETBIT(TCCR1A,WGM10);
		RESETBIT(TCCR1A,WGM11);
	    SETBIT(TCCR1B,WGM12);
		SETBIT(TCCR1B,WGM13);
		break;
		case TIMER1_CTCMODE_OCR1A_TOP_MODE:
		RESETBIT(TCCR1A,WGM10);
		RESETBIT(TCCR1A,WGM11);
		SETBIT(TCCR1B,WGM12);
		RESETBIT(TCCR1B,WGM13);
		break;
		case TIMER1_FASTPWM_ICR1_TOP_MODE:
		RESETBIT(TCCR1A,WGM10);
		SETBIT(TCCR1A,WGM11);
		SETBIT(TCCR1B,WGM12);
		SETBIT(TCCR1B,WGM13);
		break;
		case TIMER1_FASTPWM_OCR1A_TOP_MODE:
		SETBIT(TCCR1A,WGM10);
		SETBIT(TCCR1A,WGM11);
		SETBIT(TCCR1B,WGM12);
		SETBIT(TCCR1B,WGM13);
		break;
	}
	
	TCCR1B&=0XF8;
	TCCR1B|=Scaler;
	
}

void TIMER1_OC1A_Mode(TIMER1_OC1A_MODE_Type OC1A_MODE)
{
	switch(OC1A_MODE)
	{
		case TIMER1_OC1A_DisconnectedMode:
		RESETBIT(TCCR1A,COM1A0);
		RESETBIT(TCCR1A,COM1A1);
		break;
		case TIMER1_OC1A_TOGGLE_OC_Mode:
		SETBIT(TCCR1A,COM1A0);
		RESETBIT(TCCR1A,COM1A1);
		break;
		case TIMER1_OC1A_NONINVERTING_Mode:
		RESETBIT(TCCR1A,COM1A0);
		SETBIT(TCCR1A,COM1A1);
		break;
		case TIMER1_OC1A_INVERTING_Mode:
		SETBIT(TCCR1A,COM1A0);
		SETBIT(TCCR1A,COM1A1);
		break;		
	}
}
void TIMER1_OC1B_Mode(TIMER1_OC1B_MODE_Type OC1B_MODE)
{
	switch(OC1B_MODE)
	{
		case TIMER1_OC1B_DisconnectedMode:
		RESETBIT(TCCR1A,COM1B0);
		RESETBIT(TCCR1A,COM1B1);
		break;
		case TIMER1_OC1B_TOGGLE_OC_Mode:
		SETBIT(TCCR1A,COM1B0);
		RESETBIT(TCCR1A,COM1B1);
		break;
		case TIMER1_OC1B_NONINVERTING_Mode:
		RESETBIT(TCCR1A,COM1B0);
		SETBIT(TCCR1A,COM1B1);
		break;
		case TIMER1_OC1B_INVERTING_Mode:
		SETBIT(TCCR1A,COM1B0);
		SETBIT(TCCR1A,COM1B1);
		break;	
	}
}



void TIMER1_OVF_InterruptEnable()
{
	SETBIT(TIMSK,TOIE1);
}
void TIMER1_OVF_InterruptDisable()
{
	RESETBIT(TIMSK,TOIE1);
}
void TIMER1_OCA_InterruptEnable()
{
	SETBIT(TIMSK,OCIE1A);
}
void TIMER1_OCA_InterruptDisable()
{
	RESETBIT(TIMSK,OCIE1A);
}
void TIMER1_OCB_InterruptEnable()
{
	SETBIT(TIMSK,OCIE1B);
}
void TIMER1_OCB_InterruptDisable()
{
	RESETBIT(TIMSK,OCIE1B);
}

void TIMER1_ICU_InterruptEnable()
{
	SETBIT(TIMSK,TICIE1);
}

void TIMER1_ICU_InterruptDisable()
{
	RESETBIT(TIMSK,TICIE1);
}

void TIMER1_ICU_Trigger(ICU_Trigger_Type Mode)
{
	switch(Mode)
	{
		case Positive_Edge:
		SETBIT(TCCR1B,ICES1);
		break;
		case Negative_Edge:
		RESETBIT(TCCR1B,ICES1);
		break;
	}
}


 PWM_Measure(u32* Pfreq,u8* Pduty)
 {
	 u16 Ton,Toff;
	 TCNT1=0;
	 TIMER1_ICU_SetCallBack(&Func_ICU);
	 TIMER1_ICU_Trigger(Positive_Edge);
	 TIMER1_ICU_InterruptEnable();
	 flag=0;
	 while(flag<3);
	 Ton=t2-t1;
	 Toff=t3-t2;
	 *Pduty=((u32)Ton*100)/((u32)Ton+Toff);
	 *Pfreq=(u32)1000000/((u32)Toff+Ton); 
	 
 }
 
 void Func_ICU(void)
{
	if(flag==0)
	{
		t1=ICR1;
		TIMER1_ICU_Trigger(Negative_Edge);
		flag=1;
	}
	if(flag==1)
	{
		t2=ICR1;
		TIMER1_ICU_Trigger(Positive_Edge);
		flag=2;
	}
	if(flag==2)
	{
		t3=ICR1;
		TIMER1_ICU_InterruptDisable();
		flag=3;
	}
}

/****************************Timer 1 Interrupt functions**************************************/

void TIMER1_OVF_SetCallBack(void(*LocalFptr)(void))
{
	PtrTo_TIMER1_OVF=LocalFptr;
}
void TIMER1_OC1A_SetCallBack(void (*LocalFptr)(void))
{
	PtrTo_TIMER1_OC1A=LocalFptr;
}
void TIMER1_OC1B_SetCallBack(void(*LocalFptr)(void))
{
	PtrTo_TIMER1_OC1B=LocalFptr;
}

void TIMER1_ICU_SetCallBack(void (*ptr)(void))
{
	PtrT0_TIMER1_ICU=ptr;
}

ISR(TIMER1_OVF_vect)
{
	if(PtrTo_TIMER1_OVF!=0)
	{
		PtrTo_TIMER1_OVF();
	}
}

ISR(TIMER1_OCA_vect)
{
	if(PtrTo_TIMER1_OC1A!=0)
	{
		PtrTo_TIMER1_OC1A();
	}
}

ISR(TIMER1_OCB_vect)
{
	if(PtrTo_TIMER1_OC1B !=0)
	{
		PtrTo_TIMER1_OC1B();
	}
}

ISR(TIMER1_ICU_vect)
{
	if(PtrT0_TIMER1_ICU!=0)
	{
		PtrT0_TIMER1_ICU();
	}
}