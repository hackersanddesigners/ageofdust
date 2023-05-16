/***************************************************
Emma Pareschi - April 2023

This is a test code to confirm that the DFPlayer can be controlled by attiny.

Connections:

Attiny45 -- DFPlayer
VCC -- VCC
GND -- GND
PB1 -- TX
PB2 -- RX

The speaker is connected to pins SPK_1 and SPK_2 of the DFPlayer
 ****************************************************/

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(1, 2); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

void setup()
{
  mySoftwareSerial.begin(9600);
  myDFPlayer.begin(mySoftwareSerial);

  myDFPlayer.volume(20);  //Set volume value. From 0 to 30
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);  //Play the first mp3
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);  //Play the first mp3
}

void loop()
{
    myDFPlayer.play(1);  //Play the first mp3
    delay(10000); //wait 10sec

}

