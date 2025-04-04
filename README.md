<img src="https://github.com/user-attachments/assets/6913ead2-5862-47ee-b035-4ca4a0166c98" width="400px">
    
> The portable Open-Source sample player/drum pads based on Arduino 

[![code with hearth by JANM](https://img.shields.io/badge/Made_with%20%E2%99%A5%20by-JANM-ff1414.svg)](https://github.com/justanormalmaker) [![Hardware Version](https://img.shields.io/badge/Hardware-v1.0-00808f.svg)](https://github.com/justanormalmaker) [![Software Version](https://img.shields.io/badge/Software-v1.0-8a2be2.svg)](https://github.com/justanormalmaker) [![license](https://img.shields.io/github/license/justanormalmaker/OPENDRUMS.svg)](https://github.com/justanormalmaker/OPENDRUMS/blob/master/LICENSE) [![Instagram](https://img.shields.io/badge/Instagram-@opendrums.project-dd2a7b.svg)](https://www.instagram.com/opendrums.project)


[![OPENDRUMS DEMO](https://github.com/user-attachments/assets/eaa29889-be5d-4f08-b569-18beffe555d9)](https://www.youtube.com/watch?v=3pwfQyi5qWA "OPENDRUMS V1.0 video demo")

Click on the image to see the video demo :)


## 🚩 Table of Contents

- [About](#-about)
- [Why OPENDRUMS?](#-why-opendrums)
- [Features](#-features)
- [Hardware](#-hardware)
- [Software](#-software)
- [How to use](#%EF%B8%8F-how-to-use)



## 🚀 About

**OPENDRUMS** is an elecronic instrument similar to a **sample player or a drum pads machine** that can play any sound sample, but with the particularity of being small, portable and **Open-Source**!
When i ( [@justanormalmaker](https://github.com/justanormalmaker) ) thought of OPENDRUMS I wanted to create a relatively "simple" but at the same time cool and useful Hardware/Software project that anyone could create with a few components, a PCB, and a soldering iron. Its a good project for people that like to **create music**, like me :), and for anyone else that want to build a cool project and **learn something new**! The aim of this project is to bring music lovers closer to electronics and vice versa, leaving aside the boring theory and experimenting directly with something concrete and fun.
You can build OPENDRUMS with **60 components** and an Arduino Nano board. You can use the instrument to play drums or any type of samples wherever and whenever you like thanks to its **9 progammable buttons** that act like pads, **rechargeable battery**, and **compact size**. For more information about the Hardware and Software go to [Hardware](#-hardware)  -  [Software](#-software).


## 🥁 Why OPENDRUMS?

Because it's **Open-Source** and **Built with love**! You want to just build the 1.0v of the project, you can! You want to create your custom OPENDRUMS variation, or you want to improve OPENDRUMS and help me create the 2.0v, you can! You want to create a better code for the project, a better design, you want to add more buttons, more leds... you can! All the original code, circuit schematic and PCB desing are avilable for you, to just build OPENDRUMS 1.0, or to customaize everything! You decide!

## 🎨 Features

* **Compact size** - *100x90 mm* or *3,94x3,54 in*
* **9 progammable buttons** - *Buttons that can be programmed to play any sample*
* **OLED screen** - *For programming the button*
* **Integrated speaker**
* **3.5mm headphones jacks**
* **Rechargeable battery**
* **USB-C charging port** *(depends on the arduino board used)*

## 💡 Hardware

### Component list (V1.0)

* **11**  12*12mm push buttons
* **1**  ON/OFF slider switch DPDT
* **1**  push switch DPDT
* **10**  blue 5mm LEDs 
* **1**  green 5mm LED
* **1**  red 5mm LED
* **12**  1k 1/4W resistors 
* **1**  10k 1/4W resistor
* **1**  220 1/4W resistor
* **1**  50k potentiometer 
* **2**  10uf electrolytic capacitors 
* **1**  1uf ceramic capacitor
* **1**  100nf ceramic capacitor
* **1**  470uf electrolytic capacitor
* **1**  33uH SMD inductor coil
* **1**  SS24 SMD diode
* **2**  3.5mm headphones jack
* **1**  4ohm speaker
* **1**  DFPlayerMini module
* **1**  128*64 0.96" I2C OLED display
* **1**  JST 2mm connector
* **1**  AP5900 battery charger/boost converter IC (SOP-8 package)
* **1**  Arduino nano every (The original boards have a micro-USB port, some chinese clone have a USB-C port)

### PCB and circuit schematics

You can find everything, incluse the **schematic and the gerber file** in the repo's files. But for contest this is the **circuit schematic**:


<img src="https://github.com/user-attachments/assets/54658d91-32e2-442c-8c32-121d656a3f97"/>


In the schematic we found the **arduino nano, the buttons grid, the two buttons for programming, the volume potentiometer, LED indicators, the DFPlayermini circuit, the battery charger/boost converter circuit, and the OLED display**.

The **battery charger/boost converter circuit** is what gives stable **5V power** to the board and allow to charge a **3.7V LiPo (Lithium Polymer battery)**. The circuit is based on the **AP5900 IC**, a chinese chip used in power-banks and similar products. This specific IC requires little additional components to work **(Some capacitors, an inductor coil, a diode, and two LEDs)** and does the work of 3 ICs in 1. This circuit is connected directly to the 5V pin of the arduino through a **switch** that allows you to choose between **OFF/Charge and ON mode**:
* **ON Mode** - The board is powered by the battery.
* **OFF/Charging Mode** - The board can be powered by the arduino USB connector. If power is given (using arduino's USB connector) the battery will charge.

> [!CAUTION]
> DISCONNECT THE ARDUINO FROM ANY COMPUTER OR USB BEFORE TURNING TO ON MODE.

The **Arduino** is the brain of the board. It comunicates with all the buttons, the DFplayer, an the OLED.
* **Buttons grid** - Every button of the grid is connected to a **digital I/O (Input/output) pin** of the Arduino, setted as **INPUT**, and its also connected to **ground (GND)** and to the nagative terminal of an **LED** that is then connected to **5V**. Every LED is connected in series with a 220ohm resistor. When the button is pressed **it completes the circuit** and connects the arduino pin (pulled UP to 5V), and the negative terminal of the LED to GND. **The LED lights up and the Arduino feels the change in the state of the pin connected to the button**.
* **Buttons for programming/LED indicator** - Same thing for this buttons but this time we have only an LED connected **indipendently** to GND and to the **digital pin 13**, setted as **OUTPUT**, by the positive terminal.
* **Volume potentiometer** - It's connected to the **analog pin 3**, of the arduino and obviously to **GND and 5V**.
* **DFPlayerMini** - This module has the function of **reading and playing the audio file from an SD card**. Its connected to **GND and 5V trough a series of capacitors**, that have the function of improving the general audio quality of the module by removing the **electrical interference** caused by other components. It comunicates with arduino using the **UART (Universal Asynchronous Receiver-Transmitter) protocol** using the digital **pin 5 and pin 6**. It's also connected to a **4ohm speaker** with a slider switch (used to turn it ON and OFF) and two **3.5mm headphones jacks**.
* **OLED display** - The display comunicates with arduino using the **I2C protocol**. It comunicates using **analog pin 4 (SDA) and pin 5 (SCK)** of the arduino and it also recives **5V power**.

This all together makes up the OPENDRUMS circuit. All the connections between the various components are "enclosed" in a PCB (Printed Circuit Board) that makes the assembly of the project easy. You just have to find the necessary components and solder them in the right place! The circuit diagram and the PCB were made using a free online tool colled EasyEDA. 

### Project assembly

To assemble the project you need to have the PCB, the necessary components, and some basic soldering skills. Our PCB were produced by JLCPcb for really cheap (Like 3$ for 5 PCBs), from the Gerber file that we sent them. You can find where the components go in the scheme above. 

Soldering most of the components to the PCB was easy. The most difficult to solder were the SMD components, but with a youtube tutorial and some patience, the job was done. When soldering SMD componets you usually use an hot air station or an hot reflow plate but we easily soldered the components using a simple soldering iron. 

After soldering, we uploaded the .ino code to the Arduino, and the board was ready!

If you want to complete you project you can also 3d print [this](https://github.com/justanormalmaker/OPENDRUMS/tree/d73520e1f8d5941a42290f2c07b925489fcdf160/HARDWARE/CASE%20(Per%20prototipo%20v0.1)) case (it's for the v0.1, we are going to release the case for the v1.0 soon :) )

<img src="https://github.com/user-attachments/assets/0ab41940-4e27-43fc-a050-58d6f544d6fa"/>

## 💻 Software

### Main Softwares
To function OPENDRUMS uses this [Arduino code](SOFTWARE/OPENDRUMS_V1.0_arduino_software.ino).
The code is divided in sections and commented so that it can be easily understood.

It also uses this [Python program](SOFTWARE/OPENDRUMS_V1.0_python_setup_software.ino).
This program has to be used on a computer to setup OPENDRUMS when in "SETUP" mode. More info in the "How to use" section below.

### Other Softwares
To use OPENDRUMS as a MIDI instrument you have to use two free softwares:
- [HairLess MIDI](https://projectgus.github.io/hairless-midiserial/)
- [LoopMIDI](https://www.tobias-erichsen.de/software/loopmidi.html)

## ⚙️ How to Use

### Introduction
OPENDRUMS is an electronic sample player instrument that can be used like a stand-alone instrument or like a USB MIDI instrument/controller. It can play any type of sample, sound, loop... 

### Different modes and setup.
#### Mode 1: SETUP
After powering on the device (Using the power button or connecting the board to USB while off) the OLED will display the SETUP screen.
To navigate betwen YES and NO press the UP button, to enter press the PROGRAM button.
If YES is selected the device will enter in setup mode. This mode is used to tell to the board the number of sounds contained on the SD card that you can insert in the SD card slot on the side. 

> [!NOTE]
> You have to setup the board only when you add or remove files from the card.

To setup the board, connect it to a computer via USB, open the OPENDRUMS python program, insert the number of files contained in the SD and click "Send". The board will restart.

#### Mode 2: MIDI
After the SETUP screen the MIDI screen is displayed. If YES is selected the device will enter midi mode. Now it can be used like a USB midi instrument.

> [!IMPORTANT]
> You have to open Hairless MIDI and LoopMidi softwares so that the device can be correctly recognaized as a MIDI instrument.

#### Mode 3: SD PLAY
if any of the previous mode is selected the device will enter in SD mode. Now it can be used like a stand-alone instrument that will play any sample present on the SD card inserted.

> [!IMPORTANT]
> The samples of the SD card have to be .WAW files.

### How to play.
Before playing, you have to select what sample every button will play.
To do that, press the PROGRAM button, then find the sample name (or Midi note value, in MIDI mode) you like, using the UP button, and press one of the buttons named PAD to assing the sample to that button.
To exit this "program" state press the PROGRAM button again.

> [!NOTE]
> The samples selected for the buttons will stay the same even after turning off the device until you program the buttons again.

Now to play the samples, press any of the PAD buttons and have fun!

## 📜 License

This project is licensed under the [MIT](https://github.com/justanormalmaker/OPENDRUMS/blob/main/LICENSE) © [JustANormalMaker](https://github.com/justanormalmaker).

