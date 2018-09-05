//
// Created by ferna on 04/09/2018.
//

#ifndef LETTER_BOX_BOX_H
#define LETTER_BOX_BOX_H


#include "Sensor.h"
#include "Led.h"

class Box {

private:
    Sensor *slotSensor;
    Sensor *doorSensor;
    Led *letterLed;
    Sensor *collectButton;

public:
    Box(Sensor *slotSensor, Sensor *doorSensor, Led *letterLed);

    void loop();

    void onReceiveLetter();

    Sensor *getSlotSensor() const;

    void setSlotSensor(Sensor *slotSensor);

    Sensor *getDoorSensor() const;

    void setDoorSensor(Sensor *doorSensor);

    Led *getLetterLed() const;

    void setLetterLed(Led *letterLed);

    virtual ~Box();
};


#endif //LETTER_BOX_BOX_H
