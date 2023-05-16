/***************************************************
Emma Pareschi - April 2023

This is a test code to confirm that the DFPlayer can be controlled by the esp32.
This code was tested with the DOIT esp32 DEVKIT 30pins

Connections:

ESP32 DEVKIT -- DFPlayer
3V -- VCC
GND -- GND
RX2 (GPIO16) -- TX
TX2 (GPIO17) -- RX

The speaker is connected to pins SPK_1 and SPK_2 of the DFPlayer

The track 0001.mp3 in the sdcard plays continuosly. 
 ****************************************************/

#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"

DFRobotDFPlayerMini myDFPlayer;
HardwareSerial MySerial(1);


void setup() {
  MySerial.begin(9600, SERIAL_8N1, 16, 17); 
  myDFPlayer.begin(MySerial);

  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);  //Play the first mp3
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);  //Play the first mp3
  myDFPlayer.volume(30);  //Set volume value. From 0 to 30

  Serial.begin(9600);

}

void loop()
{
    myDFPlayer.play(1);  //Play the first mp3

    while(myDFPlayer.readState()!=513){
     Serial.println(myDFPlayer.readState());

     }
     Serial.println("");
     Serial.println("Song starts");

     while(myDFPlayer.readState()==513){
     Serial.print(".");
       delay(100);
     }
     Serial.println("");
     Serial.println("Song done");

}

