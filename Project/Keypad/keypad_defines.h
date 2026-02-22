#ifndef KEYPAD_DEFINES_H
#define KEYPAD_DEFINES_H

/*---------------------------------------------------------
 Lookup Table (LUT) for 4×4 Matrix Keypad
 Maps row and column positions to key values
----------------------------------------------------------*/
char LUT[][4]={'1','2','3','*',
               '4','5','6','*',
			   '7','8','9','*',
    		   '/','0','E','*'};


/*---------------------------------------------------------
 Keypad Row and Column Pin Definitions
 R0–R3 : Row pins
 C0–C3 : Column pins
----------------------------------------------------------*/
#define R0 16
#define R1 17
#define R2 18
#define R3 19
#define C0 20
#define C1 21
#define C2 22
#define C3 23

#endif
