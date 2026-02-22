#include "headers.h"      // Includes LCD, keypad, RTC, GPIO and data type definitions

/*---------------------------------------------------------
 Extern RTC variables
 These variables hold current RTC time and date values
----------------------------------------------------------*/
extern s32 hour,min,sec,date,month,year,day;

/*---------------------------------------------------------
 Function Name : Edit_RTC_Time
 Description   : Allows user to edit RTC time and date
                 using keypad input and LCD display
----------------------------------------------------------*/
void Edit_RTC_Time(void)
{
        u8 ch;            // Stores keypad key value
	    u32 data;        // Stores numeric input from keypad

/* Label to repeatedly display RTC edit menu */
  test: CmdLCD(CLEAR_DISP);           // Clear LCD screen
	    CmdLCD(GOTO_LINE1_POS0);       // Move cursor to first line
	    StrLCD("1:H 2:M 3:S 4:D");     // Display time edit options
	    CmdLCD(GOTO_LINE2_POS0);       // Move cursor to second line
	    StrLCD("5:d 6:m 7:y 8:E");     // Display date edit and exit options

	    WRITENIBBLE(IOPIN1,16,0);       // Clear Row values
	    while(ColStat());              // Wait for key press

	    ch=ReadKeyVal();               // Read pressed key
		delay_ms(100);                 // Key debounce delay

	    CmdLCD(CLEAR_DISP);             // Clear LCD
	    CmdLCD(GOTO_LINE1_POS0);        // Move cursor to first line
	    
		/*--------------------------------------------------
		  Process user selection based on key pressed
		--------------------------------------------------*/
		switch(ch)
	    {
	        case '1': StrLCD("Set hour(0-23)");  // Hour setting
				            data=Readnum();      // Read numeric input
				      if(data>23)               // Validate hour range
				            Display_invalid();
				      else
				            hour=data;           // Store valid hour
				      goto test;               // Return to menu
							
		    case '2': StrLCD("Set Minute(0-59)"); // Minute setting
				      data=Readnum();
				      if(data>59)               // Validate minute range
				            Display_invalid();
				      else
				            min=data;            // Store valid minute
				      goto test;
							
	 	    case '3': StrLCD("Set second(0-59)"); // Second setting
				      data=Readnum();
				      if(data>59)				      
				            Display_invalid();				                
				      else
				            sec=data;            // Store valid second
				      goto test;
							
		    case '4': StrLCD("0:SU 1:MO 2:TU");   // Day selection help
				      CmdLCD(GOTO_LINE2_POS0);
				      StrLCD("3:WD4:TH5:FR6:SA");
				      delay_ms(500);
				      CmdLCD(CLEAR_DISP);
		              CmdLCD(GOTO_LINE1_POS0);
				      StrLCD("Set Day(0-6)");
				      data=Readnum();
				      if(data>6)				               
				             Display_invalid();				               
				      else
				             day=data;           // Store valid day
				      goto test;
							
		    case '5': StrLCD("Set date(1-31)");   // Date setting
				      data=Readnum();
				      if((data>31) || (data==0))				  
				             Display_invalid();				               
				      else
				             date=data;          // Store valid date
				      goto test;
							
		    case '6': StrLCD("Set month(1-12)");  // Month setting
				      data=Readnum();
				      if((data>12) || (data==0))				                
				             Display_invalid();				              
				      else
				             month=data;         // Store valid month
				      goto test;
							
		    case '7': StrLCD("Set year(1-4095)"); // Year setting
				      data=Readnum();
				      if((data>4590) || (data==0))				       
				             Display_invalid();				             
				      else
				             year=data;          // Store valid year
				      goto test;
							
		    case '8': StrLCD("RTC Time Saved");   // Save and exit
					  SetRTCTimeInfo(hour,min,sec);   // Set RTC time
			     	  SetRTCDateInfo(date,month,year); // Set RTC date
					  SetRTCDay(day);                 // Set RTC day
				      delay_ms(500);							
		              break;
							
		    default: StrLCD("Invalid KeyVal");    // Invalid key handling
				     delay_ms(1000);
				     goto test;
	     }
}
