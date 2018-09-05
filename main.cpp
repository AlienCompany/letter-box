#include <Arduino.h>
#include "Util.h"
#include "Box.h"

Box *box;


void setup() {
    Serial.begin(9600);
    Sensor *slotSensor = new Sensor(2);
    Sensor *doorSensor = new Sensor(4);

    box = new Box(slotSensor, doorSensor);

    pinMode(2,INPUT);
    pinMode(4,INPUT);

}

void loop() {

    box->loop();

}
