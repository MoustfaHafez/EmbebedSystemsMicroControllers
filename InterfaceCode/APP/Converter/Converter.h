

#ifndef CONVERTER_H_
#define CONVERTER_H_

#include "STDTYPES.h"

 typedef enum
 {
	 Binary=1,
	 Dec,
	 Hex
 }NumberSystem_Type;

void ConverterSelectFromFristLine( u8  *str);
void ConverterSelectFromSecondLine(u8 *str);

void ConvertFromDecToBinary(void);

void ConvertFromStringToHex(u8 k);
u16  ConvertFromHexToDecimal(void);


#endif /* CONVERTER_H_ */