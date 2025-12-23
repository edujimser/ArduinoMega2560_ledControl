#include <Arduino.h>
#include "ledControl/ledPWM.h"

LedPWM::LedPWM(const PinInfo& pin)
    : pin(pin){
        
    if (!isValidPWM(pin)){
            Serial.println();
            Serial.print("LED PWM: Pin inválido -> ");
            Serial.print("name: ");   Serial.print(pin.name);
            Serial.print(", number: "); Serial.print(pin.number);
            Serial.print(", family: "); Serial.println(pin.family);
            
            Serial.println();
            Serial.println("Sistema detenido por error crítico.");
            delay(100);
            cli();
            while (true) { __asm__("nop"); };};
}