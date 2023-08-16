

#ifndef FIREALARM_H_
#define FIREALARM_H_

#include "FireAlarm_cfg.h"

void FireAlarmSystemReadDisplayTemp(void);
void FireAlarmSystemFineState(void);
void FireAlarmSystemHeatState(void);
void FireAlarmSystemSmokeState(void);
void FireAlarmSystemReadDisplaySmoke(void);
void FireAlarmSystemDiplaySensorRead(u8 *str,u16 SensorRead,u8 *unit);


#endif /* FIREALARM_H_ */