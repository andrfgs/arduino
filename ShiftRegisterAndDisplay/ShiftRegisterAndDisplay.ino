//**************************************************************//
//  Name    : shiftOutCode, Hello World                                
//  Author  : Carlyn Maw,Tom Igoe, David A. Mellis 
//  Date    : 25 Oct, 2006    
//  Modified: 23 Mar 2010                                 
//  Version : 2.0                                             
//  Notes   : Code for using a 74HC595 Shift Register           //
//          : to count from 0 to 255                           
//****************************************************************

#include<limits.h>

//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;



void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // count from 0 to 255 and display the number 
  // on the LEDs
  /* (int numberToDisplay = 0; numberToDisplay < 256; numberToDisplay++) {
    // take the latchPin low so 
    // the LEDs don't change while you're sending in bits:
    digitalWrite(latchPin, LOW);
    // shift out the bits:
    shiftOut(dataPin, clockPin, MSBFIRST, numberToDisplay);  

    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
    // pause before next value:
    delay(500);
  }*/

 
  for (int i = 0; i < 7; i++)
  {
    int val = 1 << i;
    val = invertBits(val);
    
    sendNumber(val);
    delay(500);
  }

}

void sendNumber(int val)
{
  digitalWrite(clockPin, LOW);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, val);
  digitalWrite(latchPin, HIGH);
}

int invertBits(int val)
{
  int inverted = LONG_MAX ^ val;

  return inverted;
}

int getBits(int val)
{
  for (int i = 31; i >= 0; i--)
  {
    Serial.print((val >> i) & 1);
  }  

  Serial.print("\n");
}

