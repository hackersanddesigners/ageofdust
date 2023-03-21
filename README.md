# Age of Dust

Research for age of dust tools as part of worldbuilding.

## Wishes

* record and playback audio (both single track that overwrites, and multiple that are stored and can be played later)
* freedom in designing the interaction with the tool and how it looks
	* no-coding options will help with this
* possibility to recycle hardware parts
* walkie-talkie-like system could be fun 


## Update for Emma and questions

* Juliette and I love all these options and would like to offer them all :) <3
* Loud sound is not a must, Juliette is interested in a "different ways of listening" approach <3 <3
* DIY switch examples here [./switches/diyswitches.md](./switches/diyswitches.md)
* I added a solar power option at the bottom that we've used before, we have some of these in the studio, so might be worth taking a look? YES
* I found a nice walkie talkie option which I opened up, looks promising (see below)
* I listed all components in a spreadsheet with some info on operating voltages, supplier link and prices etc so we can keep track easily, see [files > components.xlsx](./files/components.xlsx). I also added some other options here that might be fun (in blue and red).

#### ISD1820:
* ISD1820 all options, input and output (all wiring diagrams) See here [./files > ISD1820_wiring.pptx](./files/ISD1820_wiring.pptx)

To do:
* power source: 
 - check the spec of the solar panel kit.
 - add reference for dynamo charger
 - evalute wind turbine

#### DF MP3 player:
* Controlling DF player w resistors needs to be quite precise to get all buttons to play different track. I need to look into this a bit more to see which work well with (a combination of) standard resistors. 
	* Could be smart to figure out how to control with an ESP32 wroom devkit? (we have a bunch of those and they're cheap, looks like is possible). Can be controlled via UART (e.g. Arduino UNO, but have also seen [examples with ESP32](https://youtu.be/kq2RLz65_w0), which we have few of at H&D? Looked into ATtiny85 digispark a bit, [could work](https://github.com/wagiminator/ATtiny85-TinyDFPlayer) with some tuning of the internal oscillator, but not super easy I guess.

To do:
* check mp3 module with ESP32 wroom devkit
* check mp3 module with attiny85


## Questions for Juliette

* how many participants are we thinking? > 10-20 working in pairs
* it could be cool to go [soft](https://www.kobakant.at/DIY/) (wearable props), but this is an entirely different making process. Could also be wearable but hard :)
* What kind of materials would you prefer for casings? Natural materials? Plastics? Recycled? Integrated into costume?

## Budget

Max € 750 for all materials, components, tools


## Workflow

* Research some options to make sure things work together, based on wishes
* Document some examples for participants on how things work/connect
* The actual exploration - building tools for the script - will happen in the workshop

## Audio in: recording & playback

### MP3 player €7.50

You can play the audio tracks saved in an SD card. You can trigger the different tracks by attaching switches/buttons to the different pins. You can customize the button and the speakers. See below.

[Via tinytronics](https://www.tinytronics.nl/shop/en/audio/audio-sources/dfrobot-dfplayer-mini-mp3-module)

[Documentation](https://wiki.dfrobot.com/DFPlayer_Mini_SKU_DFR0299)

Upside:

* can be triggered w resistors + switch combos, no microcontroller
* can be controlled via UART (e.g. Arduino UNO, but have also seen [examples with ESP32](https://youtu.be/kq2RLz65_w0), which we have few of at H&D? Looked into ATtiny85 digispark a bit, [could work](https://github.com/wagiminator/ATtiny85-TinyDFPlayer) with some tuning of the internal oscillator, but not super easy I guess.

Downside: 

* not typical values so need to do series of several resistors, not super stable it seems you need exactly the right value. I could make some pins work, but not all. Maybe a few is enough.
* controlling via ESP32 requires coding, but if we figure our how should be a huge problem to include. Some ppl will enjoy having the possibility of playing with a microcontroller as well if well-documented :) 

 <img src="./images/dfplayer.jpg" alt="DFPlayer module" width="200"> 

 <img src="./images/dfplayer_schem.png" alt="DFPlayer module" width="500"> 


### ISD1820 Voice recording module

ISD1820 - 10 second audio recording and playback module € 3.50 

Recording time can be adjusted to 20 secs by replacing jumper with a 200K resistor 
[Sound clip of distortion here](./files/ISD1820_pot_distort.mp3)

[Via tinytronics](https://www.tinytronics.nl/shop/en/audio/accessories/others/voice-recording-module-with-speaker-isd1820)

[Datasheet](./files/VoiceRecord_moduleISD1820.pdf)

[**All wiring diagrams** in files > ISD1820_wiring.pptx](./files/ISD1820_wiring.pptx)


 <img src="./images/ISD1820_all.jpg" alt="DFPlayer module" width="1600"> 
 
**Can NOT be customized:**

* core pcb

**Can maybe be customized: >> didnt try**

* embedded mic

**Can be customized: >> see image**

* the speaker (works w. piezo, bone conductor, jack to batt powered speaker)
* the buttons (vcc <-> play)
* samplerate with 500k pot on p2 jumper (distorts sounds)
* slide switch to loop
* slide switch to drive speaker directly

Downside: 

* Only one file can be stored and played on this device.
* Built-in amp very low. You can attach a jack to the speaker pins and connect to battery powered speaker though. 


## Audio out: Speakers

### battery powered speakers 

Anything that takes a jack

 <img src="./images/speakers4.5V.jpeg" alt="mini speakers" width="450"> 

### piezo transducer 

€0.50 [via tinytronics](https://www.tinytronics.nl/shop/en/audio/speakers/buzzers/piezo-electronic-buzzer-with-soldered-wires-35mm) placing it between teeth or on jaw makes sound audible

 <img src="./images/piezo.png" alt="piezo transducer" width="250"> 

### bone conductor transducer 

turns any surface into a speaker € 5 [via tinytronics](https://www.tinytronics.nl/shop/en/audio/speakers/speakers/bone-conductor-transducer-8%CF%89-1w), [via Adafruit](https://www.instructables.com/Adafruit-Bone-Conduction-Speaker/)

 <img src="./images/speaker_boneconduction.png" alt="bone conduction speaker" width="150">
 
### DIY speakers
 
a little bit elaborated, you need different materials [see Kobakant for inspiration](https://www.kobakant.at/DIY/?p=5935). Here a [tutorial for a soft speaker](https://www.instructables.com/Woven-Paper-Cup-Speaker/) made with yarn in a paper cup, and [here how to make a coil from lacquered wire](https://www.instructables.com/How-to-make-a-speaker-4/). A speaker works with electromagnetism. It consists of a coil (an insulated spiral of conductive material), a strong magnet, and a cone or other thin membrane. When there's a current going through the coil and the magnet is close enough, it will start to move slightly at a very fast speed (frequency), the movement is transferred to the membrane or cone attached to it, which amplifies it acoustically so the sound becomes audible.

 <img src="./images/speaker_anatomy.jpg" alt="DIY soft speakers" width="300"> 

*Note: this may take some trial and error process to get right :)*

* for the coil: lacquered copper wire, copper tape, conductive yarn and regular yarn. Make a coil that measures 4-8 ohm resistance. Tighter windings = louder sound
* don't short the coil 
* you need to make a cone or membrane, e.g. from paper, fabrics, paper/plastic cups. Should be stiff-ish but not too stiff (then the small vibrations can't move the cone/membrane).
* insulation tape
* strong neodymium magnets 
* connect the wires of the speaker in the same place you would the other speakers, move one or more magnets closer to the coil to activate the speaker

 <img src="./images/DIYspeaker.jpg" alt="DIY soft speakers" width="450"> 
 
 *Credit: Kobakant*

 
### Stereo amplifier (bonus?)

2x3W 5V w volume control € 3 [via tinytronics](https://www.tinytronics.nl/shop/en/audio/amplifiers/2x3w-stereo-audio-amplifier-mini-5v-pam8403-volume-control-v2)

>> not strong enough to amplify output of ISD1820.

 <img src="./images/amp.png" alt="mini amp with volume control knob" width="150"> 


## Triggers: switches and sensors

You can make your digital sensor or use already made digital sensors. The options below are plug and play without coding or breadboard (just jumpers/alligator clips). The pre-assembled boards allow you to calibrate an analog sensor as switch (e.g. light sensor), by turning the screw on the board. You can also use any on/off switches you salvage from old devices and use them as a trigger

### any metal/conductive parts 

Aluminum foil, copper tape, metals, wet materials. See also this page with examples: [DIY switches page](./switches/diyswitches.md)

 <img src="./images/switches_conductivematerials.jpg" alt="different conductive materials" width="300"> 

### piezo transducer 

€0.50 [via tinytronics](https://www.tinytronics.nl/shop/en/audio/speakers/buzzers/piezo-electronic-buzzer-with-soldered-wires-35mm) press, knock or bend to create trigger signal.

 <img src="./images/piezo.png" alt="piezo transducer" width="250"> 

### vibration sensor module 

€ 2 [via tinytronics](https://www.tinytronics.nl/shop/en/sensors/acceleration-rotation/vibration-sensor-module-3-5v-sw-18010p)

 <img src="./images/sensor_vibration.png" alt="vibrartion sensor module" width="250"> 

### tilt sensor 

€ 2 [via tinytronics](https://www.tinytronics.nl/shop/en/sensors/acceleration-rotation/ball-switch-tilt-sensor-module-3-5v-sw-520d)

 <img src="./images/sensor_tiltswitch.png" alt="tilt switch" width="250"> 

### magnet sensor 

€ 1,50 [via tinytronics](https://www.tinytronics.nl/shop/en/sensors/magnetic-field/hall-effect-switch-module)

 <img src="./images/sensor_magnetic_hall.png" alt="hall effect sensor module" width="200"> 

### motion sensor 

€ 3,50 [via tinytronics](https://www.tinytronics.nl/shop/en/sensors/motion/ir-pyroelectric-infrared-pir-motion-sensing-detector-module)

>> can be hard to control, bit flimsy

 <img src="./images/sensor_movement_pir.png" alt="PIR sensor" width="200"> 

### light sensor 

€ 2,50 [via tinytronics](https://www.tinytronics.nl/shop/en/sensors/optical/light-and-color/light-sensor-module)

 <img src="./images/sensor_light_LDR.png" alt="light sensor with LDR" width="200"> 

### red laser sensor 

€ 2 [via tinytronics](https://www.tinytronics.nl/shop/en/sensors/
optical/light-and-color/red-laser-sensor-module)

<img src="./images/sensor_redlaser.png" alt="red laser sensor module" width="200"> 

## Output: Other than sound

WIP

### Piezo mist discs 

€ 0,80 standalone, [via tinytronics](https://www.tinytronics.nl/shop/en/mechanics-and-actuators/others/piezo-mist-disc-110khz) or module € 4 [via tinytronics](https://www.tinytronics.nl/shop/en/mechanics-and-actuators/others/ultrasonic-mist-module)

 <img src="./images/output_ultrasonic_mist_module.png" alt="ultrasonic mist module" width="300"> 

### red laser 

€ 2 [via tinytronics](https://www.tinytronics.nl/shop/en/sensors/optical/light-and-color/red-laser-sensor-module) >> omg check [this DIY laser projection generated by sound and mirrors](https://www.kobakant.at/DIY/?p=9106)

 <img src="./images/output_laser.png" alt="red laser module" width="200"> 
 

## Messaging: walkie talkies

Now ordered these walkie talkies to open up, € 29.99 [via LIDL](https://www.lidl.nl/p/silvercrest-walkie-talkies-voor-kinderen/p100359077002?mktc=shopping)

These have 8 channels to choose from, volume control, and - yess - a mic. Sound quality is not bad! Also has an LED number panel that indicates the selected channel. The channels probably mean we can also have more than 2 walkie talkies transmitting on that frequency. 

Opens up by loosening the screws, just need to cut into silicone that glues down the speaker to remove it. Circles in the PCB show where the buttons were located. Other switches can be attached with some precision soldering and a dot of hot glue.

**Can be customized?**

* switches > YES
* microphone > YES
* LED number > only externally I think? E.g. make a lamp cover LOL
* speaker > YES
* 4.5V power supply > ? (check at 5V?)

 <img src="./images/walkies.jpg" alt="walkie talkie lidl" width="400"> 

 *walkie talkies unharmed*

  <img src="./images/walkie-inside.jpg" alt="walkie talkie lidl inside" width="750"> 
 
 *opening up walkie talkie: carefully cut loose silicon that keeps speaker in place*

  <img src="./images/walkie-inside3.jpg" alt="walkie talkie lidl inside" width="750"> 

   *power connections and speaker connector*
  
  <img src="./images/walkie-components.jpg" alt="walkie talkie lidl inside" width="600"> 

   *switches and other components on reverse*


* Earlier I got these €10 walkie talkies from flying tiger. **These don't actually have a microphone!** They just pick up noise and interference (so can work as noise making devices). Listen [here](./files/walkienoise.mp3). Available at [flying tiger €10](https://flyingtiger.com/nl/products/walkie-talkie-set-3034395?variant=41188458397894&srsltid=Ad5pg_E7P2uBBKjFlA-3Iy8jgljKbblaxprOBdHRD30Sq0cDsXl1De_tzrs&currency=eur)

 <img src="./images/walkie1.jpg" alt="walkie talkie contents" width="500"> 

 <img src="./images/walkie2.jpg" alt="walkie talkie contents" width="500"> 


## Power supplies

**WIP** 

### Solar powered

>> We have a bunch of these kits from another solar project. Could be worth checking out for this workshop? 

* LilyGO TTGO T-Bat w 18650 Li-on battery holder CN3065 € 5,50 [via Tinytronics](https://www.tinytronics.nl/shop/nl/power/bms-en-laders/li-ion-en-li-po/met-protectiecircuit/lilygo-ttgo-t-bat-met-18650-batterijhouder-cn3065)
	* Vin: 5V (via micro USB connector) OR 4.5-6V via solar cell connector OR solar cell via JST connector
	* Vout: 5V via USB A connector or via JST-PH connector
* Li-on 18650 battery 3400mA - 10A - € 6,00 [Via tinytronics](https://www.tinytronics.nl/shop/nl/power/batterijen/18650/lg-18650-li-ion-batterij-3400mah-10a-inr18650-mj1)
* Seeed Studio Solar panels 5.5V 100mA - 55x70mm with JST-PH connector €4,25 [via Tinytronics](https://www.tinytronics.nl/shop/nl/power/zonne-energie/zonnepanelen/seeed-studio-zonnepaneel-5.5v-100ma-55x70mm-met-jst-ph-connector). Also available: 5.5V 170mA but has bulkier size [via tinytronics, €6,50](https://www.tinytronics.nl/shop/nl/power/zonne-energie/zonnepanelen/seeed-studio-zonnepaneel-5.5v-170ma-80x100mm-met-jst-ph-connector)

 <img src="./images/lilygoboard.jpg" alt="LilyGO charging board" width="800"> 

### Solar panels test
 <img src="./images/solar_indoor.jpg" alt="walkie talkie contents" width="300">
  <img src="./images/solar_outdoor.jpg" alt="walkie talkie contents" width="300">
   <img src="./images/solar_indoor_covered.jpg" alt="walkie talkie contents" width="300">
    <img src="./images/solar_indoor_flashlight.jpg" alt="walkie talkie contents" width="300">
  
with the use of a DC-DC converte, you can power directly the board, without battery.

### DYNAMO powered

## Casing and integration

WIP
