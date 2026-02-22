#include "headers.h"        // Includes LCD, keypad, delay and related definitions

/*---------------------------------------------------------
 Global variables
----------------------------------------------------------*/
extern s32 flag,check_med_time;  // Flag to enable/disable medicine reminder
u8 choice;                       // Stores user menu selection

/*---------------------------------------------------------
 Function Name : menu
 Purpose       : Display menu on LCD and handle user choice
----------------------------------------------------------*/
void menu(void)
{
    /* Label to return back to menu */
    label:  CmdLCD(CLEAR_DISP);            // Clear LCD screen
		    CmdLCD(GOTO_LINE1_POS0);       // Move cursor to first line
			StrLCD("1.E.RTC 3.EXIT");      // Display menu options
	        CmdLCD(GOTO_LINE2_POS0);       // Move cursor to second line
			StrLCD("2.E.MED TIME");        // Display medicine time option

		    /* Prepare keypad for input */
		    WRITENIBBLE(IOPIN1,16,0);      // Clear row values in keypad
            while(ColStat());		       // Wait until a key is pressed

			choice=ReadKeyVal();           // Read pressed key
			delay_ms(100);                 // Key debounce delay
				     
		    /* Perform action based on user choice */
		    switch(choice)
		    {
			      case '1':Edit_RTC_Time();  // Edit RTC time and date
	                       CmdLCD(CLEAR_DISP);
			               break;

     	          case '2':flag=0;				
				           check_med_time=0;    
					       Edit_MEDICINE_Time();// Set or Edit medicine time
						   flag=1;              // Enable reminder after editing
		                   CmdLCD(CLEAR_DISP);
		                   break;

                 case '3':CmdLCD(CLEAR_DISP); // Exit menu
						  break;

			     default:CmdLCD(CLEAR_DISP);  // Invalid key handling
		                 CmdLCD(GOTO_LINE1_POS0);
		                 StrLCD("Invalid KeyVal");
     		              delay_ms(900);       // Display message for some time
					      goto label;         // Return to menu
		    }
}

