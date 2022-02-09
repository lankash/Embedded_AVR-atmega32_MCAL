/*
 * Timer.h
 *
 * Created: 11/16/2021 6:11:35 PM
 *  Author: "Lankash"
 */ 


#ifndef TIMER_H_              //File Guard
#define TIMER_H_
 
//................................................................


/*
    Function name         :  Timer0_CTC_init_interrupt
    Function Returns      :  void
    Function Arguments    :  unsigned char OCR0_val, unsigned short prescalar.
    Function Description  :  Initialize the Timer in "CTC Interrupt" Mode.
*/
void Timer0_CTC_init_interrupt (unsigned char OCR0_val, unsigned short prescalar);


/*
    Function name         :  Timer2_CTC_init_interrupt
    Function Returns      :  void
    Function Arguments    :  unsigned char OCR0_val, unsigned short prescalar.
    Function Description  :  Initialize Timer2 in "CTC Interrupt" Mode.
*/
void Timer2_CTC_init_interrupt (unsigned char OCR0_val, unsigned short prescalar);    //Initialize Timer2 in "CTC Interrupt" Mode. 


/*
    Function name         :  Timer0_wave_nonPWM
    Function Returns      :  void
    Function Arguments    :  unsigned char OCR0_val, unsigned short prescalar.
    Function Description  :  Generate non_PWM waveform on pin 'OC0'.
*/
void Timer0_wave_nonPWM (unsigned char OCR0_val, unsigned short prescalar);


/*
    Function name         :  Timer1A_wave_nonPWM
    Function Returns      :  void
    Function Arguments    :  unsigned char OCR1A_val, unsigned short prescalar.
    Function Description  :  Generate non_PWM waveform on pin 'OC1A'.
*/
void Timer1A_wave_nonPWM (unsigned char OCR1A_val, unsigned short prescalar);


/*
    Function name         :  Timer1B_wave_nonPWM
    Function Returns      :  void
    Function Arguments    :  unsigned char OCR1B_val, unsigned short prescalar.
    Function Description  :  Generate non_PWM waveform on pin 'OC1B'.
*/
void Timer1B_wave_nonPWM (unsigned char OCR1B_val, unsigned short prescalar);


/*
    Function name         :  Timer2_wave_nonPWM
    Function Returns      :  void
    Function Arguments    :  unsigned char OCR2_val, unsigned short prescalar.
    Function Description  :  Generate non_PWM waveform on pin 'OC2'.
*/
void Timer2_wave_nonPWM (unsigned char OCR2_val, unsigned short prescalar);


/*
    Function name         :  Timer0_fastPWM
    Function Returns      :  void
    Function Arguments    :  unsigned char OCR0_val, unsigned short prescalar, unsigned char inverting.
    Function Description  :  Generate PWM waveform, Inverting @(inverting=1), Non-Inverting @(inverting=0)
*/
void Timer0_fastPWM (unsigned char OCR0_val, unsigned short prescalar, unsigned char inverting);


/*
    Function name         :  Timer2_fastPWM
    Function Returns      :  void
    Function Arguments    :  unsigned char OCR2_val, unsigned short prescalar, unsigned char inverting.
    Function Description  :  Generate PWM waveform, Inverting @(inverting=1), Non-Inverting @(inverting=0)
*/
void Timer2_fastPWM (unsigned char OCR2_val, unsigned short prescalar, unsigned char inverting);


/*
    Function name         :  Timer0_wave_phasecorrectPWM
    Function Returns      :  void
    Function Arguments    :  unsigned char OCR0_val, unsigned short prescalar, unsigned char clr_upcounting.
    Function Description  :  Generate phase correct PWM waveform, Clear OC0 Up-Counting (@clr_upcounting=1), Set OC0 Up-Counting (@clr_upcounting=0).
*/
void Timer0_wave_phasecorrectPWM (unsigned char OCR0_val, unsigned short prescalar, unsigned char clr_upcounting);


/*
    Function name         :  Timer2_wave_phasecorrectPWM
    Function Returns      :  void
    Function Arguments    :  unsigned char OCR2_val, unsigned short prescalar, unsigned char clr_upcounting.
    Function Description  :  Generate phase correct PWM waveform, Clear OC0 Up-Counting (@clr_upcounting=1), Set OC0 Up-Counting (@clr_upcounting=0).
*/
void Timer2_wave_phasecorrectPWM (unsigned char OCR2_val, unsigned short prescalar, unsigned char clr_upcounting);


/*
    Function name         :  Timer2_rtc
    Function Returns      :  void
    Function Arguments    :  unsigned short prescalar.
    Function Description  :  Set Timer_2 for Real time Clock Counter.
*/
void Timer2_rtc (unsigned short prescaler);


//................................................................

#endif /* TIMER_H_ */