
#include  "STDTYPES.h"
#include  "LCD_Interface.h"
#include  "Sensors.h"
#include  "Motor_Interface.h"
#include  "LED.h"
#include  "FireAlarm.h"



static u16 TempRead=0,SmokeRead=0,HeatFlag=0,Smokeflag=0;

void FireAlarmSystemDiplaySensorRead(u8 *str,u16 SensorRead,u8 *unit)
{
	LCD_WriteString(str);
	LCD_WriteNumber(SensorRead/10);
	LCD_WriteChar('.');
	LCD_WriteNumber(SensorRead%10);
	LCD_WriteString(unit);
	LCD_WriteString(" ");
}

void FireAlarmSystemReadDisplayTemp(void)
{
	TempRead=Temp_Read();
	LCDGoTo(0,0);
	FireAlarmSystemDiplaySensorRead("Temp=",TempRead,"C");
}

void FireAlarmSystemReadDisplaySmoke(void)
{
	SmokeRead=MPX415SmokeeRead();
	LCDGoTo(1,0);
	
	if(SmokeRead>=FireStateSmoke)
	{
		FireAlarmSystemDiplaySensorRead("Smoke=",SmokeRead,"%");
	}
	else if(SmokeRead<FireStateSmoke && Smokeflag==1)
	{
		FireAlarmSystemDiplaySensorRead("Smoke=",SmokeRead,"%");
	}
}

void FireAlarmSystemFineState()
{
	
		LCDGoTo(0,12);
		LCD_WriteString("Fine");
		LEDOFF(YELLOWLED);
		LEDOFF(REDLED);
		MotorOFF();
	
	
}

void FireAlarmSystemHeatState()
{
		LCDGoTo(0,12);
		LCD_WriteString("Heat");
		LEDON(YELLOWLED);
		LEDOFF(REDLED);
		MotorOFF();
		HeatFlag=1;
}

void FireAlarmSystemSmokeState()
{
	FireAlarmSystemReadDisplaySmoke();
	if(SmokeRead>=FireStateSmoke)
	{
		LCDGoTo(0,12);
		LCD_WriteString("Fire");
		LEDOFF(YELLOWLED);
		LEDON(REDLED);
		MotorOn();
		Smokeflag=1;
	}
}

void FireAlarmSystemRunnable()
{
	FireAlarmSystemReadDisplayTemp();
	if(TempRead<=FineStateTemp && Smokeflag==0)
	{
		FireAlarmSystemFineState();
	}
	if(TempRead>=HeatStateTemp && Smokeflag==0)
	{
		FireAlarmSystemHeatState();
	}
	if(HeatFlag==1)
	{
		FireAlarmSystemSmokeState();
	}

}