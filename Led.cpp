//
// Created by ferna on 05/09/2018.
//

#include "Led.h"

Led::Led(uint8_t PIN_LETTER_LED) : PIN_LETTER_LED(PIN_LETTER_LED) {}

Led::Led(uint8_t PIN_LETTER_LED, int brightness) : PIN_LETTER_LED(PIN_LETTER_LED), brightness(brightness) {}

void Led::init() {

    analogWrite(PIN_LETTER_LED, brightness);

}

int Led::getBrightness() const {
    return brightness;
}

void Led::setBrightness(int brightness) {
    Led::brightness = brightness;
    analogWrite(PIN_LETTER_LED, brightness);
}

Led::~Led() {}
