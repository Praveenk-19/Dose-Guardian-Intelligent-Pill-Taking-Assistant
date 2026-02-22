#include "headers.h"    // Contains LCD, GPIO, RTC, delay and data type definitions

/*---------------------------------------------------------
 Function Name : InitLCD
 Purpose       : Initialize LCD in 8-bit mode
 Explanation   : Sends LCD initialization commands as per
                 HD44780 LCD datasheet
----------------------------------------------------------*/
void InitLCD(void)
{
  // Configure LCD data pins and control pins as OUTPUT
  // P0.8–P0.15 → LCD data lines
  // RS, RW, EN → LCD control pins
  IODIR0|=((LCD_DATA<<8)|(1<<RS)|(1<<RW)|(1<<EN));

  delay_ms(20);        // Wait minimum 15 ms after power ON
  CmdLCD(0x30);        // Set LCD to 8-bit mode
  delay_ms(8);         // Wait minimum 5 ms
  CmdLCD(0x30);        // Repeat 8-bit mode command
  delay_ms(1);         // Wait minimum 160 µs
  CmdLCD(0x30);        // Repeat again for reliability
  delay_ms(1);         // Wait minimum 160 µs

  CmdLCD(0x38);        // 8-bit mode, 2-line display, 5×7 font
  CmdLCD(0x08);        // Display OFF
  CmdLCD(0x01);        // Clear display
  CmdLCD(0x06);        // Auto-increment cursor position after every byte
  CmdLCD(0x0c);        // Display ON 
}

/*---------------------------------------------------------
 Function Name : DispLCD
 Purpose       : Send data/command to LCD
 Explanation   : Handles enable pulse and timing
----------------------------------------------------------*/
void DispLCD(u8 Val)
{
  IOCLR0=1<<RW;        // Select WRITE operation
  WRITEBYTE(IOPIN0,8,Val); // Put value on data lines
  IOSET0=1<<EN;        // Enable HIGH
  delay_us(1);         // Enable pulse width
  IOCLR0=1<<EN;        // Enable LOW
  delay_ms(2);         // Command execution delay
}

/*---------------------------------------------------------
 Function Name : CmdLCD
 Purpose       : Send command to LCD
----------------------------------------------------------*/
void CmdLCD(u8 cmd)
{
  IOCLR0=1<<RS;        // Select Instruction Register
  DispLCD(cmd);        // Send command
}

/*---------------------------------------------------------
 Function Name : CharLCD
 Purpose       : Display single character on LCD
----------------------------------------------------------*/
void CharLCD(s8 data)
{
  IOSET0=1<<RS;        // Select Data Register
  DispLCD(data);       // Send character
}

/*---------------------------------------------------------
 Function Name : StrLCD
 Purpose       : Display string on LCD
----------------------------------------------------------*/
void StrLCD(s8 *ptr)
{
  while((*ptr)!='\0')  // Loop until end of string
  {
     CharLCD(*ptr);   // Display each character
	  ptr++;
  }
}

/*---------------------------------------------------------
 Function Name : IntLCD
 Purpose       : Display integer value on LCD
 Explanation   : Converts integer to ASCII and prints
----------------------------------------------------------*/
void IntLCD(s32 num)
{
   s8 a[10],i=0;       // Array to store digits

   if(num==0)
      CharLCD(0+48);  // Display '0'
   else
   {
      if(num<0)       // Check for negative number
	   {
	        CharLCD('-');
		     num=-num;
	   }
	   while(num)       // Extract digits
	   {
	       a[i++]=((num%10)+48); // Convert to ASCII and each element should be stored in Array
	       num/=10;
	   }
	   --i;
	   for(;i>=0;i--)   // Display digits in correct order
	      CharLCD(a[i]);
   }
}

/*---------------------------------------------------------
 Function Name : WriteToCGRAM
 Purpose       : Create custom character in LCD
----------------------------------------------------------*/
void WriteToCGRAM(void)
{
   s8 i,a[]={0x00,0x1f,0x11,0x11,0x11,0x1f,0x00,0x00};
   CmdLCD(0x60);       // Point to CGRAM address
   for(i=0;i<8;i++)
      CharLCD(a[i]);  // Write custom character data
}

/*---------------------------------------------------------
 Function Name : FloatLCD
 Purpose       : Display floating-point number on LCD
----------------------------------------------------------*/
void FloatLCD(f32 num,u32 nDp)
{
   u32 n;
   s32 i;

   if(num<0.0)         // Handle negative number
   {
      CharLCD('-');
	  num=-num;
   }

   n=num;              // Integer part
   IntLCD(n);          
   CharLCD('.');       // Decimal point

   for(i=0;i<nDp;i++)  // Display decimal places
   {
      num=(num-n)*10;
	   n=num;
	   CharLCD(n+48);
   }
}

/*---------------------------------------------------------
 RTC variables
----------------------------------------------------------*/
extern s32 hour,min,sec,date,month,year,day;

/*---------------------------------------------------------
 Function Name : Display_rtc
 Purpose       : Display current RTC time and date on LCD
----------------------------------------------------------*/
void Display_rtc(void)
{
      GetRTCTimeInfo(&hour,&min,&sec);   // Read RTC time
      DisplayRTCTime(hour,min,sec);      // Display time

      GetRTCDateInfo(&date,&month,&year); // Read RTC date
	  DisplayRTCDate(date,month,year);    // Display date

      GetRTCDay(&day);                   // Read RTC day
	  DisplayRTCDay(day);                 // Display day
}

/*---------------------------------------------------------
 Function Name : Display_invalid
 Purpose       : Show invalid input message on LCD
----------------------------------------------------------*/
void Display_invalid(void)
{
      CmdLCD(CLEAR_DISP);                // Clear LCD
      CmdLCD(GOTO_LINE1_POS0);           //Cursor is placed at line 1
	  StrLCD("Invalid Input");           // Error message
      CmdLCD(GOTO_LINE2_POS0);
	  StrLCD("Set Again");
	  delay_ms(900);                     // Display for short time
}
