<img src="https://github.com/user-attachments/assets/6913ead2-5862-47ee-b035-4ca4a0166c98" width="400px">
     
> The portable Open-Source sample player/drum pads based on Atmega328 

[![code with hearth by JANM](https://img.shields.io/badge/Made_with%20%E2%99%A5%20by-JANM-ff1414.svg)](https://github.com/justanormalmaker) [![Hardware Version](https://img.shields.io/badge/Hardware-v0.1-00808f.svg)](https://github.com/justanormalmaker) [![Software Version](https://img.shields.io/badge/Software-v0.1-8a2be2.svg)](https://github.com/justanormalmaker) [![license](https://img.shields.io/github/license/justanormalmaker/OPENDRUMS.svg)](https://github.com/justanormalmaker/OPENDRUMS/blob/master/LICENSE) [![Instagram](https://img.shields.io/badge/Instagram-@justanormalmaker-dd2a7b.svg)](https://www.instagram.com/justanormalmaker?igsh=NWh5ZW92dXE0NHJm)

<img src="https://github.com/user-attachments/assets/1c9d951d-ce22-44c8-91ee-80ba1963ba81" />


## 🚩 Table of Contents

- [About](#-about)
- [Why OPENDRUMS?](#-why-opendrums)
- [Features](#-features)
- [Hardware](#-hardware)
- [Browser Support](#-browser-support)
- [Pull Request Steps](#-pull-request-steps)
- [Contributing](#-contributing)
- [TOAST UI Family](#-toast-ui-family)
- [Used By](#-used-by)
- [License](#-license)


## 🚀 About

**OPENDRUMS** is an elecronic instrument similar to a **sample player or a drum pads machine**, but with the particularity of being small, portable and **Open-Source**!
When i ( [@justanormalmaker](https://github.com/justanormalmaker) ) thought of OPENDRUMS I wanted to create a relatively "simple" but at the same time cool and useful Hardware/Software project that anyone could create with a few components, a PCB, and a soldering iron. Its a good project for people that like to **create music**, like me :), and for anyone else that want to build a cool project and **learn something new**! The aim of this project is to bring music lovers closer to electronics and vice versa, leaving aside the boring theory and experimenting directly with something concrete and fun.
You can build OPENDRUMS with **60 components** and an Arduino Nano board. You can use the instrument to play drums or any type of samples wherever and whenever you like thanks to its **9 progammable buttons** that act like pads, **rechargeable battery**, and **compact size**. For more information about the Hardware and Software go to 


## 🥁 Why OPENDRUMS?

Because it's **Open-Source** and **Built with love**! You want to just build the 0.1v of the project, you can! You want to create your custom OPENDRUMS variation, or you want to improve OPENDRUMS and help me create the 1.0v, you can! You want to create a better code for the project, a better design, you want to add more buttons, more leds... you can! All the original code, circuit schematic and PCB desing are avilable for you, to just build OPENDRUMS 0.1, or to customaize everything! You decide!

## 🎨 Features

* **Compact size** - *100x90 mm* or *3,94x3,54 in*
* **9 progammable buttons** - *Buttons that can be programmed to play any sample*
* **OLED screen** - *For programming the button*
* **Integrated speaker**
* **3.5mm headphones jack**
* **Rechargeable battery**
* **USB-C charging port** *(depends on the arduino board used)*

## 💡 Hardware

### Component list

* **11**  12*12mm push buttons ([Amazon link](https://www.amazon.it/RUNCCI-YUN-Interruttore，micro-interruttore-momentanea，Tact-microinterruttori/dp/B0BF51N8CK/ref=sr_1_3?__mk_it_IT=ÅMÅŽÕÑ&crid=2D39AACUVM78Z&dib=eyJ2IjoiMSJ9.Y3eOB8jBGGPvLOlYMCzABjcCs1pTKfTvE1JVXBz9p4mF3Wn-zO-sxe34fwia25wVGzf1k2DjJtkyZWoj3vb3OiHkKG339pj2Kgr74DQYeBWMkpfDk8YrTfkB8Gi2U9CP1ELPvdwe6OqDWlrqZF6kisewhdWQu3cvSP8gok4BE6nossxLDi01uAfvWF37nhvr4kXSfbO0XIZuFCwQCxRqWKkaRaHHD1NKHzAPUNG6YsiQdBzN61t3D1XMg8RjGOfazFKsYxIyz0hk60J2xBwzK2_j4zie668vuKbzpLHvlDbDGSFkGVlxhXuZQsL1S-aCb_oG4_cy2lVbn9X31TLZlsMLWfxCCOB0QRNLexuZcowXP81H4NuJKDdtRqN51dt0ZB2VPAnbZnOFmf1yJDPaDx5jYtMRdtISC257BeCVBOSrANVmmNN1cyiysgSCurUN.Qq2wZlf-S__et4NP4etEZ1bIg6Yz5EnKg0AOuWtSsEg&dib_tag=se&keywords=bottoni%2Barduino&qid=1740647569&sprefix=bottone%2Barduino%2Caps%2C111&sr=8-3&th=1))
* **1**  6*6mm push button ([Amazon link](https://www.amazon.it/Interruttore-tattile-istantaneo-interruttore-pulsante/dp/B09VFR3BFN/ref=sr_1_7?__mk_it_IT=ÅMÅŽÕÑ&crid=2D39AACUVM78Z&dib=eyJ2IjoiMSJ9.Y3eOB8jBGGPvLOlYMCzABjcCs1pTKfTvE1JVXBz9p4mF3Wn-zO-sxe34fwia25wVGzf1k2DjJtkyZWoj3vb3OiHkKG339pj2Kgr74DQYeBWMkpfDk8YrTfkB8Gi2U9CP1ELPvdwe6OqDWlrqZF6kisewhdWQu3cvSP8gok4BE6nossxLDi01uAfvWF37nhvr4kXSfbO0XIZuFCwQCxRqWKkaRaHHD1NKHzAPUNG6YsiQdBzN61t3D1XMg8RjGOfazFKsYxIyz0hk60J2xBwzK2_j4zie668vuKbzpLHvlDbDGSFkGVlxhXuZQsL1S-aCb_oG4_cy2lVbn9X31TLZlsMLWfxCCOB0QRNLexuZcowXP81H4NuJKDdtRqN51dt0ZB2VPAnbZnOFmf1yJDPaDx5jYtMRdtISC257BeCVBOSrANVmmNN1cyiysgSCurUN.Qq2wZlf-S__et4NP4etEZ1bIg6Yz5EnKg0AOuWtSsEg&dib_tag=se&keywords=bottoni+arduino&qid=1740647569&sprefix=bottone+arduino%2Caps%2C111&sr=8-7))
* **2**  ON/OFF slider swiches DPDT
* **10**  blue 5mm LEDs ([Amazon link](https://www.amazon.it/Emissione-Luminosa-Assortimento-Incorniciato-Artigianale/dp/B0CXDS8LDL/ref=sr_1_5?__mk_it_IT=ÅMÅŽÕÑ&crid=3M4ISLTV3RW3G&dib=eyJ2IjoiMSJ9.fTo6QEjI7z7Uix_wxZd1rt453azWaQMOvlVGw5FEu81WY54QinfrAtpRCXgW9hJGdiGX8Cu20IiHUUN3ugZX5StIme1S5utcFiYWoxm7d2zbpiVQZqEVk6Uw2wPGs3BSgfVprPIvCvL0llVzEEVd2p3owQTMFlNdU5ISO9s9yj6eDBfRcUGjCp1hHor68b3ObUCS18Hcs-oOMXN8WpVMbE7gaTN9XXUqHiQAsxIWLoyE8RPyqlXj7FyEl4_aCXNquUc3PQRVBt71HAe47yNn0hRTnFmR3Z_LMNtgnD8J4onbone-LtDbTAAiZdcZxklvYwM9Uowbii3lmTx9OEC-OkuGyguQPFHgDcLZpyd_LEynTcha8EuzdbxQhQ-6-GOXQzXE65Q7GAMD1MlwO7nYPpojUjSnR8E3zEhor6N4YiIJXNG5r0tUIgFRqi1l65l0.OlKJAyDmSLPnohYcW7WazOnfsnAZFkXZYGP9XLI2c2g&dib_tag=se&keywords=led+arduino&qid=1740647820&sprefix=led+arduino%2Caps%2C159&sr=8-5))
* **1**  green 5mm LED
* **1**  red 5mm LED
* **12**  1k 1/4W resistors ([Amazon link](https://www.amazon.it/BOJACK-valori-assortimento-resistori-carbonio/dp/B08FD1XVL6/ref=sr_1_1_sspa?__mk_it_IT=ÅMÅŽÕÑ&crid=29AG1U4051PI&dib=eyJ2IjoiMSJ9.PH1qx-HYshIwrIYD_f7AJHx5rd8jAZ8RpDegaWzjrLOeIeGCHtwbyWvuzu2IaDvXngz4nMESIbYHkg-pyd1f4MNJyr35iJWknUAYo8xeCVYe98Uz7MKrSegSXQJSo-q2FWci8VkkJyS7qfIh6gIF2tS1yfV-AilrIoW2PLM_w6VpQWdq-52s4LZcj4PCsWmlVvSQq_gQYlZEmO-xo5LjDIBGLEqGzw_9yCnRDhCaGIqLCKaVvs98aG2oZabX4HK404nCMN_8CE3LNST0CvhMeZWyZuFqAi5aqJrc-ejtHac.xyy5aWoRXSNbfkrVuvYc48VcW6ZgbG5iHhLqJjM1P9M&dib_tag=se&keywords=resistenze%2Barduino&qid=1740647964&sprefix=resistenze%2Barduino%2Caps%2C141&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&th=1))
* **1**  10k 1/4W resistor
* **1**  220 1/4W resistor
* **1**  50k potentiometer ([Amazon link](https://www.amazon.it/TecnoStore®-POTENZIOMETRO-LINEARE-MONOGIRO-potentiometer/dp/B072JWNH3X/ref=sr_1_6?__mk_it_IT=ÅMÅŽÕÑ&crid=M12BQV1S7POT&dib=eyJ2IjoiMSJ9.79x5GRzZ_T4kl61UDK2c9b7QKfhCc5tqitQ5KjemX7-Pv9axcxUMFlRPN_gFBXelIWDXY41s2l0Vgh-stYLIypky-Iw0XFE8r35i8ETxaupmfuvS8WeTPGw_4YFUhQ93z6qF8y2iXyFsgHaFVOkJHME413D95vQWn0lWBDX9arij18u9rHSOWVXK_H5_GcygXvqfS4rcrnV56wzh-du14CROO4eT7c6HClwZB9wle9mfJ_JFI-EL6FFbFIFWPMKbEk6ADEKtrlZhbl5sAxeKSoHaA_4wCedQtZfYDl0V5XtsoDxqlce2ELxkycxrdbzAVqjgDU8oMbVvlqlAzX58LgFkcg-oM7WjlTqW5Di4OTUqN0LA2Yk6coeq4PrPpiTVya-Yj0bBpoc4lsQNyiS3h1Yk8t3Zb11fvJ7lSyw-uOKzYA6No7OJIMZ7DXi_FmqT.FE5TcccEJqylEZlT1eXUXu8nkTJMB-fwRtTJ1ma9qOE&dib_tag=se&keywords=potenziometro+50k&qid=1740652104&sprefix=potenziometro+50k%2Caps%2C150&sr=8-6))
* **2**  10uf electrolytic capacitors ([Ama
* **1**  1uf ceramic capacitor
* **1**  100nf ceramic capacitor
* **1**  470uf electrolytic capacitor
* **1**  33uH SMD inductor coil
* **1**  SS24 SMD diode
* **1**  3.5mm headphones jack
* **1**  4ohm speaker
* **1**  DFPlayerMini module
* **1**  128*64 0.96" I2C OLED display
* **1**  JST 2mm connector
* **1**  AP5900 battery charger/boost converter IC (SOP-8 package)
* **1**  Arduino nano (I used an amazon clone with an USB-C port)

### PCB and circuit schematics

You can find everything, incluse the **schematic and the gerber file** in the repo's files. But for contest this is the **circuit schematic**:

In the schematic we found the **arduino nano, the buttons grid, the two buttons for programming, the volume potentiometer, LED indicators, the DFPlayermini circuit, the battery charger/boost converter circuit, and the OLED display**.

The **battery charger/boost converter circuit** is what gives stable **5V power** to the board and allow to charge a **3.7V LiPo (Lithium Polymer battery)**. The circuit is based on the **AP5900 IC**, a chinese chip used in power-banks and similar products. This specific IC requires little additional components to work **(Some capacitors, an inductor coil, a diode, and two LEDs)** and does the work of 3 ICs in 1. This circuit is connected directly to the 5V pin of the arduino through a **switch** that allows you to choose between **OFF/Charge and ON mode**:
* **ON Mode** - The board is powered by the battery. YOU MUST DISCONNECT THE ARDUINO FROM ANY COMPUTER OR USB BEFORE TURNING TO ON MODE.
* **OFF/Charging Mode** - The board can be powered by the arduino USB connector. If power is given (using arduino's USB connector) the battery will charge.

The **Arduino** is the brain of the board. It comunicates with all the buttons, the DFplayer, an the OLED.
* **Buttons grid** - Every button of the grid is connected to a **digital I/O (Input/output) pin** of the Arduino, setted as **INPUT**, and its also connected to **ground (GND)** and to the nagative terminal of an **LED** that is then connected to **5V**. Every LED is connected in series with a 220ohm resistor. When the button is pressed **it completes the circuit** and connects the arduino pin (pulled UP to 5V), and the negative terminal of the LED to GND. **The LED lights up and the Arduino feels the change in the state of the pin connected to the button**.
* **Buttons for programming/LED indicator** - Same thing for this buttons but this time we have only an LED connected **indipendently** to GND and to the **digital pin 13**, setted as **OUTPUT**, by the positive terminal.
* **Volume potentiometer** - It's connected to the **analog pin 3**, of the arduino and obviously to **GND and 5V**.
* **DFPlayerMini** - This module has the function of **reading and playing the audio file from an SD card**. Its connected to **GND and 5V trough a series of capacitors**, that have the function of improving the general audio quality of the module by removing the **electrical interference** caused by other components. It comunicates with arduino using the **UART (Universal Asynchronous Receiver-Transmitter) protocol** using the digital **pin 5 and pin 6**. It's also connected to a **4ohm speaker** with a slider switch (used to turn it ON and OFF) and a **3.5mm headphones jack**.
* **OLED display** - The display comunicates with arduino using the **I2C protocol**. It comunicates using **analog pin 4 (SDA) and pin 5 (SCK)** of the arduino and it also recives **5V power**.

This all together makes up the OPENDRUMS circuit. All the connections between the various components are "enclosed" in a PCB (Printed Circuit Board) that makes the assembly of the project easy. You just have to find the necessary components and solder them in the right place! The circuit diagram and the PCB were made using a free online tool colled EasyEDA. 

### Project assembly

To assemble the project you need to have the PCB, the necessary components, and some basic soldering skills. Our PCB were produced by JLCPcb for really cheap (Like 3$ for 5 PCBs) from the Gerber file that we sent them. 

Soldering most of the components to the PCB was easy. The most difficult to solder were the SMD components, but with a youtube tutorial and some patience, the job was done. When soldering SMD componets you usually use an hot air station or an hot reflow plate but we easily 


## 📜 License

This software is licensed under the [MIT](https://github.com/justanormalmaker/OPENDRUMS/blob/main/LICENSE) © [JustANormalMaker](https://github.com/justanormalmaker).

