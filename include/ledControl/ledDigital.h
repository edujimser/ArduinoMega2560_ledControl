#ifndef LED_H
#define LED_H

#include <Arduino.h>

#include "../System/pinout/pinout.h"

class LedDigital {
    private:
        const PinInfo& pin;                 //Constructor pin
        bool state;                         //State of LED
    public:
        explicit LedDigital(const PinInfo& pin);
        
        void on();                                                         //On LED
        void off();                                                        //Off LED
        void blinking(unsigned long ms_On, unsigned long ms_Off);          //Blinking LED

};


#endif // LED_H