#ifndef LEDPWM_H
#define LEDPWM_H

#include <Arduino.h>

#include "../System/pinout/pinout.h"

class LedPWM {
    private:
        const PinInfo& pin;                 //Constructor pin
        bool state;                         //State of LED
    public:
        explicit LedPWM(const PinInfo& pin);
        
        void on();                                                         //On LED                               
        void onIntensity(int intensity);                                   //On LED with intensity
        void onFadeIn(int duration_ms, int steps);                         //Fade In LED
        void onFadeOut(int duration_ms, int steps);                        //Fade Out LED
        void onFadeTotal(int duration_ms, int steps);                      //Fade In and Out LED
        void off();                                                        //Off LED
        void blinking(int ms_On, int ms_Off);                              //Blinking LED
        void blinkingIntensity(int intensity, int ms_On, int ms_Off);      //Blinking LED with intensity

};


#endif // LEDPWM_H