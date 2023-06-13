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

Digital sensor connected between pin D4 and GND
 ****************************************************/

#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"

DFRobotDFPlayerMini myDFPlayer;
HardwareSerial MySerial(1);

int sensor_pin = 4;


void setup() {
  MySerial.begin(9600, SERIAL_8N1, 16, 17); 
  myDFPlayer.begin(MySerial);

  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);  //Play the first mp3
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);  //Play the first mp3
  myDFPlayer.volume(30);  //Set volume value. From 0 to 30

  delay(5);
  pinMode(sensor_pin, INPUT_PULLUP);


}

void loop() {

  
  if(!digitalRead(sensor_pin)){
    myDFPlayer.start();  //Play the first mp3
  }
    //delay(30000); //wait 10sec

}

