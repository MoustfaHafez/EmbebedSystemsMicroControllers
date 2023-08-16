

#include   "MemoryMap.h"
#include   "MacrosLikeFunction.h"
#include   "DIO.h"
#include   "DIO_Interafce.h"
#include   "STDTYPES.h"
#include   "Motor_Interface.h"
#include   "SevenSegment_Interface.h"
#include   "LCD_Interface.h"
#include   "KeyPad_Interface.h"
#include   "KeyPad_cfg.h"
#include   "Calculator.h"
#include   "Converter.h"
#include   "ADC.h"
#include   "Timer.h"
#include   "Sensors.h"
#include   "FireAlarm.h"
#include   "Interrupt.h"
#include   "TIMER_SERVICE.h"
#include   "Ultrasonic.h"
#include   "Boiler.h"
#include   "UARTService.h"
#include   "UART.h"



#define    F_CPU 8000000
#include  <util/delay.h>



#define secs 10;

#define StartStopButton    PINA0
#define CWCCWButton        PINA1
#define pushbutton         PINB0
#define psuhbutton2        PINB1
#define PB1                PIND2
#define PB2                PIND3
#define RED                PINC0
#define GREEN              PINC1
#define BLUE               PINC2
#define Buzer              PINC5


volatile static u16 c=0,flag=0,t1=0,t2=0,Time=0;


u8 str[20];
static volatile u8 data[20];
//volatile static flag;

void MON()
{
	DIO_VidTogglePin(PINC2);
}

void Func_RX(void)
{
	static u8 i=0;
	data[i++]=UART_ReceiveByteNoBlock();
	if(i==19)
	{
		i=0;
	}
	flag++;
	
}


void F1(void)
{
	t1=TCNT1;
}

void F2(void)
{
	t2=TCNT1;
}

void OVF(void)
{
   c++;
}
 

int main(void)
{
   u8 i=0;
   sei();
   DIO_VidIntallPins();
   LCD_Init();
   KeyPad_Init();
   ADCInit(VREF_VCC,ADC_SCALER_64);
  // BoilerAppInit();
  /*****************************************************/
  TIMER1_INIT(TIMER1_NORMALMODE,TIMER1_SCALER_8);
  TIMER1_OVF_InterruptEnable();
  TIMER1_OVF_SetCallBack(&F2);
  ExternalInttruptwillbeActivatedWith(Interrupt_INT0,NegativeEdge);
  ExternalInterruptEnable(Interrupt_INT0);
  Ext_SetCallBack(Interrupt_INT0,&F1);
  ExternalInttruptwillbeActivatedWith(Interrupt_INT1,NegativeEdge);
  ExternalInterruptEnable(Interrupt_INT1);
  Ext_SetCallBack(Interrupt_INT0,&F2);
  
   while(1)
   {	   
	  Time=(t2-t1)+((u32)c*65535);
	  LCDGoTo(0,0);
	  LCD_WriteNumber(Time);
   }
   
	
 }











	