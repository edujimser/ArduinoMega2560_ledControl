#ifndef LED_H
#define LED_H

#include <Arduino.h>

#include "../System/pinout/pinout.h"

class LedDigital {
    private:
        const PinInfo& pin;
        bool state;
    
        public:
    explicit LedDigital(const PinInfo& pin, bool state)
        : pin(pin), 
          state(state)
        {   
            if (!isValidGPIO(pin.number)) { Serial.println("LED Digital: Pin inválido"); return; }
            
        }

        void begin();
        void on();
        void off();
        void toggle();
        bool getState() const;
        void blink(unsigned long ms);
};

#endif // LED_H
        void begin();
        void on();
        void off();
        void toggle();
        bool getState() const;
        void blink(unsigned long ms);
};

#endif // LED_H