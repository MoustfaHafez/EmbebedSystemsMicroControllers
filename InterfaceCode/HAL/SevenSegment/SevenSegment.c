
#include "STDTYPES.h"
#include "MemoryMap.h"
#include "DIO_Interafce.h"
#include "SevenSegment_Interface.h"
#include "SevenSegment_Cfg.h"
#define    F_CPU 8000000
#include  <util/delay.h>


#if SevenSegmentType==_1SevenSegment8bitToDisplayOneNumberUsingOnePort

void SevenSegmentDisplay(u8 n)
{
	char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	SevenSegmentPort1=arr[n];
}

#elif SevenSegmentType==_2SevenSegment8bitToDisplayTwoNumberUsingTwoPort 

void SevenSegmentDisplay(u8 n)
{
	char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	SevenSegmentPort1=arr[n%10];
	SevenSegmentPort2=arr[n/10];
}

#elif SevenSegmentType==SevenSegment4bitBCDToDisplayMumberInHex

void SevenSegmentDisplay(u8 n)
{
	SevenSegmentPort1=n;
}

#elif SevenSegmentType==SevenSegment4bitBCDToDisplayNumberinDec

void SevenSegmentDisplay(u8 n)
{
	u8 d0=n%10;
	u8 d1=n/10;
	SevenSegmentPort1=d0 | d1<<4;
}

#elif SevenSegmentType== _2SevenSegmentmultiplixedWhichUsedInkit  

void SevenSegmentDisplay(u8 n)
{
	
	u8 arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	u8 d0=n%10;
	u8 d1=n/10;
	
	DIO_VidWritePin(SevenSegmentMultiplixedGr1,0);
	SevenSegmentPort1=arr[d0]<<1;
	DIO_VidWritePin(SevenSegmentMultiplixedGr2,1);
	_delay_ms(10);
	
	DIO_VidWritePin(SevenSegmentMultiplixedGr2,0);
	SevenSegmentPort1=arr[d1]<<1;
	DIO_VidWritePin(SevenSegmentMultiplixedGr1,1);
	_delay_ms(10);
}

#endif
