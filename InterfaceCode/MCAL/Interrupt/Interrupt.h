

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

typedef enum
{
	lowLevel=0,
	onchange,
	PostiveEdge,
	NegativeEdge
		
}InterruptSenseControl_Type;

typedef enum
{
   Interrupt_INT0=0,
   Interrupt_INT1,
   Interrupt_INT2
	
}IntrruptSource_Type;

void ExternalInttruptwillbeActivatedWith(IntrruptSource_Type source,InterruptSenseControl_Type Trigger);
void ExternalInterruptEnable(IntrruptSource_Type source);
void ExternalInterruptDisable(IntrruptSource_Type source);
void Ext_SetCallBack(IntrruptSource_Type source,void (*ptrToFunc)(void));

#endif /* INTERRUPT_H_ */