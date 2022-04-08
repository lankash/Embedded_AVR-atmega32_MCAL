/*
 * interrupt_mcal.h
 *
 * Created: 2/19/2022 8:41:01 AM
 *  Author: "Lankash"
 */ 
 
 #ifndef DIO_H_
 #define DIO_H_
 
 
 /*
    Function name         :  interr_int0
    Function Returns      :  void
    Function Arguments    :  unsigned char sense
    Function Description  :  0 -> Low level sensing
	                         1 -> Any logical change sensing
							 2 -> Falling Edge sensing
							 3 -> Rising Edge sensing
*/
 void interr_int0 (unsigned char sense);
 
 
 /*
    Function name         :  interr_int0
    Function Returns      :  void
    Function Arguments    :  unsigned char sense
    Function Description  :  0 -> Low level sensing
	                         1 -> Any logical change sensing
							 2 -> Falling Edge sensing
							 3 -> Rising Edge sensing
*/
 void interr_int1 (unsigned char sense);
 
 
 /*
    Function name         :  interr_int0
    Function Returns      :  void
    Function Arguments    :  unsigned char sense
    Function Description  :  0 -> Falling Edge sensing
	                         1 -> Rising Edge sensing
*/
 void interr_int2 (unsigned char sense);
 
 
 #endif
 