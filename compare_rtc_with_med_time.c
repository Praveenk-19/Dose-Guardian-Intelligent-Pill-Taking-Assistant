#include "headers.h"      // Include all required header files (LCD, GPIO, RTC, etc.)

/*---------------------------------------------------------
 Extern variables from RTC module
 These variables hold the current real-time clock values
----------------------------------------------------------*/
extern s32 hour,min,sec,date,month,year,day;

/*---------------------------------------------------------
 Extern variables for stored medicine reminder time
 These values are set by the user via keypad
----------------------------------------------------------*/
extern s32 med_hour,med_min,check_med_time; 


/*---------------------------------------------------------
 Function Name : compare_rtc_with_med_time
 Description   : Compares current RTC time with stored
                 medicine time and generates alert
                 using LCD, LED, and buzzer.
----------------------------------------------------------*/
void compare_rtc_with_med_time(void)
{
     u8 flag1=0;          // Status flag: 0 = not taken, 1 = medicine taken
     u32 delay=200;       // Counter to control reminder duration/repetitions

	 /*--------------------------------------------------
	   Check whether RTC time exactly matches medicine time
	   Alert is triggered only at the matched second
	 --------------------------------------------------*/
	 if( (hour==med_hour) && (min==med_min) ) 
	 {
		       check_med_time=1;
	         CmdLCD(CLEAR_DISP);   // Clear LCD before showing alert message
		     
			 /*----------------------------------------------
			   Reminder loop:
			   Continues alerting until user responds
			   or delay count expires
			 ----------------------------------------------*/
			 while(--delay)
			 {
				CmdLCD(GOTO_LINE1_POS0);     // Position cursor at LCD line 1
		        StrLCD("TAKE MEDICINE...");  // Prompt user to take medicine
			    
			    CLEARBIT(IOPIN1,LED);       // Turn OFF LED 
			    SETBIT(IOPIN1,BUZZ);        // Activate buzzer	

		        /*------------------------------------------
		          Check if confirmation switch (SW2) is pressed
		          Switch is active-low
		         ------------------------------------------*/
		         if( (READBIT(IOPIN0,SW2))== 0 )         //Waiting for SW2 press
		          {
		                 delay_ms(100);                  // Switch debounce delay
			             while( (READBIT(IOPIN0,SW2))== 0);  // Wait until SW2 release
	        	         delay_ms(100);                  // Debounce after release
			             
			             flag1=1;                        // Mark medicine as taken
						 CLEARBIT(IOPIN1,BUZZ);        // Deactivate buzzer
		                 
		                 CmdLCD(CLEAR_DISP);             // Clear LCD screen
		                 CmdLCD(GOTO_LINE1_POS0);
		                 StrLCD("MEDICINE INTAKE");      // Intake confirmation
				         CmdLCD(GOTO_LINE2_POS0);
				         StrLCD("COMPLETED...!");
				         
				         delay_s(2);                     // Show message for 2 seconds
					     CmdLCD(CLEAR_DISP);             // Clear LCD
					     break;                          // Exit reminder loop
		             }
		       }

			   /*----------------------------------------------
			     Executed if reminder time expired and
			     user did NOT press confirmation switch
			    ----------------------------------------------*/
			   if(flag1==0)
               {
		          SETBIT(IOPIN1,LED);        // Turn ON LED
                  CLEARBIT(IOPIN0,BUZZ);     // Deactivate buzzer			 		
		          
		          CmdLCD(CLEAR_DISP);         // Clear LCD display
		          CmdLCD(GOTO_LINE1_POS0);
		          StrLCD("MEDICINE INTAKE");  // Display missed alert
		          CmdLCD(GOTO_LINE2_POS0);
		          StrLCD("MISSED...?");
		          
		          delay_s(2);                 // Show message for 2 seconds
                  CmdLCD(CLEAR_DISP);         // Clear LCD
	             }
	   }																					 
}
