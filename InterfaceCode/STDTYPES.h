

#ifndef STDTYPES
#define STDTYPES

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned int   u16;
typedef signed int     s16;
typedef unsigned long  u32;
typedef signed long    s32;

#define NULL_PTR     ((void*)0)

typedef enum
{
	OK,
	NOK,
	NULL,
	OUT_OF_RANGE
}ERROR_Type;

typedef enum
{
	False,
	True
}bool_Type;

#define Max_U16   65535
#define Max_s16   32767
#define Min_s16  -32768
#define Min_u16   0

#endif /* UTILS_H_ */