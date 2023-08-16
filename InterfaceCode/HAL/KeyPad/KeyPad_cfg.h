/*
 * KeyPad_cfg.h
 *
 * Created: 11/9/2022 8:57:21 PM
 *  Author: Admin
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#define FIRST_OUT     PINB3//
#define FIRST_INPUT   PIND0//


#define ROWS 4
#define Cols 4

#define NOKEY 'T'

#ifdef KEY_PROG

const static KeysArray[ROWS][Cols]={
	
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'c','0','=','+'},		
};

#endif




#endif /* KEYPAD_CFG_H_ */