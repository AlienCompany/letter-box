//
// Created by ferna on 04/09/2018.
//

#ifndef LETTER_BOX_BOX_H
#define LETTER_BOX_BOX_H


#include "Sensor.h"

class Box {

private:
    Sensor *slotSensor;
    Sensor *doorSensor;

public:
    Box(Sensor *slotSensor, Sensor *doorSensor);

    void loop();
    void onReceiveLetter();

    virtual ~Box();
};


#endif //LETTER_BOX_BOX_H
