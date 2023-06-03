
/***************************************************
  Emma Pareschi - April 2023

  This is a test code to confirm that the DFPlayer can be controlled by attiny.

  Connections:

  Attiny45 -- DFPlayer
  VCC -- VCC
  GND -- GND
  PB1 -- TX
  PB2 -- RX
  PB3 -- digital input from one of the modules

  The speaker is connected to pins SPK_1 and SPK_2 of the DFPlayer

  MODIFICATIONS - NOT TESTED 

  Loes - june 2023

  add switch on PB3
  with each press, go to next track and play for 10 secs

 ****************************************************/

#include "Arduino.h"
// #include "SoftwareSerial.h"   // USE THIS ONE WITH ATTINY85 (comes w IDE)
#include <SoftSerial.h>           // DIGISPARK SOFTSERIAL (when using digispark board) 
#include "DFRobotDFPlayerMini.h"

SoftSerial mySoftwareSerial(1, 2); // RX, TX   // CHANGED TO SOFTSERIAL TO MATCH DIGISPARK LIB
DFRobotDFPlayerMini myDFPlayer;

const int switchPin = 3;

int switchState = 0;
int preState = 1;
int trackSelector = 0; //
int trackAmount = 2;  //put total number of mp3s on SD here

void setup()
{
  mySoftwareSerial.begin(9600);
  myDFPlayer.begin(mySoftwareSerial);

  myDFPlayer.volume(20);  //Set volume value. From 0 to 30
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);  //Select equalizer mode
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);  //Select output device

  pinMode(switchPin, INPUT);
}

void loop() {

  switchState = digitalRead(switchPin);

  if (switchState == 1 && preState == 0) {
    trackSelector++;
    if (trackSelector > trackAmount) {
      trackSelector = 0;
    }
    preState = 1;
  } else if (switchState == 0) {
    preState = 0;
  }

  if (trackSelector == 0) {
    // do nothing
  }

  if (trackSelector > 0) {
    myDFPlayer.play(trackSelector);  //Play the first mp3 for 10 secs
    delay(10000);
  }
}
