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
 ****************************************************/

#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"

DFRobotDFPlayerMini myDFPlayer;
HardwareSerial MySerial(1);

int buttonPin = 4;
int buttonState = HIGH;            // the current reading from the input pin
int lastButtonState = HIGH;  // the previous reading from the input pin
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers
int counter = 0;

bool sound = false;

void setup() {
  MySerial.begin(9600, SERIAL_8N1, 16, 17); 
  myDFPlayer.begin(MySerial);

  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);  //Play the first mp3
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);  //Play the first mp3
  myDFPlayer.volume(30);  //Set volume value. From 0 to 30

  delay(5);
  pinMode(buttonPin, INPUT_PULLUP);
  
  Serial.begin(9600);


}

void loop() {

  int reading = digitalRead(buttonPin);

 if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

    if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
        counter = counter +1;
        sound = !sound;
      }
    }
  }
  
  lastButtonState = reading;

  Serial.println(sound);


if (sound == true){
  myDFPlayer.start();
} else {
  myDFPlayer.pause();
}
}

