#include <Arduino.h>
#include "ledControl/ledRGB.h"

LedRGB::LedRGB(const PinInfo& pinRed, const PinInfo& pinGreen, const PinInfo& pinBlue)
    : pinRed(pinRed), pinGreen(pinGreen), pinBlue(pinBlue) {

    if (!isValidPWM(pinRed) || !isValidPWM(pinGreen) || !isValidPWM(pinBlue))
    {
        Serial.println();
        Serial.println("LED PWM: Pines inválidos detectados ->");
        
        if(!isValidPWM(pinRed))
        {
        // --- Pin RED ---
        Serial.print("  [RED]   name: ");   Serial.print(pinRed.name);
        Serial.print(", number: ");         Serial.print(pinRed.number);
        Serial.print(", family: ");         Serial.println(pinRed.family);
        }else if(!isValidPWM(pinGreen)){
        // --- Pin GREEN ---
        Serial.print("  [GREEN] name: ");   Serial.print(pinGreen.name);
        Serial.print(", number: ");         Serial.print(pinGreen.number);
        Serial.print(", family: ");         Serial.println(pinGreen.family);
        }else{
        // --- Pin BLUE ---
        Serial.print("  [BLUE]  name: ");   Serial.print(pinBlue.name);
        Serial.print(", number: ");         Serial.print(pinBlue.number);
        Serial.print(", family: ");         Serial.println(pinBlue.family);
        };
        Serial.println();
        Serial.println("Sistema detenido por error crítico.");
        delay(100);

        cli();
        while (true) { __asm__("nop"); };
    };
};

void LedRGB::on() {
    analogWrite(pinRed.number, 255);
    analogWrite(pinGreen.number, 255);
    analogWrite(pinBlue.number, 255);
}

void LedRGB::off(){
    analogWrite(pinRed.number, 0);
    analogWrite(pinGreen.number, 0);
    analogWrite(pinBlue.number, 0);
}

void LedRGB::setColor(uint8_t redValue, uint8_t greenValue, uint8_t blueValue) {
    uint8_t redPrepared = constrain(redValue, 0, 255);
    uint8_t greenPrepared = constrain(greenValue, 0, 255);
    uint8_t bluePrepared = constrain(blueValue, 0, 255);

    analogWrite(pinRed.number, redPrepared);
    analogWrite(pinGreen.number, greenPrepared);
    analogWrite(pinBlue.number, bluePrepared);
}