

#include "STDTYPES.h"
#include "Timer.h"
#include "MemoryMap.h"
#include "MacrosLikeFunction.h"

static volatile GeneralTime=1;

u8 volatile static c=0,TimerFlag=0;

static void (*Gptr)(void)=0;

void PWM_Init(void)
{
	TIMER1_INIT(TIMER1_FASTPWM_OCR1A_TOP_MODE,TIMER1_SCALER_8);
	TIMER1_OC1B_Mode(TIMER1_OC1B_NONINVERTING_Mode);
}
void PWM_Freq_KHZ(u16 freq)
{
	
	if(freq==0);
	else
	{
	  u16 Ttotal=1000/freq;//Micro seconds
	  if(Ttotal>=1)
	  {
		  OCR1A=Ttotal-1;
	  }
	  else
	  {
		  OCR1A=0;
	  }
	}
}
void PWM_Freq_HZ(u16 freq)
{
	
	if(freq==0);
	else
	{
		u16 Ttotal=(u32)1000000/freq;
		if(Ttotal>=1)
		{
			OCR1A=Ttotal-1;
		}
		else
		{
			OCR1A=0;
		}
	}
}

void PWM_Duty(u16 duty)
{
	 if (duty<=100)
	 {
		 u16 Ton=((u32)duty*(OCR1A+1))/100;
		 if (Ton>1)
		 {
			 OCR1B=Ton-1;
		 }
		 else
		 OCR1B=0;
	 }
}

void PWM_Frehz_DutyCycle(u16 fre,u16 Dutycycle)
{
	PWM_Freq_HZ(fre);
	PWM_Duty(Dutycycle);
}

void Timer1_SetInterruptTime_ms (u16 time,void(*LocalFptr)(void))
{
	TIMER1_INIT(TIMER1_FASTPWM_OCR1A_TOP_MODE,TIMER1_SCALER_8);
	TIMER1_OC1B_Mode(TIMER1_OC1B_NONINVERTING_Mode);
	OCR1A=((u16)1000*time)-1;
	TIMER1_OVF_SetCallBack(LocalFptr);
	TIMER1_OVF_InterruptEnable();	
}
void Timer1_SetInterruptTime_us (u16 time,void(*LocalFptr)(void))
{
	TIMER1_INIT(TIMER1_FASTPWM_OCR1A_TOP_MODE,TIMER1_SCALER_8);
	TIMER1_OC1B_Mode(TIMER1_OC1B_NONINVERTING_Mode);
	OCR1B= time-1;
	TIMER1_OVF_SetCallBack(LocalFptr);
	TIMER1_OVF_InterruptEnable();
}

void DelayTimeSec(void)
{
	c++;
	if(c==(30*GeneralTime))
	{
		TimerFlag=1;
		c=0;
	}
}
void TIMER0_IntSevice(void)
{
	TIMER0_Init(TIMER0_SCALAR_1024,TIMER0_NormalMode);
	TCNT0=128;
	TIMER0_OV_InterruptEnable();
}

void TIMER0_DelayOnSec(u8 time,void (*ptr)(void))
{
	GeneralTime=time;
	TIMER0_OV_SetCallBack(&DelayTimeSec);
	if(TimerFlag==1)
	{
		ptr();
		TimerFlag=0;
	}
}
