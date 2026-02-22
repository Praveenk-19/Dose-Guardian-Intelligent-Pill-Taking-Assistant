#include "headers.h"     // Includes LCD, keypad, delay and data type definitions

/*---------------------------------------------------------
 Function Name : Readnum
 Purpose       : Read a multi-digit number from keypad
 Return Value  : Entered number as integer
----------------------------------------------------------*/
s32 Readnum(void)
{
       u32 num=0;        // Variable to store the final number
	   s8 key,cnt=0;     // key → pressed key, cnt → digit count

/* Label to restart input if invalid key is pressed */
label: CmdLCD(GOTO_LINE2_POS0);
	   StrLCD("                "); // Clear second line of LCD

	   while(1)          // Loop until 'E' key is pressed
	   {
		     CmdLCD(GOTO_LINE2_POS0+cnt); // Set cursor at current position
	         WRITENIBBLE(IOPIN1,16,0);     // Prepare keypad rows
	         while(ColStat());            // Wait for key press
	         key=ReadKeyVal();            // Read pressed key
	         delay_ms(200);               // Key debounce delay
					
	         /* If numeric key (0–9) is pressed */
	         if( (key>='0') && (key<='9') )
	         {
				  CharLCD(key);          // Display digit on LCD
		          num=(num*10)+(key-48); // Build number
			      cnt++;                // Increase digit count
	         }

	         /* If '/' key is pressed → delete last digit */
	         else if( key == '/' )
	         {
				  if(cnt==0)      // No digit to delete
					  cnt=0;
				  else
				  {
	                  num=num/10;            // Remove last digit
				      cnt--;             // Decrease digit count
	                  CmdLCD(GOTO_LINE2_POS0+cnt);
				      CharLCD(' ');     // Clear last digit on LCD
				  }
	         }

	         /* If 'E' key is pressed → confirm input */
	         else if( key == 'E' )
	         {
	              return num;             // Return entered number
	         }
	         
			 /* If any invalid key is pressed */
			 else
	         {
	              CmdLCD(GOTO_LINE2_POS0);
		          StrLCD("                 "); // Clear line
				  CmdLCD(GOTO_LINE2_POS0);
    	          StrLCD("Invalid KeyVal");     // Error message
			      delay_ms(500);
				  CmdLCD(GOTO_LINE2_POS0);
		          StrLCD("                  ");
				  CmdLCD(GOTO_LINE2_POS0);
    	          StrLCD("Set Again");          // Prompt to retry
			      delay_ms(500);
			      num=0;                      // Reset number
				  cnt=0;                      // Reset count
				  goto label;                 // Restart input
	         }
	  }
}
