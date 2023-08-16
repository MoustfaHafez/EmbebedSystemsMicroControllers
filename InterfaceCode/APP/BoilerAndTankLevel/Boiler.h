

#ifndef   BOILER_H_
#define   BOILER_H_
#include "BoilerCfg.h"

u8   Boiler_U8GetLevelSensor(void);
u16  Boiler_U16GetTempSensor(void);
void BoilerAppDiplayTempSensorRead(u8 *str,u16 SensorRead);
void BoilerAppInit(void);
void BoilerStartSystem(void);
void BoilerStopSystem(void);
void Boiler_Timer1_Init();
void BoilerRunnableApp();



#endif 