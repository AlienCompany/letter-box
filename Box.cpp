//
// Created by ferna on 04/09/2018.
//

#include "Box.h"
#include <Arduino.h>

Box::Box(Sensor *slotSensor, Sensor *doorSensor) : slotSensor(slotSensor), doorSensor(doorSensor) {}

Box::~Box() {}

void Box::loop() {

    SensorEventCode slotCode = slotSensor->checkChange();
    SensorEventCode doorCode = doorSensor->checkChange();

    if (slotCode == OPEN){
        onReceiveLetter();
    }

}

void Box::onReceiveLetter() {

    Serial.println("onReceiveLetter");

}

