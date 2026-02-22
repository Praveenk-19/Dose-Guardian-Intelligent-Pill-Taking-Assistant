
#ifndef DEFINES_H
#define DEFINES_H

//Macros for bits or bytes operatoins		
#define SETBIT(WORD,BP)               WORD|=(1<<BP)
#define CLEARBIT(WORD,BP)             WORD&=(~(1<<BP))
#define CPLBIT(WORD,BP)               WORD^=(1<<BP)
#define TESTBIT(WORD,BP)              WORD=(WORD>>BP)&1
#define WRITEBIT(WORD,BP,BIT)         WORD=((WORD&~(1<<BP))|(BIT<<BP))
#define WRITENIBBLE(WORD,SBP,NIBBLE)  WORD=((WORD&~(0XF<<SBP))|(NIBBLE<<SBP))
#define WRITEBYTE(WORD,SBP,BYTE)      WORD=(WORD&(~(0XFF<<SBP))|(BYTE<<SBP))
#define WRITEHWORD(WORD,SBP,HWORD)    WORD=((WORD&~(0XFFFF<<SBP))|(HWORD<<SBP))
#define READBIT(WORD,BIT)             WORD=((WORD>>BIT)&1)

#endif
