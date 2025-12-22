#include <Arduino.h>
#include "ledControl/ledDigital.h"


LedDigital::LedDigital(const PinInfo& p)
    : pin(p) {}

// Inicializa el pin como salida y apaga el LED
void LedDigital::begin() {
    pinMode(pin.number, OUTPUT);
    digitalWrite(pin.number, LOW);
    state = false;
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

// Cambia el estado del LED
void LedDigital::toggle() {
    state = !state;
    digitalWrite(pin.number, state ? HIGH : LOW);
}

// Devuelve el estado actual
bool LedDigital::getState() const {
    return state;
}

// Parpadeo simple bloqueante
void LedDigital::blink(unsigned long ms) {
    on();
    delay(ms);
    off();
    delay(ms);
}
