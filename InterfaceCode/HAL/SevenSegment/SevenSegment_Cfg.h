/*
 * SevenSegment_Cfg.h
 *
 * Created: 11/6/2022 1:29:03 PM
 *  Author: Admin
 */ 


#ifndef SEVENSEGMENT_CFG_H_
#define SEVENSEGMENT_CFG_H_


#define SevenSegmentPort1   PORTA
#define SevenSegmentPort2   PORTB


#define _1SevenSegment8bitToDisplayOneNumberUsingOnePort              1
#define _2SevenSegment8bitToDisplayTwoNumberUsingTwoPort              2 
/* we can use one BCD 4bit to display one number from 0:9 using half of 
 port or use two  BCD 4 bit to display two number using one port in hex */
#define  SevenSegment4bitBCDToDisplayMumberInHex                      3
/* we can use one BCD 4bit to display one number from 0:9 using half of 
 port or use two  BCD 4 bit to display two number using one port in decimal */                  
#define  SevenSegment4bitBCDToDisplayNumberinDec                      4

#define  _2SevenSegmentmultiplixedWhichUsedInkit                      5

#define   SevenSegmentMultiplixedGr1                                  PINC7
#define   SevenSegmentMultiplixedGr2                                  PINC6                       


#define SevenSegmentType       _2SevenSegmentmultiplixedWhichUsedInkit               





#endif /* SEVENSEGMENT_CFG_H_ */