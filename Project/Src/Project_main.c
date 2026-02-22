#include "headers.h"     // Includes LCD, keypad, RTC, delay and data types

/*---------------------------------------------------------
 Global variables
----------------------------------------------------------*/
s32 hour,min,sec,date,month,year,day;     // RTC current time and date variables
s32 med_hour,med_min,flag,check_med_time;       // Medicine time variables and control flag

/*---------------------------------------------------------
 main function
 Description : Entry point of the program
----------------------------------------------------------*/
int main()
{
	  /* Configure LED and BUZZER pins as OUTPUT */
	  IODIR1|=((1<<BUZZ)|(1<<LED));	 // LED and BUZZER output direction

	  InitLCD();      // Initialize LCD display
	  KeyPadInit();   // Initialize keypad
	  RTC_Init();     // Initialize RTC module

      /* Set initial reference RTC time (HH:MM:SS) */
	  SetRTCTimeInfo(12,50,39);

      /* Set initial reference RTC date (DD/MM/YYYY) */						
	  SetRTCDateInfo(19,2,2003);

      /* Set initial reference RTC day (0–6) */
      SetRTCDay(3);

	  /* Super loop or Infinite loop*/
	  while(1)
	  {
	   	   /* Display RTC time, date and day on LCD */
		   Display_rtc();

           /* Check if SW1 is pressed (active LOW) */
           if((READBIT(IOPIN0,SW1))==0)	         // Waiting for SW1 press
		   {
		          delay_ms(100);                // Switch debounce delay
		          while((READBIT(IOPIN0,SW1))==0);  // Wait until SW1 release
	              delay_ms(100);                // Debounce after release
				  menu();                      // Call menu function
		   }

		   /* If medicine reminder is enabled */
		   if((flag==1)  && (check_med_time==0))
		          compare_rtc_with_med_time(); // Compare RTC time with medicine time
	  }
}

