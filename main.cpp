#include <Arduino.h>
#include "Util.h"
#include "Box.h"


Box *box;

const uint8_t PIN_SLOT_SENSOR = 2;
const uint8_t PIN_DOOR_SENSOR = 4;
const uint8_t PIN_LETTER_LED = 3;
const uint8_t PIN_COLLECT = 7;
const uint8_t PIN_PACKET_LED = 8;

void setup() {
    Serial.begin(9600);

    Sensor *slotSensor = new Sensor(PIN_SLOT_SENSOR, 200);
    Sensor *doorSensor = new Sensor(PIN_DOOR_SENSOR, 200);
    Led *letterLed = new Led(PIN_LETTER_LED, 0);
    Sensor *collectSensor = new Sensor(PIN_COLLECT);
    Led *packetLed = new Led(PIN_PACKET_LED, 0);

    box = new Box(slotSensor, doorSensor, letterLed, collectSensor, packetLed);

    pinMode(PIN_SLOT_SENSOR, INPUT);
    pinMode(PIN_DOOR_SENSOR, INPUT);
    pinMode(PIN_LETTER_LED, OUTPUT);
    pinMode(PIN_COLLECT, INPUT_PULLUP);
    pinMode(PIN_PACKET_LED, OUTPUT);

    letterLed->init();
    packetLed->init();

}

void loop() {

    box->loop();

}
