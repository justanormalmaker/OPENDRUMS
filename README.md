<img src="https://github.com/user-attachments/assets/1b90f5db-bd15-409f-aa60-4ae742a669e3" width="385px">

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
When i ( [@justanormalmaker](https://github.com/justanormalmaker) ) thought of OPENDRUMS I wanted to create a relatively "simple" but at the same time cool and useful Hardware/Software project that anyone could create with a few components, a PCB, and a soldering iron. Its a good project for people that like to **create music**, like me :), and for anyone else that want to build a cool project and **learn something new**!
You can build OPENDRUMS with **60 components** and easly programm its **Atmega328p microprocessor** with an Arduino Uno board and **Arduino IDE**. You can use the instrument to play drums or any type of samples wherever and whenever you like thanks to its **9 progammable button** that act like pads, **rechargeable battery**, and **compact size** (100mm x 90mm). For more information about the Hardware and Software go to 


## 🥁 Why OPENDRUMS?

Because it's **Open-Source** and **Built with love**! You want to just build the 0.1v of the project, you can! You want to create your custom OPENDRUMS variation, or you want to improve OPENDRUMS and help me create the 1.0v, you can! You want to create a better code for the project, a better design, you want to add more buttons, more leds... you can! All the original code, circuit schematic and PCB desing are avilable for yo,u to just build OPENDRUMS 0.1, or to customaize everything! You decide!

## 🎨 Features

* **Compact size** - *100x90 mm* or *3,94x3,54 in*
* **9 progammable button** - *Buttons that can be programmed to play any sample*
* **OLED screen** - *For programming the button*
* **Integrated speaker**
* **3.5mm headphones jack**
* **Rechargeable battery**
* **USB-C charging port**

## 💡 Hardware

### Component list

* **11**  12*12mm push buttons
* **1**  6*6mm push button
* **2**  ON/OFF slider swiches
* **10**  blu 5mm LEDs
* **1**  green 5mm LED
* **1**  red 5mm LED
* **12**  1k 1/4W resistors
* **1**  10k 1/4W resistor
* **1**  220 1/4W resistor
* **1**  50k potentiometer
* **2**  22pf ceramic capacitors
* **2**  10uf electrolytic capacitors
* **1**  1uf ceramic capacitor
* **1**  100nf ceramic capacitor
* **1**  470uf electrolytic capacitor
* **1**  16MHz quartz crystal
* **1**  33uH SMD inductor
* **1**  SS24 SMD diode
* **1**  3.5mm headphones jack
* **1**  4ohm speaker
* **1**  DFPlayerMini
* **1**  128*64 0.96" I2C OLED display
* **1**  USB-C 6pin charging port
* **1**  4pins male header row
* **1**  JST 2mm connector
* **1**  AP5900 battery charger/bust converter IC (SOP-8 package)
* **1**  Atmega328p-pu microcontroller

### PCB and circuit schematics

## 🌏 Browser Support

| <img src="https://user-images.githubusercontent.com/1215767/34348387-a2e64588-ea4d-11e7-8267-a43365103afe.png" alt="Chrome" width="16px" height="16px" /> Chrome | <img src="https://user-images.githubusercontent.com/1215767/34348590-250b3ca2-ea4f-11e7-9efb-da953359321f.png" alt="IE" width="16px" height="16px" /> Internet Explorer | <img src="https://user-images.githubusercontent.com/1215767/34348380-93e77ae8-ea4d-11e7-8696-9a989ddbbbf5.png" alt="Edge" width="16px" height="16px" /> Edge | <img src="https://user-images.githubusercontent.com/1215767/34348394-a981f892-ea4d-11e7-9156-d128d58386b9.png" alt="Safari" width="16px" height="16px" /> Safari | <img src="https://user-images.githubusercontent.com/1215767/34348383-9e7ed492-ea4d-11e7-910c-03b39d52f496.png" alt="Firefox" width="16px" height="16px" /> Firefox |
| :---------: | :---------: | :---------: | :---------: | :---------: |
| Yes | 11+ | Yes | Yes | Yes |


## 🔧 Pull Request Steps

TOAST UI products are open source, so you can create a pull request(PR) after you fix issues. Run npm scripts and develop yourself with the following process.

### Setup

Fork `main` branch into your personal repository. Clone it to local computer. Install node modules. Before starting development, you should check if there are any errors.

```sh
$ git clone https://github.com/{your-personal-repo}/tui.editor.git
$ npm install
$ npm run build toastmark
$ npm run test editor
```

> TOAST UI Editor uses [npm workspace](https://docs.npmjs.com/cli/v7/using-npm/workspaces/), so you need to set the environment based on [npm7](https://github.blog/2021-02-02-npm-7-is-now-generally-available/). If subversion is used, dependencies must be installed by moving direct paths per package.

### Develop

You can see your code reflected as soon as you save the code by running a server. Don't miss adding test cases and then make green rights.

#### Run snowpack-dev-server
[snowpack](https://www.snowpack.dev/) allows you to run a development server without bundling.

``` sh
$ npm run serve editor
```

#### Run webpack-dev-server
If testing of legacy browsers is required, the development server can still be run using a [webpack](https://webpack.js.org/).

``` sh
$ npm run serve:ie editor
```

#### Run test

``` sh
$ npm test editor
```

### Pull Request

Before uploading your PR, run test one last time to check if there are any errors. If it has no errors, commit and then push it!

For more information on PR's steps, please see links in the Contributing section.

## 💬 Contributing

* [Code of Conduct](https://github.com/nhn/tui.editor/blob/master/CODE_OF_CONDUCT.md)
* [Contributing Guideline](https://github.com/nhn/tui.editor/blob/master/CONTRIBUTING.md)
* [Commit Convention](https://github.com/nhn/tui.editor/blob/master/docs/COMMIT_MESSAGE_CONVENTION.md)
* [Issue Guidelines](https://github.com/nhn/tui.editor/tree/master/.github/ISSUE_TEMPLATE)


## 🍞 TOAST UI Family

- [TOAST UI Calendar](https://github.com/nhn/tui.calendar)
- [TOAST UI Chart](https://github.com/nhn/tui.chart)
- [TOAST UI Grid](https://github.com/nhn/tui.grid)
- [TOAST UI Image Editor](https://github.com/nhn/tui.image-editor)
- [TOAST UI Components](https://github.com/nhn)


## 🚀 Used By

* [NHN Dooray! - Collaboration Service (Project, Messenger, Mail, Calendar, Drive, Wiki, Contacts)](https://dooray.com)
* [UNOTES - Visual Studio Code Extension](https://marketplace.visualstudio.com/items?itemName=ryanmcalister.Unotes)


## 📜 License

This software is licensed under the [MIT](https://github.com/nhn/tui.editor/blob/master/LICENSE) © [NHN Cloud](https://github.com/nhn).

