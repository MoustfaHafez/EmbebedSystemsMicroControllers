


#ifndef MACROSLIKEFUNCTION_H_
#define MACROSLIKEFUNCTION_H_

#define  SETBIT(Reg,Bit)     (Reg|=(1<<Bit))
#define  RESETBIT(Reg,Bit)   (Reg&=(~(1<<Bit)))
#define  TOGGLEBIT(Reg,Bit)  (Reg^=(1<<Bit))
#define  ReadPin(Reg,Bit)    (((Reg>>Bit)&1))

#endif /* MACROSLIKEFUNCTION_H_ */