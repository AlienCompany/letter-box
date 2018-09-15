//
// Created by ferna on 04/09/2018.
//

#ifndef LETTER_BOX_BOX_H
#define LETTER_BOX_BOX_H


#include "Sensor.h"
#include "Led.h"
#include "CommunicationService.h"

class Box {

private:
    Sensor *slotSensor;
    Sensor *doorSensor;
    Led *letterLed;
    Sensor *collectButton;
    Led *packetLed;
    Sensor *callingCardSensor;
    Led *callingCardLed;

    bool hasLetter = false;
    bool hasPacket = false;
    bool hasCallingCard = false;

   CommunicationService* communicationService;


public:
    Box(Sensor *slotSensor, Sensor *doorSensor, Led *letterLed, Sensor *collectButton, Led *packetLed,
            Sensor *callingCardSensor, Led *callingCardLed);


    void loop();

    void onReceiveLetter();

    void onReceivePacket();

    void onCollect();

    Sensor *getSlotSensor() const;

    void setSlotSensor(Sensor *slotSensor);

    Sensor *getDoorSensor() const;

    void setDoorSensor(Sensor *doorSensor);

    Led *getLetterLed() const;

    void setLetterLed(Led *letterLed);

    Led *getPacketLed() const;

    void setPacketLed(Led *packetLed);

    Sensor *getCollectButton() const;

    void setCollectButton(Sensor *collectButton);

    Sensor *getCallingCardSensor() const;

    void setCallingCardSensor(Sensor *callingCardSensor);

    Led *getCallingCardLed() const;

    void setCallingCardLed(Led *callingCardLed);

    virtual ~Box();

    void onReceiveCallingCard();
};


#endif //LETTER_BOX_BOX_H
