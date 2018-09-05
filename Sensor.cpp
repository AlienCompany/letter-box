//
// Created by ferna on 04/09/2018.
//

#include "Sensor.h"
#include <Arduino.h>
Sensor::Sensor(uint8_t PIN_SENSOR) : PIN_SENSOR(PIN_SENSOR) {}

Sensor::~Sensor() {}

SensorEventCode Sensor::checkChange() {
    SensorState valueSensor = (SensorState) digitalRead(PIN_SENSOR);

    if (valueSensor != currentState){
        currentState = valueSensor;
        if(currentState == OPENED){
            return OPEN;
        }else{
            return CLOSE;
        }
    }

    return NONE;
}

SensorState Sensor::getState() {
    return currentState;
}
