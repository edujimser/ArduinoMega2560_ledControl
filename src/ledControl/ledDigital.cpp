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
            delay(100);
            cli();
            while (true) { __asm__("nop"); };};
}

// On LED
void LedDigital::on() {
    digitalWrite(pin.number, HIGH);
    state = true;
}

// Off LED
void LedDigital::off() {
    digitalWrite(pin.number, LOW);
    state = false;
}

// Blinking LED
void LedDigital::blinking(int ms_On, int ms_Off) {
    static unsigned long lastChange = 0;
    static bool state = false;

    unsigned long now = millis();

    int interval = state ? ms_On : ms_Off;

    if (now - lastChange >= interval) {
        state = !state;
        lastChange = now;

        if (state)
            this->on();
        else
            this->off();
    }
}
