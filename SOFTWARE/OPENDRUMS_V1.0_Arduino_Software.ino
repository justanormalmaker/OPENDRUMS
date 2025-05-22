#include <BLEMIDI_Transport.h>
#include <hardware/BLEMIDI_ESP32.h>
#include <Preferences.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <HardwareSerial.h>
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
int SPAD1;
int SPAD2;
int SPAD3;
int SPAD4;
int SPAD5;
int SPAD6;
int SPAD7;
int SPAD8;
int SPAD9;

/////////////////////// DICHIARAZIONE VARIABILI DI LAVORO ///////////////////////////
int LED = 13;
int stato, sottostato;
int I;
int maxx;
int potValue;
int newVolValue;
int volValue;

Preferences prefs;

/////////////////////// DICHIARAZIONE OLED/DFPLAYERMINI/MIDI ///////////////////////////
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1  // Pin di reset, non usato con i display I2C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

HardwareSerial mySerial(1); // Pin 5 per RX, Pin 6 per TX
DFRobotDFPlayerMini myDFPlayer;

BLEMIDI_CREATE_INSTANCE("OPENDRUMS", MIDI)


///////////////////////////////////////////////////////////////////////// VOID SETUP ////////////////////////////////////////////////////////////////////////////
void setup() {
  
  /////////////////////// SETUP OLED/DFPLAYERMINI E SERIALI ///////////////////////////
  Serial.begin(115200);
  mySerial.begin(9600,SERIAL_8N1, 5, 6);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
  Serial.println(F("SSD1306 allocation fallita"));
  for(;;);
  }

  if (!myDFPlayer.begin(mySerial)) {
    Serial.println("DFPlayer Mini non trovato.");
    while (true);
  }
  myDFPlayer.volume(30);

  MIDI.begin();

  prefs.begin("config", false);

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
  maxx = prefs.getInt("MAXX", 0);

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

  while (stato == 1) {  // Controlla se la seriale è attiva

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
      prefs.putInt("MAXX", maxx);

      Serial.print("Saved Number: ");
      Serial.println(maxx);

      sottostato = 1;  // 0 = Modalità PLAY
      I = 1;
    }

    if (digitalRead(PROG) == LOW && I == 2) {
      sottostato = 1;  // 0 = Modalità PLAY
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

      SPAD1 = prefs.getInt("MPAD1", 0);
      SPAD2 = prefs.getInt("MPAD2", 0);
      SPAD3 = prefs.getInt("MPAD3", 0);
      SPAD4 = prefs.getInt("MPAD4", 0);
      SPAD5 = prefs.getInt("MPAD5", 0);
      SPAD6 = prefs.getInt("MPAD6", 0);
      SPAD7 = prefs.getInt("MPAD7", 0);
      SPAD8 = prefs.getInt("MPAD8", 0);
      SPAD9 = prefs.getInt("MPAD9", 0);

      delay(200);
    }

    if (digitalRead(PROG) == LOW && I == 2) {
      stato = 0;  // 0 = Modalità PLAY
      I = 1;

      SPAD1 = prefs.getInt("SPAD1", 0);
      SPAD2 = prefs.getInt("SPAD2", 0);
      SPAD3 = prefs.getInt("SPAD3", 0);
      SPAD4 = prefs.getInt("SPAD4", 0);
      SPAD5 = prefs.getInt("SPAD5", 0);
      SPAD6 = prefs.getInt("SPAD6", 0);
      SPAD7 = prefs.getInt("SPAD7", 0);
      SPAD8 = prefs.getInt("SPAD8", 0);
      SPAD9 = prefs.getInt("SPAD9", 0);

      delay(200);
    }
    }
  }
  
  if (stato == 1){
    stato = 0;
    sottostato = 1;
  }
  

  display.clearDisplay();
  display.display();
}



///////////////////////////////////////////////////////////////////////// VOID LOOP ////////////////////////////////////////////////////////////////////////////
void loop() {

  potValue = analogRead(POT);
  newVolValue = potValue / 34;

  if (newVolValue < 1) newVolValue = 1;
  if (newVolValue > 30) newVolValue = 30;

  if (newVolValue != volValue) {
  volValue = newVolValue;

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
      Serial.println(I);
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
      prefs.putInt("SPAD1", SPAD1);
    }
    if (digitalRead(PAD2) == LOW) {
      SPAD2 = I;
      prefs.putInt("SPAD2", SPAD2);
    }
    if (digitalRead(PAD3) == LOW) {
      SPAD3 = I;
      prefs.putInt("SPAD3", SPAD3);
    } 
    if (digitalRead(PAD4) == LOW) {
      SPAD4 = I;
      prefs.putInt("SPAD4", SPAD4);
    }
    if (digitalRead(PAD5) == LOW) {
      SPAD5 = I;
      prefs.putInt("SPAD5", SPAD5);
    }
    if (digitalRead(PAD6) == LOW) {
      SPAD6 = I;
      prefs.putInt("SPAD6", SPAD6);
    } 
    if (digitalRead(PAD7) == LOW) {
      SPAD7 = I;
      prefs.putInt("SPAD7", SPAD7);
    }
    if (digitalRead(PAD8) == LOW) {
      SPAD8 = I;
      prefs.putInt("SPAD8", SPAD8);
    }
    if (digitalRead(PAD9) == LOW) {
      SPAD9 = I;
      prefs.putInt("SPAD9", SPAD9);
    } 
  } 
  else {
    digitalWrite(LED, LOW);
    display.clearDisplay();
    display.display();
  }
  
  
  if (digitalRead(PAD1) == LOW) {
    Serial.println(SPAD1);
    myDFPlayer.play(SPAD1);
    delay(50);
  }
  if (digitalRead(PAD2) == LOW) {
    Serial.println(SPAD2);
    myDFPlayer.play(SPAD2); 
    delay(50);
  }
   if (digitalRead(PAD3) == LOW) {
    Serial.println(SPAD3);
    myDFPlayer.play(SPAD3);
    delay(50); 
  } 
  if (digitalRead(PAD4) == LOW) {
    Serial.println(SPAD4);
    myDFPlayer.play(SPAD4);
    delay(50);
  }
  if (digitalRead(PAD5) == LOW) {
    Serial.println(SPAD5);
    myDFPlayer.play(SPAD5); 
    delay(50);
  }
   if (digitalRead(PAD6) == LOW) {
    Serial.println(SPAD6);
    myDFPlayer.play(SPAD6);
    delay(50); 
  } 
  if (digitalRead(PAD7) == LOW) {
    Serial.println(SPAD7);
    myDFPlayer.play(SPAD7);
    delay(50);
  }
  if (digitalRead(PAD8) == LOW) {
    Serial.println(SPAD8);
    myDFPlayer.play(SPAD8); 
    delay(50);
  }
   if (digitalRead(PAD9) == LOW) {
    Serial.println(SPAD9);
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
      Serial.println(I);
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
      prefs.putInt("MPAD1", SPAD1);
    }
    if (digitalRead(PAD2) == LOW) {
      SPAD2 = I;
      prefs.putInt("MPAD2", SPAD2);
    }
    if (digitalRead(PAD3) == LOW) {
      SPAD3 = I;
      prefs.putInt("MPAD3", SPAD3);
    } 
    if (digitalRead(PAD4) == LOW) {
      SPAD4 = I;
      prefs.putInt("MPAD4", SPAD4);
    }
    if (digitalRead(PAD5) == LOW) {
      SPAD5 = I;
      prefs.putInt("MPAD5", SPAD5);
    }
    if (digitalRead(PAD6) == LOW) {
      SPAD6 = I;
      prefs.putInt("MPAD6", SPAD6);
    } 
    if (digitalRead(PAD7) == LOW) {
      SPAD7 = I;
      prefs.putInt("MPAD7", SPAD7);
    }
    if (digitalRead(PAD8) == LOW) {
      SPAD8 = I;
      prefs.putInt("MPAD8", SPAD8);
    }
    if (digitalRead(PAD9) == LOW) {
      SPAD9 = I;
      prefs.putInt("MPAD9", SPAD9);
    } 
  } 
  else {
    digitalWrite(LED, LOW);
    display.clearDisplay();
    display.display();
  }
  
  
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