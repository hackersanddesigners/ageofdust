
/***************************************************
Emma Pareschi - April 2023

This is a test code to confirm that the DFPlayer can be controlled by attiny.

Connections:

DIGISPARK -- DFPLAYER
VCC       -- VCC
GND       -- GND
PB1       -- TX
PB2       -- RX

The speaker is connected to pins SPK_1 and SPK_2 of the DFPlayer

 ****************************************************/

#include "Arduino.h"
// #include "SoftwareSerial.h"   //>> DOESN'T WORK W DIGISPARK BOARD
#include <SoftSerial.h>           // >> USE DIGISPARK SOFTSERIAL! 
#include "DFRobotDFPlayerMini.h"

SoftSerial mySoftwareSerial(1, 2); // RX, TX   // CHANGED TO SOFTSERIAL TO MATCH DIGISPARK LIB
DFRobotDFPlayerMini myDFPlayer;

void setup()
{
  mySoftwareSerial.begin(9600);
  myDFPlayer.begin(mySoftwareSerial);

  myDFPlayer.volume(20);  //Set volume value. From 0 to 30
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);  //Select equalizer mode
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);  //Select output device
}

void loop()
{
    myDFPlayer.play(1);  //Play the first mp3 for 10 secs
    delay(10000); 

    myDFPlayer.play(2);  //Play the second mp3 for 10 secs
    delay(10000); 
}
