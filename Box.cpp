//
// Created by ferna on 04/09/2018.
//

#include "Box.h"
#include <Arduino.h>

Box::Box(Sensor *slotSensor, Sensor *doorSensor, Led *letterLed) : slotSensor(slotSensor), doorSensor(doorSensor), letterLed(letterLed) {}

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
    letterLed->setBrightness(255);


}

Sensor *Box::getSlotSensor() const {
    return slotSensor;
}

void Box::setSlotSensor(Sensor *slotSensor) {
    Box::slotSensor = slotSensor;
}

Sensor *Box::getDoorSensor() const {
    return doorSensor;
}

void Box::setDoorSensor(Sensor *doorSensor) {
    Box::doorSensor = doorSensor;
}

Led *Box::getLetterLed() const {
    return letterLed;
}

void Box::setLetterLed(Led *letterLed) {
    Box::letterLed = letterLed;
}

