//
// Created by ferna on 04/09/2018.
//

#include "Box.h"
#include "CommunicationService.h"
#include <Arduino.h>

Box::Box(Sensor *slotSensor, Sensor *doorSensor, Led *letterLed, Sensor *collectButton, Led *packetLed,
         Sensor *callingCardSensor, Led *callingCardLed)
        : slotSensor(slotSensor), doorSensor(doorSensor), letterLed(letterLed), collectButton(collectButton),
          packetLed(packetLed), callingCardSensor(callingCardSensor), callingCardLed(callingCardLed) {
    communicationService = CommunicationService::getInstance();
}

Box::~Box() {}

void Box::loop() {

    SensorEventCode slotCode = slotSensor->checkChange();
    SensorEventCode doorCode = doorSensor->checkChange();
    SensorEventCode collectCode = collectButton->checkChange();
    SensorEventCode callingCardEventCode = callingCardSensor->checkChange();

    if (slotCode == OPEN) {
        onReceiveLetter();
    }
    if (doorCode == OPEN) {
        onReceivePacket();
    }
    if (callingCardEventCode == OPEN) {
        onReceiveCallingCard();
    }
    if (collectCode == OPEN) {
        onCollect();
    }
    if (millis() >= timeToSendNotif) {
        if (toSendNotificationReceive) {
            if (communicationService->sendNotificationReceive(hasLetter, hasPacket, hasCallingCard)){
                toSendNotificationReceive = false;
            } else{
                timeToSendNotif += 15000;
            }

        } else if (toSendNotificationCollect) {
            if (communicationService->sendNotificationCollect()) {
                toSendNotificationCollect = false;
            } else{
                timeToSendNotif += 15000;
            }
        }
    }
}

void Box::onReceiveLetter() {

    Serial.println("onReceiveLetter");
    letterLed->setBrightness(255);
    hasLetter = true;

    timeToSendNotif = millis() + 30000;
    toSendNotificationReceive = true;


}

void Box::onReceivePacket() {

    Serial.println("onReceivePacket");
    packetLed->setBrightness(255);
    hasPacket = true;

    timeToSendNotif = millis() + 30000;
    toSendNotificationReceive = true;


}

void Box::onReceiveCallingCard() {

    Serial.println("onReceiveCallingCard");
    callingCardLed->setBrightness(255);
    hasCallingCard = true;

    timeToSendNotif = millis() + 30000;
    toSendNotificationReceive = true;


}

void Box::onCollect() {

    Serial.println("onCollect");
    letterLed->setBrightness(0);
    hasLetter = false;
    packetLed->setBrightness(0);
    hasPacket = false;
    callingCardLed->setBrightness(0);
    hasCallingCard = false;

    timeToSendNotif = millis() + 30000;
    toSendNotificationCollect = true;


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

Sensor *Box::getCollectButton() const {
    return collectButton;
}

void Box::setCollectButton(Sensor *collectButton) {
    Box::collectButton = collectButton;
}

Sensor *Box::getCallingCardSensor() const {
    return callingCardSensor;
}

void Box::setCallingCardSensor(Sensor *callingCardSensor) {
    Box::callingCardSensor = callingCardSensor;
}

Led *Box::getCallingCardLed() const {
    return callingCardLed;
}

void Box::setCallingCardLed(Led *callingCardLed) {
    Box::callingCardLed = callingCardLed;
}

