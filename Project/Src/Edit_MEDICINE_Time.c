#include "headers.h"        // Includes LCD, keypad, GPIO, RTC and data type definitions

/* Extern variables to store medicine time */
extern s32 med_hour,med_min;

/*---------------------------------------------------------
 Function Name : Edit_MEDICINE_Time
 Description   : Allows user to set medicine time (HH:MM:SS)
                 using keypad input and LCD display
----------------------------------------------------------*/
void Edit_MEDICINE_Time(void)
{
        u8 ch;             // Variable to store keypad character
		s32 data;          // Variable to store numeric input
 
/* Label for repeating menu until exit option is selected */
test:   CmdLCD(CLEAR_DISP);            // Clear LCD screen
	    CmdLCD(GOTO_LINE1_POS0);        // Move cursor to first line
	    StrLCD("1:H 2:M 3:E");      // Display menu options
		
		WRITENIBBLE(IOPIN1,16,0);        // Clear Row values
	    while(ColStat());               // Wait until any key is pressed
	    ch=ReadKeyVal();                // Read pressed key value
		delay_ms(200);                  // Key debounce delay
		
		CmdLCD(CLEAR_DISP);              // Clear LCD
		CmdLCD(GOTO_LINE1_POS0);         // Move cursor to first line
	      
		  /* Perform operation based on selected key */
		  switch(ch)
	      {
	            case '1': StrLCD("Set hour(0-23)");  // Prompt to set hour
				          data=Readnum();            // Read numeric value
				          if(data>23)                // Validate hour range
				                   Display_invalid(); 				              
		     	          else
						           med_hour=data;        // Store valid hour
				          goto test;                 // Return to menu

		        case '2': StrLCD("Set Minute(0-59)"); // Prompt to set minutes
				          data=Readnum();             // Read numeric value
				          if(data>59)                 // Validate minute range
				                    Display_invalid();				              
					      else
							        med_min=data;        // Store valid minute
				          goto test;                 // Return to menu

		        case '3':DisplayRTCTime(med_hour,med_min,0); // Display saved time
						 CmdLCD(GOTO_LINE2_POS0);           // Move to second line 
						 StrLCD("Med Time saved");   // Exit and save time
						 delay_s(1);                 // Show message for 1 sec
						 break;                      // Exit switch

                default:  StrLCD("Invalid KeyVal");   // Invalid key pressed
					      delay_ms(1000);             // Show message for 1 sec
					      goto test;                 // Return to menu
	      }
}
