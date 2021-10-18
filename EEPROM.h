/*

Code Created by "LANKASH" 
  @ 11/9/2021

File Contents : 'EEPROM' Function Prototypes. 

*/

#ifndef EEPROM_H_
#define EEPROM_H_


/*
    Function name         :  EEPROM_write
    Function Returns      :  void
    Function Arguments    :  unsigned short address, unsigned char data
    Function Description  :  Write a value in the 'EEPROM'
*/
void EEPROM_write(unsigned short address, unsigned char data);

/*
    Function name         :  EEPROM_read
    Function Returns      :  unsigned short
    Function Arguments    :  unsigned short address
    Function Description  :  Read a value from the 'EEPROM'
*/
unsigned char EEPROM_read(unsigned short address);

#endif
