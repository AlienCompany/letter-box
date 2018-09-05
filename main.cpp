#include <Arduino.h>
#include "Util.h"
#include "Box.h"


Box *box;

const PIN_SLOT_SENSOR = 2;
const PIN_DOOR_SENSOR = 4;
const PIN_LETTER_LED = 3;
const PIN_COLLECT = 7;

void setup() {
    Serial.begin(9600);

    Sensor *slotSensor = new Sensor(PIN_SLOT_SENSOR, 200);
    Sensor *doorSensor = new Sensor(PIN_DOOR_SENSOR, 200);
    Led *letterLed = new Led(PIN_LETTER_LED, 0);
    Sensor *collectSensor = new Sensor(PIN_COLLECT);

    box = new Box(slotSensor, doorSensor, letterLed, collectSensor);

    pinMode(PIN_SLOT_SENSOR, INPUT);
    pinMode(PIN_DOOR_SENSOR, INPUT);
    pinMode(PIN_LETTER_LED, OUTPUT);
    pinMode(PIN_COLLECT, INPUT_PULLUP);

    letterLed->init();

}

void loop() {

    box->loop();

}
