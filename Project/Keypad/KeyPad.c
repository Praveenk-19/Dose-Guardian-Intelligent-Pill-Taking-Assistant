#include "headers.h"          // Contains GPIO and controller related definitions
#include "keypad_defines.h"  // Contains keypad row/column pin numbers and LUT table

/*---------------------------------------------------------
 Function Name : KeyPadInit
 Purpose       : Initialize keypad
 Explanation   : Sets keypad ROW pins as OUTPUT.
                 Column pins are kept as INPUT to detect key press.
----------------------------------------------------------*/
void KeyPadInit(void)
{
   IODIR1|=((1<<R0)|(1<<R1)|(1<<R2)|(1<<R3)); 
   // Configure R0, R1, R2, R3 pins as output for row scanning
}

/*---------------------------------------------------------
 Function Name : ColStat
 Purpose       : Check whether any key is pressed
 Return Value  : 1 → No key pressed
                 0 → Some key is pressed
 Explanation   : If all column pins are HIGH, no key is pressed.
----------------------------------------------------------*/
int ColStat(void)
{
   // Read column pins; if all bits are HIGH (1), keypad is idle
   if(((IOPIN1>>C0)&0xf)==0xf)
       return 1;   // No key pressed
   else
       return 0;   // Key pressed
}

/*---------------------------------------------------------
 Function Name : ReadKeyVal
 Purpose       : Find which key is pressed
 Return Value  : Character value of pressed key from LUT
 Explanation   : Scans rows one by one and checks columns.
----------------------------------------------------------*/
char ReadKeyVal(void)
{
   char RowVal,ColVal;   // Variables to store detected row and column

   /*------------- Check ROW 0 -------------*/
   IOCLR1=1<<R0;                             // Make row 0 LOW
   IOSET1=((1<<R1)|(1<<R2)|(1<<R3));         // Make other rows HIGH
   if(((IOPIN1>>C0)&0xf)!=0xf)               // If any column becomes LOW
   {
	  RowVal=0;                              // Key is in row 0
	  goto ColCheck;                         // Go to column detection
   }

   /*------------- Check ROW 1 -------------*/
   IOCLR1=1<<R1;                             // Make row 1 LOW
   IOSET1=((1<<R0)|(1<<R2)|(1<<R3));         // Make other rows HIGH
   if(((IOPIN1>>C0)&0xf)!=0xf)
   {
      RowVal=1;                              // Key is in row 1
	  goto ColCheck;                          // Go to column detection
   }

   /*------------- Check ROW 2 -------------*/
   IOCLR1=1<<R2;                             // Make row 2 LOW
   IOSET1=((1<<R0)|(1<<R1)|(1<<R3));         // Make other rows HIGH
   if(((IOPIN1>>C0)&0xf)!=0xf)
   {
      RowVal=2;                              // Key is in row 2
	   goto ColCheck;                         // Go to column detection
   }

   /*------------- Check ROW 3 -------------*/
   IOCLR1=1<<R3;                             // Make row 3 LOW
   IOSET1=((1<<R0)|(1<<R1)|(1<<R2));         // Make other rows HIGH
   if(((IOPIN1>>C0)&0xf)!=0xf)
      RowVal=3;                              // Key is in row 3

   /*------------- Column Detection -------------*/
   ColCheck: 
      if(((IOPIN1>>C0)&1)==0)                // If column 0 is LOW
	     ColVal=0;
	  else if(((IOPIN1>>C1)&1)==0)            // If column 1 is LOW
	     ColVal=1;
	  else if(((IOPIN1>>C2)&1)==0)            // If column 2 is LOW
	     ColVal=2;
	  else
	     ColVal=3;                            // Otherwise column 3

   /* Wait until key is released */
   while(((IOPIN1>>C0)&0xf)!=0xf);
   // Ensures key is released before next read

   /* Get key value from lookup table */
   return (LUT[RowVal][ColVal]);
}
