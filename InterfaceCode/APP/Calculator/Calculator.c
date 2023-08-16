
#include  "Calculator.h"
#include  "KeyPad_Interface.h"
#include  "LCD_Interface.h"
#include  "STDTYPES.h"
#include  "KeyPad_cfg.h"


s16 Calculator(u8 n1 ,u8 n2 , u8 sign)
{
	s16 value=0;
	switch (sign)
	{
		case '+':
		value=n1+n2;
		break;
		case '-':
		value=n1-n2;
		break;
		case '*':
		value=n1*n2;
		break;
		case '/':
		value=n1/n2;
		break;
	}
	return value;
}

static u8 flag1=0,flag=0,n1=0,n2=0,sign;


void CalculatorRunnable(void)
{
	 u8 k=keyPad_GetKey();

	 if(k!=NOKEY)
	 {
		 if(k>='0' && k<='9')
		 {
			 
			 if(flag1==0)
			 {
				 LCDGoTo(0,0);
				 LCD_WriteString("           ");
				 LCDGoTo(0,0);
				 flag1=1;
			 }
			 if(flag==0)
			 {
				 n1=n1*10+k-'0';
				 LCD_WriteChar(k);
			 }
			 else if (flag==1)
			 {
				 n2=n2*10+k-'0';
				 LCD_WriteChar(k);
			 }
			 
		 }
		 if(k=='+' || k=='-' ||k=='*' ||k=='/')
		 {
			 flag=1;
			 LCD_WriteChar(k);
			 sign=k;
		 }
		 if(k=='=')
		 {
			 LCD_WriteChar(k);
			 s16 value=Calculator(n1,n2,sign);
			 LCDGoTo(1,0);
			 LCD_WriteNumber(value);
			 LCD_WriteString("    ");
			 n1=n2=0;
			 flag=0;
			 flag1=0;
		 }
		 if(k=='c')
		 {
			 LCD_Clear();

		 }
		 
	 }
	
}

