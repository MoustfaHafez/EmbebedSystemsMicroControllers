
#include "STDTYPES.h"
#include "Timer.h"
#include "TIMER_SERVICE.h"
#include "LCD_Interface.h"
#include "Boiler.h"
#include "Ultrasonic.h"
#include "Sensors.h"
#include "Motor_Interface.h"
#include "Interrupt.h"

static volatile u8 StartFlag=0;

void BoilerStartSystem(void)
{
	StartFlag=1;
}

void BoilerStopSystem(void)
{
	StartFlag=0;
}




void BoilerAppInit(void)
{	
	ExternalInttruptwillbeActivatedWith(Interrupt_INT0,NegativeEdge);
	ExternalInterruptEnable(Interrupt_INT0);
	Ext_SetCallBack(Interrupt_INT0,BoilerStartSystem);
	ExternalInttruptwillbeActivatedWith(Interrupt_INT1,NegativeEdge);
	ExternalInterruptEnable(Interrupt_INT1);
	Ext_SetCallBack(Interrupt_INT1,BoilerStopSystem);
	
	TIMER0_IntSevice();
	
	ULTRASONIC_Init();
}


u8 Boiler_U8GetLevelSensor(void)
{
	u8 dis=ULTRASONIC_GetDistance();
	return dis;
}
u16 Boiler_U16GetTempSensor(void)
{
	u16 temp=Temp_Read();
	return temp;
}
void BoilerAppDiplayTempSensorRead(u8 *str,u16 SensorRead)
{
	LCD_WriteString(str);
	LCD_WriteNumber(SensorRead/10);
	LCD_WriteChar('.');
	LCD_WriteNumber(SensorRead%10);

}

void BoilerRunnableApp()
{
	 u8 LevelSensor=Boiler_U8GetLevelSensor();
	 LCDGoTo(0,0);
	 LCD_WriteString("levelSensor=");
	 LCD_WriteNumber(LevelSensor);
	 LCD_WriteString("  ");
	  
	 u16 Temp=Boiler_U16GetTempSensor();
	 LCDGoTo(1,0);
	 BoilerAppDiplayTempSensorRead("Temp=",Temp);
	 
	if(StartFlag==1)
	{
		
			if(LevelSensor<=MinLevelOfTank)
			{
				InletValveOpen();		
				/*_delay_ms(3000);
				MotorOn();*/
				TIMER0_DelayOnSec(3,&MotorOn);
				
			}
			else if (LevelSensor>=MaxLevelOfTank)
			{
				
				MotorOFF();
				InletValveClose();			
			}
			/***********Heater Conditions***********/
			if(LevelSensor>=MaxLevelOfTank && Temp<=MaxTempOfTank)
			{
				HeaterON();
			}
			else if(Temp>=MaxTempOfTank)
			{
				HeaterOFF();
			}
			
			/*======outletValve Conditions==========*/
		    if(LevelSensor<=MinLevelOfTank)
		    {
			    OutletValveClose();
		    }	    
		    else if(Temp>=MaxTempOfTank)
		    {
			    OutletValveOpen();
		    }
			
	}
	else
	{
		InletValveClose();
		OutletValveClose();
		MotorOFF();
		HeaterOFF();
	}
   
   
}

