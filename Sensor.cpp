//
// Created by ferna on 04/09/2018.
//

#include "Sensor.h"
#include <Arduino.h>

Sensor::Sensor(uint8_t PIN_SENSOR) : PIN_SENSOR(PIN_SENSOR) {}

Sensor::Sensor(uint8_t PIN_SENSOR, long sensibility) : PIN_SENSOR(PIN_SENSOR), sensibility(sensibility) {}

Sensor::~Sensor() {}

SensorEventCode Sensor::checkChange() {
    if(lastEventDate + sensibility >= millis()){
        return NONE;
    }

    SensorState valueSensor = (SensorState) digitalRead(PIN_SENSOR);

    if (valueSensor != currentState ) {
        currentState = valueSensor;
        lastEventDate = millis();
        if (currentState == OPENED) {
            return OPEN;
        } else {
            return CLOSE;
        }
    }

    return NONE;
}

SensorState Sensor::getState() {
    return currentState;
}

long Sensor::getSensibility() const {
    return sensibility;
}

void Sensor::setSensibility(long sensibility) {
    Sensor::sensibility = sensibility;
}


