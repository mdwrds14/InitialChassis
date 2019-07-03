//
// Created by jarrett on 7/3/19.
//

#include "main.h"

#include <Arduino.h>

#define VERSION_NUMBER 19


#define DIRB1 24
#define DIRA1 22
#define DIRB2 25
#define DIRA2 23
#define PWMA 9
#define PWMB 3

uint8_t x = 0;

void setup() {
    pinMode(13, OUTPUT);

    for (int i = 0; i < 50; i++) {
        digitalWrite(13, HIGH);
        delay(i);
        digitalWrite(13, LOW);
        delay(50-i);
    }

    Serial.begin(115200);
    Serial.print(":version-num \"");
    Serial.print(VERSION_NUMBER);
    Serial.println("\"");


    pinMode(DIRB1, OUTPUT);
    pinMode(DIRB2, OUTPUT);
    pinMode(DIRA1, OUTPUT);
    pinMode(DIRA2, OUTPUT);
    pinMode(PWMA, OUTPUT);
    pinMode(PWMB, OUTPUT);
}

void loop() {
    delay(10);
//    digitalWrite(13, HIGH);
//    delay(750);
//    Serial.println(":led-on false");
//    digitalWrite(13, LOW);
//    delay(250);
//    Serial.println(":led-on true");
    
    x += 5;
    Serial.print(":x ");
    Serial.println(x);



    digitalWrite(DIRB1, HIGH);
    digitalWrite(DIRB2, LOW);
    digitalWrite(DIRA1, LOW);
    digitalWrite(DIRA2, HIGH);

    analogWrite(PWMA, x);
    Serial.print(":speedA ");
    Serial.println(x);
    analogWrite(PWMB, x);
    Serial.print(":speedB ");
    Serial.println(x);
}