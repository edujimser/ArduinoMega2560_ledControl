#ifndef LED_RGB_H
#define LED_RGB_H

#include <Arduino.h>
#include "../System/pinout/pinout.h"

class LedRGB {

    private:
        const PinInfo& pinRed;                   //Red pin
        const PinInfo& pinGreen;                  //Green pin
        const PinInfo& pinBlue;                  //Blue pin
    public:
        explicit LedRGB(const PinInfo& pinRed, const PinInfo& pinGreen, const PinInfo& pinBlue);

        void on();
        void off();
        void setColor(uint8_t redValue, uint8_t greenValue, uint8_t blueValue);

};

#endif // LED_RGB_H