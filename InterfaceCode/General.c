
#include "MacrosLikeFunction.h"
#include "MemoryMap.h"
unsigned char i=0;

/// delay for 2 msec 
/*for(i=0;i<100;i++)
{
	for(int x=0;x<500;x++)
	{
		SevenSegmentDiplaymultiplixed(i);///2 ms *500=1000ms
	}	
}
///task one one button to incremant another to decrement
////////////////////////////////////////////////////////////===========
  if(DIO_LowHighReadPin(PB1)==Low)
  {
	  i++;
	  if(i==99)
	  {
		  i=0;
	  }
	  while(DIO_LowHighReadPin(PB1)==Low);
  }
  
  if(DIO_LowHighReadPin(PB2)==Low)
  {
	  i--;
	  if(i==255)
	  {
		  i=99;
	  }
	  while(DIO_LowHighReadPin(PB2)==Low);
  }
  
  SevenSegmentDiplaymultiplixed(i);

}*/

//***************Trafic light***************************************

///if u pressed buton seven segment increment till you raise your hand 
 
	/*if(DIO_LowHighReadPin(PB1)==Low)
	{
		i++;
		if(i==100)
		{
			i=0;
		}
		for(unsigned int x=0;x<5;x++)
		{
			SevenSegmentDiplaymultiplixed(i);
		}
	}
	SevenSegmentDiplaymultiplixed(i);*/
	
///***************************************one button to increment s7 till u rasie your hand 
/// anthor one to decrement till you rasie your hand

/*if(DIO_LowHighReadPin(PB1)==Low)
{
	i++;
	if(i==100)
	{
		i=0;
	}
	for(unsigned int x=0;x<5;x++)
	{
		SevenSegmentDiplaymultiplixed(i);
	}
}

if(DIO_LowHighReadPin(PB2)==Low)
{
	i--;
	if(i==255)
	{
		i=99;
	}
	for(unsigned int x=0;x<5;x++)
	{
		SevenSegmentDiplaymultiplixed(i);
	}
}


SevenSegmentDiplaymultiplixed(i);
/*************************************8stop watch project**********************

one button to reset start from 0 another button to pause and resume if i==0 buzeer is activated

 if(DIO_LowHighReadPin(PB1)==Low)
 {
	 i=30;
	 flag=0;
	 DIO_VidWritePin(Buzer,Low);
	 while(DIO_LowHighReadPin(PB1)==Low);
 }
 
 if(DIO_LowHighReadPin(PB2)==Low)
 {
	 
	 flag=!flag;
	 while(DIO_LowHighReadPin(PB2)==Low);
 }
 
 if(flag==1)
 {
	 
	 for(u8 x=0;x<30;x++)
	 {
		 SevenSegmentDisplay(i);
	 }
	 i--;
	 if(i==255)
	 {
		 i=0;
		 DIO_VidWritePin(Buzer,High);
		 flag=0;
	 }
 }
 SevenSegmentDisplay(i);
 
 
 
 Move Cursor at any place on KeyPad
 
 
 LCDGoTo(0,0);
 LCD_WriteString("char: ");
 LCDGoTo(1,0);
 LCD_WriteString("ASCKI: ");
 
 while(1)
 {
	 
	 
	 u8 i='a';
	 for(i='a' ;i<='z';i++)
	 {
		 LCDGoTo(0,8);
		 LCD_WriteChar(i);
		 LCDGoTo(1,7);
		 LCD_WriteNumber(i);
		 _delay_ms(600);
	 }
	 
 }
 
 //keypad test 
 
 
 while(1)
 {
	 
	 k=keyPad_GetKey();
	 if(k!=NOKEY)
	 {
		 if(k>='0' && k<='9')
		 {
			 num=num*10+k-'0';/// convert from string to int
			 LCD_WriteChar(k);
		 }
		 else if (k=='=')
		 {
			 LCDGoTo(1,0);
			 LCDWriteBinary(num);
			 LCD_WriteString("       ");
			 num=0;
			 LCDGoTo(0,0);
		 }
		 else if(k=='c')
		 {
			 LCD_Clear();
		 }
		 
		 
	 }
	 
  }

//============calculator =================================
 while(1)
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
			 value=Calculator(n1,n2,sign);
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


/LCD_WriteString("Converter");
LCDGoTo(1,0);
LCD_WriteString("Wellcome Mostafa");
_delay_ms(2000);
LCD_Clear();
LCD_WriteString("1.B   2.D  3.Hex");


/******************************
static u16 HexToDec=0;//28
u16 ConvertFromHexToDecimal(u16 num)
{
	
	u8 i=0,Rem;
	while(num>0)
	{
		Rem=num%10;
		u16 P=Rem*Power(16,i);
		HexToDec=HexToDec+P;
		num=num/10;
		i++;
	}
	return HexToDec;
}




 u8 k= keyPad_GetKey();
 if(k!=NOKEY)
 {
	 if(k!= '=')
	 {
		 LCD_WriteChar(k);
		 Result= ConvertFromStringToDecimal(k);
	 }
 }
 if(k=='=')
 {
	 
	 LCDGoTo(1,0);
	 // u16 Result=ConvertFromBinaryToDec();
	 LCD_WriteNumber(Result);
	 LCDWriteBinary(Result);
	 LCDWriteHex(Result);
	 LCD_WriteString("  ");
	 //RenitilixeDataFromStringToBinary();
	 LCDGoTo(0,0);
	 */

// how to know excucate time of any faunctio

 /*      DIO_VidWritePin(PIND0,High);
	    _delay_us(200);
	     DIO_VidWritePin(PIND0,Low);
		===================================================
		TIMER0_SET_TCNT0(0);
		_delay_us(100);
		
		u8 y=c*256+TCNT0;
		TIMER0_OV_InterruptDisable();
		LCD_WriteNumber(y);*/
 
 //======================================TIMER0=====================================
  /*TIMER0_Init(TIMER0_SCALAR_8,TIMER0_FastPWMMode);
  sei();
  TIMER0_OV_InterruptEnable();
  TIMER0_OC_InterruptEnable();
  TIMER0_OC0PinMode(OCO_INVERTING);
  TIMER0_SET_OCR0(200);
  
  TIMER0_OV_SetCallBack(&TOGGLEPIN1);
  TIMER0_OC_SetCallBack(&TOOGLEPIN2);*/
  
  
 /*ISR(INT0_vect)
 {
	 DIO_VidTogglePin(PIND0);
 }*/
 
 /*ISR(TIMER1_OVF_vect)
{
	
	DIO_VidTogglePin(PIND0);
}

ISR(TIMER1_OCA_vect)
{
	
	DIO_VidTogglePin(PIND1);
}

ISR(TIMER1_OCB_vect)
{
	DIO_VidTogglePin(PIND2);
}

 /*ISR(TIMER0_OC_vect)
 {
    
	DIO_VidTogglePin(PIND0);
     
 }
  
ISR(TIMER0_OVF_vect)
{
	
	DIO_VidTogglePin(PIND5);
	
		
}*/
	/*c++;
	static u16 c=0;
	c++;
	TCNT0=56;
	if(c==4)
	{		
		DIO_VidWritePin(PIND0,High);		
	}
	else if(c==5)
	{
		DIO_VidWritePin(PIND0,Low);
		c=0;
	}
	
}

ISR(TIMER0_OVF_vect)
{
	u16 static c=0;
	c++;
	if(c==3906)
	{
		DIO_VidTogglePin(PIND6);
		c=0;
	}
}

ISR(TIMER0_OVF_vect)
{
	u16 static c=0;
	c++;
	TCNT0=6;// interrupt every 250 microsecodns
	if(c==4000)///4000*250 mc=1 sec
	{
		DIO_VidTogglePin(PIND6);
		c=0;
	}
}

ISR(TIMER0_OVF_vect)//pwm 50 hz 25% duty cycle
{
	u16 static c=0;
	c++;
	TCNT0=6;// interrupt every 250 microsecodns
	if(c==60)///4000*250 mc=1 sec
	{
		DIO_VidWritePin(PIND6,Low);
	}
	else if(c==80)
	{
		DIO_VidWritePin(PIND6,High);
		c=0;
	}
}

ISR(TIMER0_OVF_vect)//pwm 1 khz 20% duty cycle
{
	u16 static c=0;
	c++;
	TCNT0=56;// interrupt every 200 microsecodns
	if(c==4)///200*4=800 micro off 
	{
		DIO_VidWritePin(PIND6,Low);
	}
	else if(c==5)//1*200=200 on
	{
		DIO_VidWritePin(PIND6,High);
		c=0;
	}
}

ISR(TIMER0_OVF_vect)//pwm 5 khz 30% duty cycle
{
	u16 static c=0;
	c++;
	TCNT0=236;// interrupt every 20 microsecodns
	if(c==7)///20*4=140 micro off
	{
		DIO_VidWritePin(PIND6,Low);
	}
	else if(c==10)//3*20=60 on
	{
		DIO_VidWritePin(PIND6,High);
		c=0;
	}
}

//another solution to reduce number of interrupt 
// before wile one TCNT0=256-140==116 

ISR(TIMER0_OVF_vect)//PWM  5KHZ 30% duty cycle
{
	u16 static flag=0;
	if(flag==0)/// after 140 ms 
	{
		DIO_VidWritePin(PIND5,Low);
		flag=1;
		TCNT0=196;// 60 mus
	}
	else if(flag==1)// after 60micro
	{
		DIO_VidWritePin(PIND5,High);
		flag=0;
		TCNT0=116;// 60 mus
	}
}*/
 /*u8 x;
	   /*u8 x=UART_U8ReadData();
	   LCDGoTo(0,0);
	   LCD_WriteChar(x);*/
	   
	  /*if(UART_ReadDataPeriodicCheck(&x)==1)
	  {
		  LCDGoTo(0,0);
		  LCD_WriteChar(x);
	  }*/
	  
	  /* UART_VoidReadString(&str);
	   LCD_WriteString(&str);
	   LCD_WriteString("      ");
	   
       LCDGoTo(1,0);   
	   LCD_WriteNumber(n);
	   n++;
	   if(n==10)
	   {
		  n=0;
	   }
	  _delay_ms(200);*/




  
  