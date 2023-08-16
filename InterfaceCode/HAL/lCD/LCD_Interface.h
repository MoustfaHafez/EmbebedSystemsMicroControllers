/*
 * LCD_Interface.h
 *
 * Created: 11/8/2022 11:38:54 AM
 *  Author: Admin
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
#include "STDTYPES.h"

void LCD_Init(void);
void LCD_WriteNumber(s16 num);
void LCD_WriteNumber4Digit(u8 num);
void LCD_WriteChar(u8 num);
void LCD_WriteString(u8 *str);
void LCDWriteBinary(u16 num);
void LCDGoTo(u8 line,u8 cell);
void LCDWriteHex(u16 num);
void LCD_Clear(void);


#endif /* LCD_INTERFACE_H_ */