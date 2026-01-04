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

// On LED
void LedPWM::on() {
    analogWrite(pin.number, 255);
    state = true;
}

// Off LED 
void LedPWM::off(){
    analogWrite(pin.number, 0);
    state = false;
}

// On LED with intensity
void LedPWM::onIntensity(uint8_t intensity) {
    uint8_t intesityPrepared = constrain(intensity, 0, 255);
    analogWrite(pin.number, intesityPrepared);
    state = (intesityPrepared > 0);
}

// Fade In LED (non-blocking)
void LedPWM::onFadeIn(int duration_ms, int steps) {
    static unsigned long lastUpdate = 0;
    static int currentIntensity = 0;
    static bool running = false;

    if (steps <= 0) { steps = 1; } // Prevent division by zerO
    if (duration_ms <= 0) { duration_ms = 1; } // Prevent division by zero

    // Start fade if not running
    if (!running) {
        running = true;
        currentIntensity = 0;
        lastUpdate = millis();
        analogWrite(pin.number, currentIntensity);
    }

    unsigned long now = millis();
    unsigned long interval = duration_ms / steps;

    // Update intensity only when interval has passed
    if (running && (now - lastUpdate >= interval)) {
        lastUpdate = now;

        currentIntensity += (255 / steps);
        if (currentIntensity > 255) {
            currentIntensity = 255;
            running = false;   // Fade finished
        }

        analogWrite(pin.number, currentIntensity);
        state = (currentIntensity > 0);
    }
}

// Fade Out LED (non-blocking)
void LedPWM::onFadeOut(int duration_ms, int steps) {
    static unsigned long lastUpdate = 0;
    static int currentIntensity = 255;
    static bool running = false;

    if (steps <= 0) { steps = 1; } // Prevent division by zero
    if (duration_ms <= 0) { duration_ms = 1; } // Prevent division by zero

    // Start fade if not running
    if (!running) {
        running = true;
        currentIntensity = 255;
        lastUpdate = millis();
        analogWrite(pin.number, currentIntensity);
    }

    unsigned long now = millis();
    unsigned long interval = duration_ms / steps;

    // Update intensity only when interval has passed
    if (running && (now - lastUpdate >= interval)) {
        lastUpdate = now;

        currentIntensity -= (255 / steps);
        if (currentIntensity < 0) {
            currentIntensity = 0;
            running = false;   // Fade finished
        }

        analogWrite(pin.number, currentIntensity);
        state = (currentIntensity > 0);
    }
}

// Blinking LED (non-blocking)
void LedPWM::blinking(int ms_On, int ms_Off) {
    static unsigned long lastToggle = 0;
    static bool ledState = false;

    unsigned long now = millis();

    if (ledState && (now - lastToggle >= (unsigned long)ms_On)) {
        // Turn off LED
        analogWrite(pin.number, 0);
        ledState = false;
        lastToggle = now;
        state = false;
    } 
    else if (!ledState && (now - lastToggle >= (unsigned long)ms_Off)) {
        // Turn on LED
        analogWrite(pin.number, 255);
        ledState = true;
        lastToggle = now;
        state = true;
    }
}

// Blinking LED with intensity (non-blocking)
void LedPWM::blinkingIntensity(uint8_t intensity, int ms_On, int ms_Off) {
    static unsigned long lastToggle = 0;
    static bool ledState = false;

    unsigned long now = millis();

    if (ledState && (now - lastToggle >= (unsigned long)ms_On)) {
        // Turn off LED
        analogWrite(pin.number, 0);
        ledState = false;
        lastToggle = now;
        state = false;
    } 
    else if (!ledState && (now - lastToggle >= (unsigned long)ms_Off)) {
        // Turn on LED
        analogWrite(pin.number, intensity);
        ledState = true;
        lastToggle = now;
        state = true;
    }
}