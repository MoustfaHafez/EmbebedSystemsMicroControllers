
#include "Converter.h"
#include "LCD_Interface.h"
#include "LCD_Cfg.h"
#include "STDTYPES.h"
#include "KeyPad_cfg.h"
#define    F_CPU 8000000
#include  <util/delay.h>



void WelcomeMessage(void)
{
	LCDGoTo(0,5);
	LCD_WriteString("Welcome");
	LCDGoTo(1,5);
	LCD_WriteString("Mostafa");
	_delay_ms(3000);
	LCD_Clear();
}

 u16 Power(u8 base,u8 num)///2*2*2*2*2
{
	u16 Result=1;	
	for(u8 i=1;i<=num;i++)
	{
		Result*=base;
	}
	return Result;
}

/*******************************************************/
static u16 HexToDec=0;
static u8 str[16];
static u8 i=0;
void ConvertFromStringToHex(u8 k)//12A '1''2''A' ///'1'-'0'=1 '2'-'0'=2   'A'-'7'=10  'B'-'7'=11
{
	if(k>='0' && k<='9')
	{
		str[i]=k-'0';//str[0]=1, str[1]=2 ,str[2]=10;
		i++;
	}
	else if(k>='A' && k<='Z')
	{
		str[i]=k-55;//
		i++;
	}
}

u16 ConvertFromHexToDecimal(void)
{
	u8 x=0;
	for(s8 j=i-1;j>=0;j--,x++)
	{
		HexToDec+=str[j]*Power(16,x);
	}
	return HexToDec;
}


void RenitilizeDatafromStringToHex()
{
	
	for(u8 j=0;j<i;j++)
	{
		str[j]=0;
	}
	i=HexToDec=0;
}
/**************************************************/

 u8  BinaryArray[16];
 u16 BinaryToDec=0;
 u8  i1=0;
 void ConvertFromStringToBinary(u8 k)
 {
	 if(k>='0' && k<='1')
	 {
		 BinaryArray[i1]=k-'0';
		 i1++;
	 } 
 }

u16 ConvertFromBinaryToDec()
{
	u8 x=0;
	for(s8 j=i1-1;j>=0;j--,x++)
	{
		BinaryToDec+=BinaryArray[j]*Power(2,x);
	}
	return BinaryToDec;
}

void RenitilixeDataFromStringToBinary()
{
	for(u8 j=0;j<i1;j++)
	{
		BinaryArray[j]=0;
	}
	i1=BinaryToDec=0;
}
/****************************************************/
u16 DecNum=0;
u16 ConvertFromStringToDecimal(u8 k)
{

	if(k>='0' && k<='9')
	{
		DecNum=DecNum*10+k-'0';
	}
	return DecNum;
}

void RenitializeDataFromStringToDec()
{
	DecNum=0;
}
/***************************************************/
void ConverterModeFirstLine(u8 *str)
{
	 LCDGoTo(0,0);
	 LCD_WriteString("                 ");
	 LCDGoTo(0,0);
	 LCD_WriteString(str);
	 LCDGoTo(1,0);
	 LCD_WriteString("1.B   2.Dec  3.Hex");	
}

void ConvertModeSecondLine(u8 *str)
{
	 LCDGoTo(1,0);
	 LCD_WriteString("                 ");
	 LCDGoTo(1,0);
	 LCD_WriteString(str);
	 LCDGoTo(0,5);
}

u8 flagFirstLine=0,flagSecondLine=0;

void ConverterFirstScreenFirstLine(u8 k)
{
  
   if(flagFirstLine==0)
   {
	     LCD_WriteString("1.B   2.D  3.Hex");
		 flagFirstLine=1;
   }
   if(k=='1')
   {    
	    ConverterModeFirstLine("1.B");
		//BinaryFlag++;
		
   }
   else if(k=='2')
   {
	    ConverterModeFirstLine("2.Dec");
   }
   else if(k=='3')
   {
	    ConverterModeFirstLine("3.Hex");
   }
  	
}






static flag=0,flag1=0;u16 ResultDecimal=0;

u8 BinaryFlag=0,DecFlag=0,HexFlag=0;

void ConverterRunnable()
{
	u8 k=keyPad_GetKey();
	if(flag==0)
	{
		WelcomeMessage();
		flag=1;
	}
	if(k!=NOKEY)
	{		
        if(flag1==0)
        {
	        LCDGoTo(0,0);
	        LCD_WriteString("           ");
	        LCDGoTo(0,0);
	        flag1=1;
        }
	 
	
		    LCD_WriteChar(k);
		    ResultDecimal=ConvertFromStringToDecimal(k);
				
		//ConvertFromStringToHex(k);	
		//ConvertFromStringToBinary(k);
		
	}
	if(k=='=')
	{
		LCDGoTo(1,0);
		//u16 ResultHexToDec=ConvertFromHexToDecimal();
		//u16 ResultBinaryToDec=ConvertFromBinaryToDec();
		
		
		
		LCD_WriteNumber(ResultDecimal);
		LCDWriteBinary(ResultDecimal);
		LCDWriteHex(ResultDecimal);
		LCD_WriteString("                        ");
		//RenitilizeDatafromStringToHex();
		RenitializeDataFromStringToDec();
		ResultDecimal=0;
		flag1=0;
		DecFlag=0;
	}
	
}






void ConverterSelectFromSecondLine(u8* str)
{
	LCDGoTo(1,0);
	LCD_WriteString("                             ");
	LCDGoTo(1,0);
	LCD_WriteString(str);
}