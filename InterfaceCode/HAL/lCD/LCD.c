

#include "STDTYPES.h"
#include "DIO_Interafce.h"
#include "LCD_Interface.h"
#include "LCD_Cfg.h"
#include "MacrosLikeFunction.h"

#define    F_CPU 8000000
#include  <util/delay.h>

/***************************8 BIT MODE***********************************/

#if LCDMODE==LCD_8Bit

static void LCDWriteInstruction(u8 ins)
{
	
	DIO_VidWritePin(RS,Low);///send command
	DIO_VidWritePort(LCDPORT,ins);
	DIO_VidWritePin(LCDEN,High);
	_delay_ms(1);
	DIO_VidWritePin(LCDEN,Low);
	
	_delay_ms(1);
}


static void LCDWriteData(u8 Data)
{
	DIO_VidWritePin(RS,High); /// send data on port 
	DIO_VidWritePort(LCDPORT,Data);
	DIO_VidWritePin(LCDEN,High);
	_delay_ms(1);
	DIO_VidWritePin(LCDEN,Low);
	_delay_ms(1);
}

void LCD_Init(void)
{
	_delay_ms(50);
	LCDWriteInstruction(0x38);/// screen on 8 bit mode 
	LCDWriteInstruction(0x0c);/// cursor off 0x0e, 0x0f
	LCDWriteInstruction(0x01);/// clearscren 
	_delay_ms(1);
	LCDWriteInstruction(0x06);/// increase DDRAM NO SHIFT	
}
/**************************** 4 bit mode ********************************/
#elif LCDMODE==LCD_4Bit

static void LCDWriteInstruction(u8 ins)//0x39   0b 0011 1001
{
	
	DIO_VidWritePin(RS,Low);///send command
	
	DIO_VidWritePin(D7,ReadPin(ins,7));
	DIO_VidWritePin(D6,ReadPin(ins,6));
	DIO_VidWritePin(D5,ReadPin(ins,5));
	DIO_VidWritePin(D4,ReadPin(ins,4));
	DIO_VidWritePin(LCDEN,High);
	_delay_ms(1);
	DIO_VidWritePin(LCDEN,Low);
	_delay_ms(1);
	/****************low data**********************/
	DIO_VidWritePin(D7,ReadPin(ins,3));
	DIO_VidWritePin(D6,ReadPin(ins,2));
	DIO_VidWritePin(D5,ReadPin(ins,1));
	DIO_VidWritePin(D4,ReadPin(ins,0));
	DIO_VidWritePin(LCDEN,High);
	_delay_ms(1);
	DIO_VidWritePin(LCDEN,Low);
	_delay_ms(1);
}


static void LCDWriteData(u8 Data) //0x039   0b 0011 1001
{
	DIO_VidWritePin(RS,High); /// send data on port
	
	DIO_VidWritePin(D7,ReadPin(Data,7));
	DIO_VidWritePin(D6,ReadPin(Data,6));
	DIO_VidWritePin(D5,ReadPin(Data,5));
	DIO_VidWritePin(D4,ReadPin(Data,4));
	DIO_VidWritePin(LCDEN,High);
	_delay_ms(1);
	DIO_VidWritePin(LCDEN,Low);
	_delay_ms(1);
	/****************low data**********************/
	DIO_VidWritePin(D7,ReadPin(Data,3));
	DIO_VidWritePin(D6,ReadPin(Data,2));
	DIO_VidWritePin(D5,ReadPin(Data,1));
	DIO_VidWritePin(D4,ReadPin(Data,0));
	DIO_VidWritePin(LCDEN,High);
	_delay_ms(1);
	DIO_VidWritePin(LCDEN,Low);
	_delay_ms(1);
}

void LCD_Init(void)
{
	_delay_ms(50);
	LCDWriteInstruction(0x02);
	LCDWriteInstruction(0x28);/// screen on 4 bit mode
	LCDWriteInstruction(0x0c);/// cursor off 0x0e, 0x0f
	LCDWriteInstruction(0x01);/// clearscren
	_delay_ms(1);
	LCDWriteInstruction(0x06);/// increase DDRAM NO SHIFT
}

#endif

/*****************************************************************/

void LCD_WriteChar(u8 chr)
{
	LCDWriteData(chr);
}

void LCD_WriteString(u8 *str)
{
	u8 i=0;
	for(i=0;str[i];i++)
	{
		LCDWriteData(str[i]);
	}
}


void LCD_Clear(void)
{
	LCDWriteInstruction(0x01);/// clearscren
	_delay_ms(1);
}

void LCD_WriteNumber(s16 num)
{
	u8 i=0, str[16];
	s8 j;
	if(num==0)
	{
		LCD_WriteChar('0');
		return;
	}
	if(num<0)
	{
		num*=-1;
		LCD_WriteChar('-');
	}
	while(num>0)
	{
		str[i]=num%10+'0';
		num/=10;
		i++;
	}
	for(j=i-1;j>=0;j--)
	{
		LCD_WriteChar(str[j]);
	}
}

void LCD_WriteNumber4Digit(u8 num)///8542
{
	LCD_WriteChar( ((num%10000)/1000) +'0');
	LCD_WriteChar( ((num%1000)/100) +'0');
	LCD_WriteChar( ((num%100)/10) +'0');
	LCD_WriteChar( ((num%10)/1) +'0');
}


void LCDWriteBinary(u16 num)
{
	u8 flag=0;
	for(s8 i=31;i>=0;i--)
	{
		if((num>>i)&1)
		{
			LCD_WriteChar('1');
			flag=1;
		}
		else
		{
			if(flag==1)
			{
				LCD_WriteChar('0');
			}
			
		}
	}
}


/***************************************************/
void LCDWriteHex(u16 num)
{
	u8 i=0,str[16];
	s8 j;
	while(num>0)
	{
		u8 Rem=num%16;
		
		if(Rem<10)
		{
			str[i]=Rem+'0';
		}
		else
		{
			str[i]=Rem+'7';
		}
		num/=16;
		i++;
	}
	//////////////////////////////////////////////////////////////////////////
	for(j=i-1;j>=0;j--)
	{
		LCD_WriteChar(str[j]);
		
	}
}

/********************************************************/
void LCDGoTo(u8 line,u8 cell)
{
	if(line==0)
	{
	   LCDWriteInstruction(0x80+cell);
	}
	else if(line==1)
	{
		LCDWriteInstruction(0x80+cell+0x40);
	}
}

/*******************************************************/
