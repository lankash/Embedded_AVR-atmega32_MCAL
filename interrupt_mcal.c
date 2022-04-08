/*
 * interrupt_mcal.c
 *
 * Created: 2/19/2022 8:41:01 AM
 *  Author: "Lankash"
 */ 
 
 
 #include <avr/io.h>
 #include <avr/interrupt.h>
 #include "my_macros.h"
 #include "DIO.h"
 
 
 //.............................................................................
 
 void interr_int0 (unsigned char sense)  //Enable external interrupt for pin 'PD2'
 { 
	 sei();                           //Enable Global Interrupt bit.
	 SET_BIT (GICR, INT0);            //Enable INT0 pin Interrupt
	 DIO_set_pin_dir('D', 2, 0);      //Set INT0 pin as I/P
	 
	 switch (sense)
	 {
		 case 0:                //Low level sensing
		 CLR_BIT (MCUCR, 0);    //ISC00
		 CLR_BIT (MCUCR, 1);    //ISC01
		 
		 case 1:                //Any logical change sensing
		 SET_BIT (MCUCR, 0);    //ISC00
		 CLR_BIT (MCUCR, 1);    //ISC01
		 
		 case 2:                //Falling Edge sensing
		 CLR_BIT (MCUCR, 0);    //ISC00
		 SET_BIT (MCUCR, 1);    //ISC01
		 
		 case 3:                //Rising Edge change
		 SET_BIT (MCUCR, 0);    //ISC00
		 SET_BIT (MCUCR, 1);    //ISC01
	 }
 }
 
 //............................................................................
 
 void interr_int1 (unsigned char sense)  //Enable external interrupt for pin 'PD3'
 {
	 sei();                           //Enable Global Interrupt bit.
	 SET_BIT (GICR, INT1);            //Enable INT1 pin Interrupt
	 DIO_set_pin_dir('D', 2, 0);      //Set INT1 pin as I/P
	 
	 switch (sense)
	 {
		 case 0:                //Low level sensing
		 CLR_BIT (MCUCR, 2);    //ISC10
		 CLR_BIT (MCUCR, 3);    //ISC11
		 
		 case 1:                //Any logical change sensing
		 SET_BIT (MCUCR, 2);    //ISC10
		 CLR_BIT (MCUCR, 3);    //ISC11
		 
		 case 2:                //Falling Edge sensing
		 CLR_BIT (MCUCR, 2);    //ISC10
		 SET_BIT (MCUCR, 3);    //ISC11
		 
		 case 3:                //Rising Edge change
		 SET_BIT (MCUCR, 2);    //ISC10
		 SET_BIT (MCUCR, 3);    //ISC11
	 }
 }
 
 //..........................................................................
 
 void interr_int2 (unsigned char sense)  //Enable external interrupt for pin 'PB2'
 {
	 sei();                           //Enable Global Interrupt bit.
	 SET_BIT (GICR, INT2);            //Enable INT2 pin Interrupt.
	 DIO_set_pin_dir('B', 2, 0);      //Set INT2 pin as I/P
	 
	 switch (sense)
	 {
		 case 0:                 //Falling Edge sensing
		 CLR_BIT (MCUCSR, 6);    //ISC2
		 
		 case 1:                //Rising Edge sensing
		 SET_BIT (MCUCSR, 6);    //ISC2
	 }
 }
 
 //......................................................................