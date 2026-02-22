#include "types.h"          

/*---------------------------------------------------------
 Function Name : delay_us
 Description   : Generates delay in microseconds
 Argument      : tdly → delay count in microseconds
 Logic         : Loop count is multiplied to match CPU clock
----------------------------------------------------------*/
void delay_us(u32 tdly)
{
   tdly*=12;              // Scale delay value for 1 microsecond timing
   while(tdly--);         // Empty loop to create time delay
}

/*---------------------------------------------------------
 Function Name : delay_ms
 Description   : Generates delay in milliseconds
 Argument      : tdly → delay count in milliseconds
 Logic         : Loop count adjusted for millisecond delay
----------------------------------------------------------*/
void delay_ms(u32 tdly)
{
    tdly*=12000;          // Scale delay value for 1 millisecond timing
    while(tdly--);        // Empty loop to create time delay
}

/*---------------------------------------------------------
 Function Name : delay_s
 Description   : Generates delay in seconds
 Argument      : tdly → delay count in seconds
 Logic         : Loop count adjusted for second delay
----------------------------------------------------------*/
void delay_s(u32 tdly)
{
    tdly*=12000000;       // Scale delay value for 1 second timing
	  while(tdly--);      // Empty loop to create long time delay
}
