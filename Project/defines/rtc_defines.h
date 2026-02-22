#ifndef RTC_DEFINES_H
#define RTC_DEFINES_H

/*---------------------------------------------------------
 System Clock Configuration
----------------------------------------------------------*/

// External oscillator frequency (12 MHz crystal)
#define FOSC 12000000

// CPU clock frequency (CCLK = 5 × FOSC = 60 MHz)
#define CCLK (5*FOSC)    

// Peripheral clock frequency (PCLK = CCLK / 4)
#define PCLK (CCLK/4) 


/*---------------------------------------------------------
 RTC Prescaler Calculations
 These values generate 1 second tick from RTC
----------------------------------------------------------*/

// Integer part of RTC prescaler value
#define PREINT_VAL ((PCLK/32768)-1)

// Fractional part of RTC prescaler value
#define PREFRAC_VAL (PCLK-(PREINT_VAL+1)*32768)


/*---------------------------------------------------------
 RTC Control Register (CCR) Bit Definitions
----------------------------------------------------------*/

// Enable RTC counting
#define RTC_ENABLE  (1<<0)

// Reset RTC counters and prescalers
#define RTC_RESET   (1<<1)

// Select RTC clock source
#define RTC_CLKSRC  (1<<4)


/*---------------------------------------------------------
 CPU Selection Macro
 Uncomment if using LPC2148 controller
----------------------------------------------------------*/
//#define CPU_LPC2148

#endif

