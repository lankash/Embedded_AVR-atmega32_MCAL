/*

Code created by "LANKASH"
   @11/9/2021

File contents : 'EEPROM' functions Implementation.

*/

#include <avr/io.h>
#include "my_macros.h"

//#define EEARL *((volatile unsigned char*)(0x3E))    //Write in 'EEARL' REG.
//#define EEARH *((volatile unsigned char*)(0x3f))    //Write in 'EEARH' REG.

//#define EEAR *((volatile unsigned short*)(0x3E))    //Write in the two REGs ('EEARL' & 'EEARH') @ the same time.



void EEPROM_write(unsigned short address, unsigned char data)
{
  EEARL = (char)address;        //Put the Low nibble 'ADDRESS' on 'EEARL' REG. 
  EEARH = (char)(address>>8);   //Put the high nibble 'ADDRESS' on 'EEARH' REG.

  EEDR = data;                  //Write  'DATA'(10-bit) on 'EEARL' & 'EEARH' REGs.   

  SET_BIT(EECR, EEMWE);         //Enable the 'MASTER WRITE ENABLE' bit in 'CONTROL REG'.
  SET_BIT(EECR, EEWE);          //Enable the 'WRITE ENABLE' bit in 'CONTROL REG'.

  while(1 == (READ_BIT(EECR, EEWE)));   //To make shure that the data has been written Successfully.
}


unsigned char EEPROM_read(unsigned short address)
{
  EEARL = (char)address;         //Put the Low nibble 'ADDRESS' on 'EEARL' REG. 
  EEARH = (char)(address>>8);    //Put the High nibble 'ADDRESS' on 'EEARH' REG. 

  SET_BIT(EECR, EERE);           //Enable the 'READ ENABLE' bit in 'CONTROL REG'.

  return EEDR;                   //Return the read vlaue from the 'EEPROM'.
}
