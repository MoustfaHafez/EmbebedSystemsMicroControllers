


#ifndef TIMER_SERVICE_H_
#define TIMER_SERVICE_H_

void PWM_Init(void);
void PWM_Freq_KHZ(u16 freq);
void PWM_Freq_HZ(u16 freq);
void PWM_Duty(u16 duty);

void Timer1_SetInterruptTime_ms (u16 time,void(*LocalFptr)(void));
void Timer1_SetInterruptTime_us (u16 time,void(*LocalFptr)(void));

void DelayTimeSec(void);
void TIMER0_IntSevice(void);
void TIMER0_DelayOnSec(u8 time,void (*ptr)(void));



#endif /* TIMER_SERVICE_H_ */