//
// Created by ferna on 05/09/2018.
//

#include "Led.h"

Led::Led(uint8_t PIN_LED) : PIN_LED(PIN_LED) {}

Led::Led(uint8_t PIN_LED, int brightness) : PIN_LED(PIN_LED), brightness(brightness) {}

void Led::init() {

    analogWrite(PIN_LED, brightness);
}

int Led::getBrightness() const {
    return brightness;
}

void Led::setBrightness(int brightness) {
    Led::brightness = brightness;
    analogWrite(PIN_LED, brightness);
}

Led::~Led() {}
