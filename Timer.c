/*
 * Timer.c
 *
 * Created: 11/16/2021 6:11:11 PM
 *  Author: "Lankash"
 */ 

//..................................................
#include <avr/io.h>
#include <avr/interrupt.h>

#include "my_macros.h"
#include "timer.h"
#include "DIO.h"
//..................................................

void Timer0_CTC_init_interrupt (unsigned char OCR0_val, unsigned short prescalar)    //Initialize the Timer in "CTC Interrupt" Mode. 
{
	CLR_BIT(TCCR0, WGM00);          //Set CTC Mode
	SET_BIT(TCCR0, WGM01);     
	
	//Select the Timer Clock PRESCALER.
	switch (prescalar)
	{
		case 0 :                  //No Prescaler
		CLR_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
                break;
		
		case 8 :                 //Prescaler = 8
		CLR_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS02);
		break;

		case 64 :                //Prescaler = 64
		SET_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS02);
		break;

		case 256 :               //Prescaler = 256
		CLR_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
                break;		
		
		case 1024 :              //Prescaler = 1024
		SET_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
                break;	
         }
	
	OCR0 = OCR0_val;           //Load value in [OCR0]
	  
	sei();                    //Enable Global interrupt.
	SET_BIT(TIMSK, OCIE0);    //Enable CTC interrupt.
}

//...............................................................

void Timer2_CTC_init_interrupt (unsigned char OCR0_val, unsigned short prescalar)    //Initialize the Timer in "CTC Interrupt" Mode. 
{
	CLR_BIT(TCCR2, WGM20);          //Set CTC Mode
	SET_BIT(TCCR2, WGM21);     
	
	//Select the Timer Clock PRESCALER.
	switch (prescalar)
	{
		case 0 :                  //No Prescaler
		CLR_BIT(TCCR2, CS20);
		CLR_BIT(TCCR2, CS21);
		SET_BIT(TCCR2, CS22);
                break;
		
		case 8 :                 //Prescaler = 8
		CLR_BIT(TCCR2, CS20);
		SET_BIT(TCCR2, CS21);
		CLR_BIT(TCCR2, CS22);
		break;

		case 64 :                //Prescaler = 64
		SET_BIT(TCCR2, CS20);
		SET_BIT(TCCR2, CS21);
		CLR_BIT(TCCR2, CS22);
		break;

		case 256 :               //Prescaler = 256
		CLR_BIT(TCCR2, CS20);
		CLR_BIT(TCCR2, CS21);
		SET_BIT(TCCR2, CS22);
                break;		
		
		case 1024 :              //Prescaler = 1024
		SET_BIT(TCCR2, CS20);
		CLR_BIT(TCCR2, CS21);
		SET_BIT(TCCR2, CS22);
                break;	
         }
	
	OCR0 = OCR0_val;           //Load value in [OCR0]
	  
	sei();                    //Enable Global interrupt.
	SET_BIT(TIMSK, OCIE0);    //Enable CTC interrupt.
}

//...............................................................

void Timer0_wave_nonPWM (unsigned char OCR0_val, unsigned short prescalar)
{
	//SET "OCn" pins.
	//DIO_set_pin_dir('B', 3, 1);     //Set "OC0" pin as O/P
	SET_BIT(DDRB, 3);
	
	//Select the Timer Clock PRESCALER.
	switch (prescalar)
	{
		case 0 :                  //No Prescaler
		CLR_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
		break;
		
		case 8 :                 //Prescaler = 8
		CLR_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS02);
		break;
		
		case 64 :                //Prescaler = 64
		SET_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS02);
		break;
		
		case 256 :               //Prescaler = 256
		CLR_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
		break;
		
		case 1024 :              //Prescaler = 1024
		SET_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
		break;
	}
    
	CLR_BIT(TCCR0, WGM00);          //Set CTC Mode
	SET_BIT(TCCR0, WGM01);
	
	OCR0 = OCR0_val;               //OCR0_val 78  =>   Value to be assigned in the [OCR0].
	                               //@M.C Freq.= 8 MHz --> Timer Freq.= 7.8125 KHz --> Tick time = 128 micro Sec. --> 10 mSec = 78.125 counts in OCR

	
	//Set Toggle "OC0" on compare match.
	SET_BIT(TCCR0, COM00);
	CLR_BIT(TCCR0, COM01);
}

//...............................................................

void Timer1A_wave_nonPWM (unsigned char OCR1A_val, unsigned short prescalar)
{
	//SET "OC1A" pins.
	DIO_set_pin_dir('D', 5, 1);     //Set "OC1A" pin as O/P
	SET_BIT(DDRD, 5);
	
	//Select the Timer Clock PRESCALER.
	switch (prescalar)
	{
		case 0 :                  //No Prescaler
		CLR_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
		break;
		
		case 8 :                 //Prescaler = 8
		CLR_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS02);
		break;
		
		case 64 :                //Prescaler = 64
		SET_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS02);
		break;
		
		case 256 :               //Prescaler = 256
		CLR_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
		break;
		
		case 1024 :              //Prescaler = 1024
		SET_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
		break;
	}
	
	CLR_BIT(TCCR0, WGM00);          //Set CTC Mode
	SET_BIT(TCCR0, WGM01);
	
	OCR1A = OCR1A_val;               //OCR0_val 78  =>   Value to be assigned in the [OCR0].
	//@M.C Freq.= 8 MHz --> Timer Freq.= 7.8125 KHz --> Tick time = 128 micro Sec. --> 10 mSec = 78.125 counts in OCR

	
	//Set Toggle "OC0" on compare match.
	SET_BIT(TCCR0, COM00);
	CLR_BIT(TCCR0, COM01);
}

//...............................................................

void Timer1B_wave_nonPWM_OC1B (unsigned char OCR1B_val, unsigned short prescalar)
{
	//SET "OC1A" pins.
	//DIO_set_pin_dir('D', 4, 1);     //Set "OC1A" pin as O/P
	SET_BIT(DDRD, 4);
	
	//Select the Timer Clock PRESCALER.
	switch (prescalar)
	{
		case 0 :                  //No Prescaler
		CLR_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
		break;
		
		case 8 :                 //Prescaler = 8
		CLR_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS02);
		break;
		
		case 64 :                //Prescaler = 64
		SET_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS02);
		break;
		
		case 256 :               //Prescaler = 256
		CLR_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
		break;
		
		case 1024 :              //Prescaler = 1024
		SET_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
		break;
	}
	
	CLR_BIT(TCCR0, WGM00);          //Set CTC Mode
	SET_BIT(TCCR0, WGM01);
	
	OCR1B = OCR1B_val;               //OCR0_val 78  =>   Value to be assigned in the [OCR0].
	//@M.C Freq.= 8 MHz --> Timer Freq.= 7.8125 KHz --> Tick time = 128 micro Sec. --> 10 mSec = 78.125 counts in OCR

	
	//Set Toggle "OC0" on compare match.
	SET_BIT(TCCR0, COM00);
	CLR_BIT(TCCR0, COM01);
}

//...............................................................

void Timer2_wave_nonPWM (unsigned char OCR2_val, unsigned short prescalar)
{
	//SET "OC1A" pins.
	//DIO_set_pin_dir('D', 7, 1);     //Set "OC1A" pin as O/P
	SET_BIT(DDRD, 7);
	
	//Select the Timer Clock PRESCALER.
	switch (prescalar)
	{
	  case 0 :                  //No Prescaler
       	CLR_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	SET_BIT(TCCR0, CS02);
        break;
	
	  case 8 :                 //Prescaler = 8
	CLR_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);
        break;
	
	  case 64 :                //Prescaler = 64
	SET_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);
        break;
	
	  case 256 :               //Prescaler = 256
	CLR_BIT(TCCR0, CS00); 
	CLR_BIT(TCCR0, CS01);
	SET_BIT(TCCR0, CS02);
        break;
	
	  case 1024 :              //Prescaler = 1024
	SET_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	SET_BIT(TCCR0, CS02);
        break;
	}
	
	CLR_BIT(TCCR0, WGM00);          //Set CTC Mode
	SET_BIT(TCCR0, WGM01);
	
	OCR2 = OCR2_val;               //OCR0_val 78  =>   Value to be assigned in the [OCR0].
	//@M.C Freq.= 8 MHz --> Timer Freq.= 7.8125 KHz --> Tick time = 128 micro Sec. --> 10 mSec = 78.125 counts in OCR

	
	//Set Toggle "OC0" on compare match.
	SET_BIT(TCCR0, COM00);
	CLR_BIT(TCCR0, COM01);
}

//...............................................................

void Timer0_fastPWM (unsigned char OCR0_val, unsigned short prescalar, unsigned char inverting)   //Inverting @ "inverting" = 1.
{
	DIO_set_pin_dir('B', 3, 1);     //Set OC0 as O/P pin
	
    //Set Control bits to "Fast PWM" mode.
	SET_BIT(TCCR0, WGM00);
    SET_BIT(TCCR0, WGM01);
	
	//Select the Timer Clock PRESCALAR.
	switch (prescalar)
	{
		case 0 :                   //No Prescaler
		CLR_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
                break;
		
		case 8 :                   //Prescaler = 8
		CLR_BIT(TCCR0, CS00);  
		SET_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS02);
                break;
		
		case 64 :                  //Prescaler = 64
		SET_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS02);
                break;
		
		case 256 :                 //Prescaler = 256
		CLR_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
                break;
		
		case 1024 :                //Prescaler = 1024
		SET_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
                break;
	}
	
	OCR0 = OCR0_val;               //Load value in [OCR0]

     switch (inverting)
 	{
 		case 0 :                   //Clear OC0 on compare match, clear OC0 at Bottom, Non-Inverting mode.
 		CLR_BIT(TCCR0, COM00);
		SET_BIT(TCCR0, COM01);
                break;
 		
 		case 1 :                   //Set OC0 on compare match, clear OC0 at Bottom, Inverting mode.
 		SET_BIT(TCCR0,COM00);
                SET_BIT(TCCR0,COM01);
                break;
 	}
}

//...............................................................

void Timer2_fastPWM (unsigned char OCR2_val, unsigned short prescalar, unsigned char inverting)   //Inverting @ "inverting" = 1.
{
	DIO_set_pin_dir('D', 7, 1);     //Set OC0 as O/P pin
	
	//Set Control bits to "Fast PWM" mode.
	SET_BIT(TCCR2, WGM20);
	SET_BIT(TCCR2, WGM21);
	
	//Select the Timer Clock PRESCALAR.
	switch (prescalar)
	{
		case 0 :                   //No Prescaler
		CLR_BIT(TCCR2, CS20);
		CLR_BIT(TCCR2, CS21);
		SET_BIT(TCCR2, CS22);
                break;
		
		case 8 :                   //Prescaler = 8
		CLR_BIT(TCCR2, CS20);
		SET_BIT(TCCR2, CS21);
		CLR_BIT(TCCR2, CS22);
                break;
		
		case 64 :                  //Prescaler = 64
		SET_BIT(TCCR2, CS20);
		SET_BIT(TCCR2, CS21);
		CLR_BIT(TCCR2, CS22);
                break;
		
		case 256 :                 //Prescaler = 256
		CLR_BIT(TCCR2, CS20);
		CLR_BIT(TCCR2, CS21);
		SET_BIT(TCCR2, CS22);
                break;
		
		case 1024 :                //Prescaler = 1024
		SET_BIT(TCCR2, CS20);
		CLR_BIT(TCCR2, CS21);
		SET_BIT(TCCR2, CS22);
                break;
	}
	
	OCR2 = OCR2_val;               //Load value in [OCR0]

	switch (inverting)
	{
		case 0 :                   //Clear OC0 on compare match, clear OC0 at Bottom, Non-Inverting mode.
		CLR_BIT(TCCR0, COM20);
		SET_BIT(TCCR0, COM21);
                break;
		
		case 1 :                   //Set OC0 on compare match, clear OC0 at Bottom, Inverting mode.
		SET_BIT(TCCR2, COM20);
		SET_BIT(TCCR2, COM21);
                break;
	}

}

//...............................................................

void Timer0_wave_phasecorrectPWM (unsigned char OCR0_val, unsigned short prescalar, unsigned char clr_upcounting)
{
	DIO_set_pin_dir('B', 3, 1);     //Set OC0 as O/P pin
	
	//Set Control bits to "Fast PWM" mode.
	SET_BIT(TCCR0, WGM00);
	CLR_BIT(TCCR0, WGM01);
	
	OCR0 = OCR0_val;               //Load value in [OCR0]
	
	//Select the Timer Clock PRESCALAR.
	switch (prescalar)
	{
		case 0 :                   //No Prescaler
		CLR_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
                break;
		
		case 8 :                   //Prescaler = 8
		CLR_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS02);
                break;
		
		case 64 :                  //Prescaler = 64
		SET_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS02);
                break;
		
		case 256 :                 //Prescaler = 256
		CLR_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS00);
                break;
		
		case 1024 :                //Prescaler = 1024
		SET_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
                break;
	}
	
	switch (clr_upcounting)
	{
		case 0 :                   //Clear OC0 on compare match when up-counting.
		SET_BIT(TCCR0, COM00);
		SET_BIT(TCCR0, COM01);
                break;
		
		case 1 :                   //Set OC0 on compare match when up-counting.
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
                break;
	}
}

//...............................................................

void Timer_wave_phasecorrectPWM_OC2 (unsigned char OCR2_val, unsigned short prescalar, unsigned char clr_upcounting)
{
	DIO_set_pin_dir('D', 7, 1);     //Set OC2 as O/P pin
	
	//Set Control bits to "Fast PWM" mode.
	SET_BIT(TCCR2, WGM20);
	CLR_BIT(TCCR2, WGM21);
	
	OCR2 = OCR2_val;               //Load value in [OCR2]
	
	//Select the Timer Clock PRESCALAR.
	switch (prescalar)
	{
		case 0 :                   //No Prescaler
		CLR_BIT(TCCR2, CS20);
		CLR_BIT(TCCR2, CS21);
		SET_BIT(TCCR2, CS22);
                break;
		
		case 8 :                   //Prescaler = 8
		CLR_BIT(TCCR2, CS20);
		SET_BIT(TCCR2, CS21);
		CLR_BIT(TCCR2, CS22);
                break;
		
		case 64 :                  //Prescaler = 64
		SET_BIT(TCCR2, CS20);
		SET_BIT(TCCR2, CS21);
		CLR_BIT(TCCR2, CS22);
                break;
		
		case 256 :                 //Prescaler = 256
		CLR_BIT(TCCR2, CS20);
		CLR_BIT(TCCR2, CS21);
		SET_BIT(TCCR2, CS22);
                break;
		
		case 1024 :                //Prescaler = 1024
		SET_BIT(TCCR2, CS20);
		CLR_BIT(TCCR2, CS21);
		SET_BIT(TCCR2, CS22);
                break;
	}
	
	switch (clr_upcounting)
	{
		case 0 :                   //Clear OC0 on compare match when up-counting.
		SET_BIT(TCCR2, COM20);
		SET_BIT(TCCR2, COM21);
                break;
		
		case 1 :                   //Set OC0 on compare match when up-counting.
		CLR_BIT(TCCR2,COM20);
		SET_BIT(TCCR2,COM21);
                break;
	}
}

//...............................................................

void Timer2_rtc (unsigned short prescaler)
{
	
	SET_BIT (ASSR, 3);    //Set Asynchronous timer; Out-Source Crystal (32.125 kh)
	
	//Select the Timer Clock PRESCALAR.
	switch (prescalar)
	{
		case 0 :                   //No Prescaler
		CLR_BIT(TCCR2, CS20);
		CLR_BIT(TCCR2, CS21);
		SET_BIT(TCCR2, CS22);
                break;
		
		case 8 :                   //Prescaler = 8
		CLR_BIT(TCCR2, CS20);
		SET_BIT(TCCR2, CS21);
		CLR_BIT(TCCR2, CS22);
                break;
		
		case 64 :                  //Prescaler = 64
		SET_BIT(TCCR2, CS20);
		SET_BIT(TCCR2, CS21);
		CLR_BIT(TCCR2, CS22);
                break;
		
		case 256 :                 //Prescaler = 256
		CLR_BIT(TCCR2, CS20);
		CLR_BIT(TCCR2, CS21);
		SET_BIT(TCCR2, CS22);
                break;
		
		case 1024 :                //Prescaler = 1024
		SET_BIT(TCCR2, CS20);
		CLR_BIT(TCCR2, CS21);
		SET_BIT(TCCR2, CS22);
                break;
	}
	
	sei ();                    //Enable global Interrupt bit.
	SET_BIT (TIMSK, TOIE2)     //Enable Timer 2 interrupt.
}