//
// Created by ferna on 04/09/2018.
//

#include "Box.h"
#include <Arduino.h>

Box::Box(Sensor *slotSensor, Sensor *doorSensor, Led *letterLed, Sensor *collectButton, Led *packetLed)
        : slotSensor(slotSensor), doorSensor(doorSensor), letterLed(letterLed), collectButton(collectButton),
          packetLed(packetLed) {}

Box::~Box() {}

void Box::loop() {

    SensorEventCode slotCode = slotSensor->checkChange();
    SensorEventCode doorCode = doorSensor->checkChange();
    SensorEventCode collectCode = collectButton->checkChange();

    if (slotCode == OPEN) {
        onReceiveLetter();
    }
    if (doorCode == OPEN) {
        onReceivePacket();
    }
    if (collectCode == OPEN) {
        onCollect();
    }
}

void Box::onReceiveLetter() {

    Serial.println("onReceiveLetter");
    letterLed->setBrightness(255);


}

void Box::onReceivePacket(){

    Serial.println("onReceivePacket");
    packetLed->setBrightness(255);

}

void Box::onCollect() {

    Serial.println("onCollect");
    letterLed->setBrightness(0);
    packetLed->setBrightness(0);

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

Led *Box::getPacketLed() const {
    return packetLed;
}

void Box::setPacketLed(Led *packetLed) {
    Box::packetLed = packetLed;
}

