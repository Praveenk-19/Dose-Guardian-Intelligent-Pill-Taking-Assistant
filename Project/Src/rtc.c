#include "headers.h"     // Contains RTC registers, LCD functions, data types

/*---------------------------------------------------------
 Array to store day names
 Index : 0 = Sunday, 1 = Monday, ... 6 = Saturday
----------------------------------------------------------*/
s8 week[][4] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};

/*---------------------------------------------------------
 Function Name : RTC_Init
 Purpose       : Initialize Real Time Clock (RTC)
 Explanation   : Resets RTC, sets prescaler values and
                 enables RTC counting
----------------------------------------------------------*/
void RTC_Init(void) 
{
  // Reset and disable RTC before configuration
	CCR = RTC_RESET;

#ifndef CPU_LPC2148
  // Set prescaler values for correct time calculation
	PREINT = PREINT_VAL;
	PREFRAC= PREFRAC_VAL;

  // Enable RTC
	CCR = RTC_ENABLE;  

#else
  // Enable RTC and select clock source (for LPC2148)
	CCR = RTC_ENABLE | RTC_CLKSRC; 

#endif
}

/*---------------------------------------------------------
 Function Name : GetRTCTimeInfo
 Purpose       : Read current RTC time
----------------------------------------------------------*/
void GetRTCTimeInfo(s32 *hour, s32 *minute, s32 *second)
{
	*hour = HOUR;     // Read hour register
	*minute = MIN;   // Read minute register
	*second = SEC;   // Read second register
}

/*---------------------------------------------------------
 Function Name : DisplayRTCTime
 Purpose       : Display time on LCD in HH:MM:SS format
----------------------------------------------------------*/
void DisplayRTCTime(u32 hour, u32 minute, u32 second)
{
	CmdLCD(GOTO_LINE1_POS0);   // Go to first line on LCD

	CharLCD((hour/10)+48);    // Display hour tens digit
	CharLCD((hour%10)+48);    // Display hour units digit
    CharLCD(':');

	CharLCD((minute/10)+48);  // Display minute tens digit
    CharLCD((minute%10)+48);  // Display minute units digit
	CharLCD(':');

    CharLCD((second/10)+48);  // Display second tens digit
    CharLCD((second%10)+48);  // Display second units digit
}

/*---------------------------------------------------------
 Function Name : GetRTCDateInfo
 Purpose       : Read current RTC date
----------------------------------------------------------*/
void GetRTCDateInfo(s32 *date, s32 *month, s32 *year)
{
	*date = DOM;     // Read date (day of month)
	*month = MONTH; // Read month
	*year = YEAR;   // Read year
}

/*---------------------------------------------------------
 Function Name : DisplayRTCDate
 Purpose       : Display date on LCD in DD/MM/YYYY format
----------------------------------------------------------*/
void DisplayRTCDate(u32 date, u32 month, u32 year)
{
	CmdLCD(GOTO_LINE2_POS0);   // Go to second line on LCD

	CharLCD((date/10)+48);    // Date tens digit
	CharLCD((date%10)+48);    // Date units digit
	CharLCD('/');

	CharLCD((month/10)+48);   // Month tens digit
	CharLCD((month%10)+48);   // Month units digit
	CharLCD('/');

	IntLCD(year);             // Display full year
}

/*---------------------------------------------------------
 Function Name : SetRTCTimeInfo
 Purpose       : Set RTC time
----------------------------------------------------------*/
void SetRTCTimeInfo(u32 hour, u32 minute, u32 second)
{
	HOUR = hour;    // Set hour register
	MIN = minute;  // Set minute register
	SEC = second;  // Set second register
}

/*---------------------------------------------------------
 Function Name : SetRTCDateInfo
 Purpose       : Set RTC date
----------------------------------------------------------*/
void SetRTCDateInfo(u32 date, u32 month, u32 year)
{
	DOM = date;     // Set day of month
	MONTH = month; // Set month
	YEAR = year;   // Set year	
}

/*---------------------------------------------------------
 Function Name : GetRTCDay
 Purpose       : Read current day of week
----------------------------------------------------------*/
void GetRTCDay(s32 *day)
{
	*day = DOW;     // Read Day Of Week register
}

/*---------------------------------------------------------
 Function Name : DisplayRTCDay
 Purpose       : Display day name on LCD
----------------------------------------------------------*/
void DisplayRTCDay(u32 dow)
{
	CmdLCD(GOTO_LINE1_POS0+10); // Move cursor to right side
	StrLCD(week[dow]);          // Display day name (SUN, MON, etc.)
}

/*---------------------------------------------------------
 Function Name : SetRTCDay
 Purpose       : Set day of the week in RTC
----------------------------------------------------------*/
void SetRTCDay(u32 day)
{
	DOW = day;      // Set Day Of Week register
}
