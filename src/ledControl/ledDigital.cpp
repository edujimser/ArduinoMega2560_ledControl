#include <Arduino.h>
#include "ledControl/ledDigital.h"


LedDigital::LedDigital(const PinInfo& pin)
    : pin(pin){
        
    if (!isValidGPIO(pin)){
            Serial.println();
            Serial.print("LED Digital: Pin inválido -> ");
            Serial.print("name: ");   Serial.print(pin.name);
            Serial.print(", number: "); Serial.print(pin.number);
            Serial.print(", family: "); Serial.println(pin.family);
            
            Serial.println();
            Serial.println("Sistema detenido por error crítico.");
            cli();
            while (true) { __asm__("nop"); };};
}

// Enciende el LED
void LedDigital::on() {
    digitalWrite(pin.number, HIGH);
    state = true;
}

// Apaga el LED
void LedDigital::off() {
    digitalWrite(pin.number, LOW);
    state = false;
}

