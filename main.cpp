#include <Arduino.h>
#include "Util.h"
#include "Box.h"


Box *box;


void setup() {
    Serial.begin(9600);

    Sensor *slotSensor = new Sensor(2, 200);
    Sensor *doorSensor = new Sensor(4, 200);
    Led *letterLed = new Led(3, 0);

    box = new Box(slotSensor, doorSensor, letterLed);

    pinMode(2, INPUT);
    pinMode(4, INPUT);
    pinMode(3, OUTPUT);

    letterLed->init();

}

void loop() {

    box->loop();

}
