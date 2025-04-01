#include <MIDI.h>
#include <EEPROM.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

/////////////////////// DICHIARAZIONE VARIABILI PAD ///////////////////////////
int PAD1 = 2;
int PAD2 = 3;
int PAD3 = 4;
int PAD4 = 10;
int PAD5 = 11;
int PAD6 = 12;
int PAD7 = A0;
int PAD8 = A1;
int PAD9 = A2;
int PROG = 8;
int UP = 7;
int POT = A3;
int SPAD1, SPAD2, SPAD3, SPAD4, SPAD5, SPAD6, SPAD7, SPAD8, SPAD9;

/////////////////////// DICHIARAZIONE VARIABILI DI LAVORO ///////////////////////////
int LED = 13;
int stato, sottostato;
int I;
int maxx;
int potValue = 0;
int volValue;

/////////////////////// DICHIARAZIONE OLED/DFPLAYERMINI ///////////////////////////
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1  // Pin di reset, non usato con i display I2C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

SoftwareSerial mySoftwareSerial(5, 6); // Pin 5 per RX, Pin 6 per TX
DFRobotDFPlayerMini myDFPlayer;

MIDI_CREATE_DEFAULT_INSTANCE();


///////////////////////////////////////////////////////////////////////// VOID SETUP ////////////////////////////////////////////////////////////////////////////
void setup() {
  
  /////////////////////// SETUP OLED/DFPLAYERMINI E SERIALI ///////////////////////////
  Serial.begin(115200);
  mySoftwareSerial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
  Serial.println(F("SSD1306 allocation fallita"));
  for(;;);
  }
  if (!myDFPlayer.begin(mySoftwareSerial)){
    Serial.println("DFPlayer Mini non trovato.");
    while(true);
  }
  myDFPlayer.volume(30);
  MIDI.begin(MIDI_CHANNEL_OMNI);

  /////////////////////// SETUP VARIABILI PAD E DI LAVORO ///////////////////////////
  pinMode(PAD1, INPUT_PULLUP);
  pinMode(PAD2, INPUT_PULLUP);
  pinMode(PAD3, INPUT_PULLUP);
  pinMode(PAD4, INPUT_PULLUP);
  pinMode(PAD5, INPUT_PULLUP);
  pinMode(PAD6, INPUT_PULLUP);
  pinMode(PAD7, INPUT_PULLUP);
  pinMode(PAD8, INPUT_PULLUP);
  pinMode(PAD9, INPUT_PULLUP);
  pinMode(PROG, INPUT_PULLUP);
  pinMode(UP, INPUT_PULLUP);
  pinMode(LED, OUTPUT);

  stato = 1;  // 0 = Modalità PLAY SD, 1 = Schermata MENU', 2 = Modalità MIDI.
  sottostato = 0;
  I = 1;
  maxx = EEPROM.read(10);

  /////////////////////// SCHERMATA DI AVVIO ///////////////////////////
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);  
  display.setCursor(10, 25);  
  display.print("OPENDRUMS");
  display.display();

  delay(2000);

  display.clearDisplay();
  display.display();

  /////////////////////// SCHERMATA MENU' ///////////////////////////

  while (Serial && stato == 1) {  // Controlla se la seriale è attiva

    if (digitalRead(UP) == LOW) { 
      I = I + 1;
      if (I > 2) {
        I = 1;
      }
      delay(120);
    }
    
    if (sottostato == 0){
    if (I == 1){
      display.clearDisplay();
      display.setTextColor(SSD1306_WHITE);
      display.setTextSize(2);  
      display.setCursor(5, 1);  
      display.print("SETUP?");
      display.setCursor(5, 30);  
      display.print("[YES]  NO");
      display.display();
    }

    if (I == 2){
      display.clearDisplay();
      display.setTextColor(SSD1306_WHITE);
      display.setTextSize(2);  
      display.setCursor(5, 1);  
      display.print("SETUP?");
      display.setCursor(5, 30);  
      display.print("YES  [NO]");
      display.display();
    }

    if (digitalRead(PROG) == LOW && I == 1) {

      display.clearDisplay();
      display.setTextColor(SSD1306_WHITE);
      display.setTextSize(2);  
      display.setCursor(5, 1);  
      display.print("SETUP ON!");
      display.setCursor(5, 25);  
      display.print("Go to your Computer!");
      display.display();

      while (Serial.available() == 0) {
      }

      maxx = Serial.parseInt();  // Legge un numero intero
      EEPROM.write(10,maxx);

      Serial.print("Numero salvato: ");
      Serial.println(maxx);

      sottostato = 1;  
      I = 1;
    }

    if (digitalRead(PROG) == LOW && I == 2) {
      sottostato = 1;  
      I = 1;
      delay(200);
    }
    }

    /////////////////////////////////////////////////////////////////
    
    if (sottostato == 1){
    if (I == 1){
      display.clearDisplay();
      display.setTextColor(SSD1306_WHITE);
      display.setTextSize(2);  
      display.setCursor(5, 1);  
      display.print("MIDI?");
      display.setCursor(5, 30);  
      display.print("[YES]  NO");
      display.display();
    }

    if (I == 2){
      display.clearDisplay();
      display.setTextColor(SSD1306_WHITE);
      display.setTextSize(2);  
      display.setCursor(5, 1);  
      display.print("MIDI?");
      display.setCursor(5, 30);  
      display.print("YES  [NO]");
      display.display();
    }

    if (digitalRead(PROG) == LOW && I == 1) {
      stato = 2;  // 2 = Modalità MIDI
      I = 1;

      SPAD1 = EEPROM.read(11);
      SPAD2 = EEPROM.read(12);
      SPAD3 = EEPROM.read(13);
      SPAD4 = EEPROM.read(14);
      SPAD5 = EEPROM.read(15);
      SPAD6 = EEPROM.read(16);
      SPAD7 = EEPROM.read(17);
      SPAD8 = EEPROM.read(18);
      SPAD9 = EEPROM.read(19);

      delay(200);
    }

    if (digitalRead(PROG) == LOW && I == 2) {
      stato = 0;  // 0 = Modalità PLAY
      I = 1;

      SPAD1 = EEPROM.read(1);
      SPAD2 = EEPROM.read(2);
      SPAD3 = EEPROM.read(3);
      SPAD4 = EEPROM.read(4);
      SPAD5 = EEPROM.read(5);
      SPAD6 = EEPROM.read(6);
      SPAD7 = EEPROM.read(7);
      SPAD8 = EEPROM.read(8);
      SPAD9 = EEPROM.read(9);

      delay(200);
    }
    }
  }

  display.clearDisplay();
  display.display();
}



///////////////////////////////////////////////////////////////////////// VOID LOOP ////////////////////////////////////////////////////////////////////////////
void loop() {

  potValue = analogRead(POT);

    if (volValue != potValue/30){
      volValue = potValue / 30;
    if (volValue < 1) {
        volValue = 1;
    } else if (volValue > 30) {
        volValue = 30;
    }
    
    myDFPlayer.volume(volValue);
    }

  /////////////////////////////////////// MODALITA' SD PLAY ////////////////////////////////////////////
  
  if (stato == 0){

  /////////////////////// PROGRAMMAZIONE SUONI /////////////////////////////

  if (digitalRead(PROG) == LOW && sottostato == 0) {
    sottostato = 1;  // 1 = Modalità programma ON
    delay(200);
  }
  if (digitalRead(PROG) == LOW && sottostato == 1) {
    sottostato = 0;  // 0 = Modalità programma OFF, Modalità PLAY ON
    delay(200);
  }

  if (sottostato == 1) {
    digitalWrite(LED, HIGH);
    
    if (digitalRead(UP) == LOW) { 
      I = I + 1;
      if (I > maxx) {
        I = 1;
      }
      delay(120);
    }

    display.clearDisplay();  // Schermata per indicare il file che si sta scegliendo
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(5, 1);
    display.print("PROGM. ON!");
    display.setCursor(5, 25);
    display.print("File ");
    display.print(I);
    display.display();

    if (digitalRead(PAD1) == LOW) {
      SPAD1 = I;
      EEPROM.write(1,SPAD1);
    }
    if (digitalRead(PAD2) == LOW) {
      SPAD2 = I;
      EEPROM.write(2,SPAD2);
    }
    if (digitalRead(PAD3) == LOW) {
      SPAD3 = I;
      EEPROM.write(3,SPAD3);
    } 
    if (digitalRead(PAD4) == LOW) {
      SPAD4 = I;
      EEPROM.write(4,SPAD4);
    }
    if (digitalRead(PAD5) == LOW) {
      SPAD5 = I;
      EEPROM.write(5,SPAD5);
    }
    if (digitalRead(PAD6) == LOW) {
      SPAD6 = I;
      EEPROM.write(6,SPAD6);
    } 
    if (digitalRead(PAD7) == LOW) {
      SPAD7 = I;
      EEPROM.write(7,SPAD7);
    }
    if (digitalRead(PAD8) == LOW) {
      SPAD8 = I;
      EEPROM.write(8,SPAD8);
    }
    if (digitalRead(PAD9) == LOW) {
      SPAD9 = I;
      EEPROM.write(9,SPAD9);
    } 
  } 
  else {
    digitalWrite(LED, LOW);
    display.clearDisplay();
    display.display();
  }
  
  ////////////////////////////////////////////////////////////////

  if (digitalRead(PAD1) == LOW) {
    myDFPlayer.play(SPAD1);
    delay(50);
  }
  if (digitalRead(PAD2) == LOW) {
    myDFPlayer.play(SPAD2); 
    delay(50);
  }
   if (digitalRead(PAD3) == LOW) {
    myDFPlayer.play(SPAD3);
    delay(50); 
  } 
  if (digitalRead(PAD4) == LOW) {
    myDFPlayer.play(SPAD4);
    delay(50);
  }
  if (digitalRead(PAD5) == LOW) {
    myDFPlayer.play(SPAD5); 
    delay(50);
  }
   if (digitalRead(PAD6) == LOW) {
    myDFPlayer.play(SPAD6);
    delay(50); 
  } 
  if (digitalRead(PAD7) == LOW) {
    myDFPlayer.play(SPAD7);
    delay(50);
  }
  if (digitalRead(PAD8) == LOW) {
    myDFPlayer.play(SPAD8); 
    delay(50);
  }
   if (digitalRead(PAD9) == LOW) {
    myDFPlayer.play(SPAD9);
    delay(50); 
  }
  }

  /////////////////////// MODALITA' MIDI PLAY ///////////////////////////
  
  if (stato == 2){
  if (digitalRead(PROG) == LOW && sottostato == 0) {
    sottostato = 1;  // 1 = Modalità programma ON
    delay(200);
  }
  if (digitalRead(PROG) == LOW && sottostato == 1) {
    sottostato = 0;  // 0 = Modalità programma OFF, Modalità PLAY ON
    delay(200);
  }

  if (sottostato == 1) {
    digitalWrite(LED, HIGH);
    
    if (digitalRead(UP) == LOW) { 
      I = I + 1;
      if (I > 127) {
        I = 0;
      }
      delay(120);
    }

    display.clearDisplay();  // Schermata per indicare il valore midi che si sta scegliendo
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(5, 1);
    display.print("PROGM. ON!");
    display.setCursor(5, 25);
    display.print("Midi ");
    display.print(I);
    display.display();

    if (digitalRead(PAD1) == LOW) {
      SPAD1 = I;
      EEPROM.write(11,SPAD1);
    }
    if (digitalRead(PAD2) == LOW) {
      SPAD2 = I;
      EEPROM.write(12,SPAD2);
    }
    if (digitalRead(PAD3) == LOW) {
      SPAD3 = I;
      EEPROM.write(13,SPAD3);
    } 
    if (digitalRead(PAD4) == LOW) {
      SPAD4 = I;
      EEPROM.write(14,SPAD4);
    }
    if (digitalRead(PAD5) == LOW) {
      SPAD5 = I;
      EEPROM.write(15,SPAD5);
    }
    if (digitalRead(PAD6) == LOW) {
      SPAD6 = I;
      EEPROM.write(16,SPAD6);
    } 
    if (digitalRead(PAD7) == LOW) {
      SPAD7 = I;
      EEPROM.write(17,SPAD7);
    }
    if (digitalRead(PAD8) == LOW) {
      SPAD8 = I;
      EEPROM.write(18,SPAD8);
    }
    if (digitalRead(PAD9) == LOW) {
      SPAD9 = I;
      EEPROM.write(19,SPAD9);
    } 
  } 
  else {
    digitalWrite(LED, LOW);
    display.clearDisplay();
    display.display();
  }
  
  /////////////////////////////////////////////////////////////////

  if (digitalRead(PAD1) == LOW) {
    Serial.println(SPAD1);
    MIDI.sendNoteOn(SPAD1, 127, 1);
    delay(50);
  }
  if (digitalRead(PAD2) == LOW) {
    Serial.println(SPAD2);
    MIDI.sendNoteOn(SPAD2, 127, 1);
    delay(50);
  }
  if (digitalRead(PAD3) == LOW) {
    Serial.println(SPAD3);
    MIDI.sendNoteOn(SPAD3, 127, 1);
    delay(50); 
  } 
  if (digitalRead(PAD4) == LOW) {
    Serial.println(SPAD4);
    MIDI.sendNoteOn(SPAD4, 127, 1);
    delay(50);
  }
  if (digitalRead(PAD5) == LOW) {
    Serial.println(SPAD5);
    MIDI.sendNoteOn(SPAD5, 127, 1);
    delay(50);
  }
  if (digitalRead(PAD6) == LOW) {
    Serial.println(SPAD6);
    MIDI.sendNoteOn(SPAD6, 127, 1);
    delay(50); 
  } 
  if (digitalRead(PAD7) == LOW) {
    Serial.println(SPAD7);
    MIDI.sendNoteOn(SPAD7, 127, 1);
    delay(50);
  }
  if (digitalRead(PAD8) == LOW) {
    Serial.println(SPAD8);
    MIDI.sendNoteOn(SPAD8, 127, 1);
    delay(50);
  }
  if (digitalRead(PAD9) == LOW) {
    Serial.println(SPAD9);
    MIDI.sendNoteOn(SPAD9, 127, 1);
    delay(50); 
  }
  } 
  
}