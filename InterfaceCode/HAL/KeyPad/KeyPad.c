
#define KEY_PROG

#include "DIO_Interafce.h"
#include "STDTYPES.h"
#include "KeyPad_Interface.h"
#include "KeyPad_cfg.h"



void KeyPad_Init(void)
{
	/*DIO_VidWritePin(FIRST_OUT,High);
	DIO_VidWritePin(FIRST_OUT+1,High);
	DIO_VidWritePin(FIRST_OUT+2,High);
	DIO_VidWritePin(FIRST_OUT+3,High);*/
	
	DIO_Pinnumber_Type i;
	for(i=FIRST_OUT;i<4;i++)
	{
		DIO_VidWritePin(i,High);
	}

}

u8 keyPad_GetKey(void)
{
	u8 R,C,key=NOKEY;
	
	for(R=0;R<ROWS;R++)
	{
		DIO_VidWritePin(FIRST_OUT+R,Low);
		for(C=0;C<Cols;C++)
		{
			if(DIO_LowHighReadPin(FIRST_INPUT+C)==Low)
			{
				key=KeysArray[R][C];
				while (DIO_LowHighReadPin(FIRST_INPUT+C)==Low);			
			}
			
		}
		DIO_VidWritePin(FIRST_OUT+R,High);
	}
	
	return key;
	   
}
