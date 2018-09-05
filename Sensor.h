//
// Created by ferna on 04/09/2018.
//

#ifndef LETTER_BOX_SENSOR_H
#define LETTER_BOX_SENSOR_H

#include <stdint-gcc.h>

enum SensorEventCode {
    OPEN,
    CLOSE,
    NONE
};

enum SensorState {
    OPENED = 0,
    CLOSED = 1
};

class Sensor {

private:
    uint8_t PIN_SENSOR;
    SensorState currentState;
    long lastEventDate = 0; // in ms
    long sensibility = 0; //in ms

public:
    Sensor(uint8_t PIN_SENSOR);

    Sensor(uint8_t PIN_SENSOR, long sensibility);

    virtual ~Sensor();

    SensorEventCode checkChange();

    SensorState getState();

    long getSensibility() const;

    void setSensibility(long sensibility);

};


#endif //LETTER_BOX_SENSOR_H
