#include <IRremote.h>


IRsend irsend;

unsigned int baudRate = 9600;
unsigned int shortBreak = 400;
unsigned int longBreak = 5000;
unsigned int frequency = 38;

unsigned int menuBtn[68] = {9200,4500,650,500,650,1650,650,1650,700,1600,700,500,650,1650,650,1650,650,1650,650,1650,700,1600,700,1650,650,500,650,550,650,500,650,550,650,1650,650,1650,650,1650,650,550,650,500,650,550,650,500,650,500,700,500,650,500,700,1650,650,1650,650,1650,650,1650,650,500,700,500,650,1650,650};
unsigned int playBtn[68] = {9200,4500,650,500,650,1650,650,1650,700,1650,650,500,650,1650,650,1650,650,1650,650,1650,700,1600,700,1600,700,500,650,550,650,500,650,500,700,1650,650,1650,650,500,650,1650,650,550,650,500,650,550,600,550,650,550,650,500,650,1650,650,1650,650,1650,650,1700,650,500,650,500,700,1650,650};
unsigned int leftBtn[68] = {9200,4550,600,550,650,1650,650,1650,650,1700,600,550,650,1650,650,1650,650,1700,600,1700,600,1700,650,1650,650,550,600,550,650,550,600,550,650,1650,650,1700,600,550,650,550,600,1700,650,500,650,550,650,500,650,550,650,550,600,1700,600,1700,600,1700,650,1650,650,550,600,550,650,1650,650};
unsigned int rightBtn[68] = {9200,4500,650,550,650,1650,650,1650,650,1650,650,550,650,1650,650,1650,650,1650,650,1650,650,1650,650,1650,650,550,650,500,700,500,650,500,650,1650,700,500,650,1650,650,1650,650,550,600,550,650,550,650,500,650,550,650,500,650,1650,650,1650,650,1650,700,1600,700,500,650,550,650,1650,650};
unsigned int topBtn[68] = {9340,4600,580,580,640,1640,600,1700,580,1700,600,560,580,1700,600,1700,580,1700,600,1700,580,1700,600,1700,580,580,560,580,580,580,580,580,580,1700,580,580,580,1700,580,580,580,1700,580,580,580,580,580,560,600,560,580,580,580,560,600,580,560,580,580,1700,580,1720,580,1700,580,600,580}; 
unsigned int bottomBtn[68] = {9360,4580,580,580,580,1700,580,1700,600,1700,580,560,600,1700,580,1700,580,1720,580,1700,580,1700,600,1680,600,560,580,580,580,560,600,560,580,1700,600,560,580,580,580,1700,580,1700,580,580,580,580,580,600,560,560,580,580,580,560,600,580,560,560,600,1700,580,1700,580,1720,580,580,580};
unsigned int btnRawLength = 68;

void setup() { 
  Serial.begin(baudRate);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Goodnight moon!");
}



void loop() {
  if (Serial.available()) {
    char v = Serial.read();

    if (v == 't') {
      Serial.println("top");
      top();
    } else if (v == 'b') {
      Serial.println("bottom");
      bottom();
    } else if (v == 'l') {
      Serial.println("left");
      left();
    } else if (v == 'r') {
      Serial.println("right");
      right();
    } else if (v == 'm') {
      Serial.println("menu");
      menu();
    } else if (v == 'p') {
      Serial.println("play");
      play();
    }
  }
}

void menu() {
    irsend.sendRaw(menuBtn, btnRawLength, frequency);
    delay(shortBreak);
}

void play() {
    irsend.sendRaw(playBtn, btnRawLength, frequency);
    delay(shortBreak);
}

void left() {
    irsend.sendRaw(leftBtn, btnRawLength, frequency);
    delay(shortBreak);
}

void right() {
    irsend.sendRaw(rightBtn, btnRawLength, frequency);
    delay(shortBreak);
}

void top() {
    irsend.sendRaw(topBtn, btnRawLength, frequency);
    delay(shortBreak);
}

void bottom() {
    irsend.sendRaw(bottomBtn, btnRawLength, frequency);
    delay(shortBreak);
}
