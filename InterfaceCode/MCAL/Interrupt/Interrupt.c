
#include "STDTYPES.h"
#include "MemoryMap.h"
#include "MacrosLikeFunction.h"
#include "Interrupt.h"

static void (*PtrTo_Int0)(void)=0;
static void (*PtrTo_Int1)(void)=0;
static void (*PtrTo_Int2)(void)=0;

void ExternalInterruptEnable(IntrruptSource_Type source)
{
	
	switch(source)
	{
		case Interrupt_INT0:
		SETBIT(GICR,INT0);
		break;
		case Interrupt_INT1:
		SETBIT(GICR,INT1);
		break;
		case Interrupt_INT2:
		SETBIT(GICR,INT2);
		break;
	}
}

void ExternalInterruptDisable(IntrruptSource_Type source)
{
	switch(source)
	{
		case Interrupt_INT0:
		RESETBIT(GICR,INT0);
		break;
		case Interrupt_INT1:
		RESETBIT(GICR,INT1);
		break;
		case Interrupt_INT2:
		RESETBIT(GICR,INT2);
		break;
	}
}

void ExternalInttruptwillbeActivatedWith(IntrruptSource_Type source,InterruptSenseControl_Type Trigger)
{
	if(Trigger==lowLevel)
	{
		switch (source)
		{
			case Interrupt_INT0:
			RESETBIT(MCUCR,ISC00);
			RESETBIT(MCUCR,ISC01);
			break;
			
			case Interrupt_INT1:
			RESETBIT(MCUCR,ISC10);
			RESETBIT(MCUCR,ISC11);
			break;
			
		}
	}
	else if(Trigger==onchange)
	{
		switch (source)
		{
			case Interrupt_INT0:
			SETBIT(MCUCR,ISC00);
			RESETBIT(MCUCR,ISC01);
			break;
			
			case Interrupt_INT1:
			SETBIT(MCUCR,ISC10);
			RESETBIT(MCUCR,ISC11);
			break;		
		}
	}
	else if(Trigger==PostiveEdge)
	{
		switch (source)
		{
			case Interrupt_INT0:
			SETBIT(MCUCR,ISC00);
			SETBIT(MCUCR,ISC01);
			break;
			
			case Interrupt_INT1:
			SETBIT(MCUCR,ISC10);
			SETBIT(MCUCR,ISC11);
			break;
			
			case Interrupt_INT2:
			SETBIT(MCUCSR,ISC2);
			break;
		}
	}
	else if(Trigger=NegativeEdge)
	{
		switch (source)
		{
			case Interrupt_INT0:
			RESETBIT(MCUCR,ISC00);
			SETBIT(MCUCR,ISC01);
			break;
			
			case Interrupt_INT1:
			RESETBIT(MCUCR,ISC10);
			SETBIT(MCUCR,ISC11);
			break;
			
			case Interrupt_INT2:
			RESETBIT(MCUCSR,ISC2);
			break;
		}
	}
}

void Ext_SetCallBack(IntrruptSource_Type source,void (*ptrToFunc)(void))
{
	switch (source)
	{
		case Interrupt_INT0:
		PtrTo_Int0=ptrToFunc;
		break;
		case Interrupt_INT1:
		PtrTo_Int1=ptrToFunc;
		break;
		case Interrupt_INT2:
		PtrTo_Int2=ptrToFunc;
		break;
	}
}

 ISR(INT0_vect)
{
	if(PtrTo_Int0!=0)
	{
		PtrTo_Int0();
	}
}

 ISR(INT1_vect)
{
	if(PtrTo_Int1!=0)
	{
		PtrTo_Int1();
	}
}
 ISR(INT2_vect)
{
	if(PtrTo_Int2!=0)
	{
		PtrTo_Int2();
	}
}