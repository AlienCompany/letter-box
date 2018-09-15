#include <Arduino.h>
#include "Util.h"
#include "Box.h"
#include "CommunicationService.h"


Box *box;

const uint8_t PIN_SLOT_SENSOR = 2;
const uint8_t PIN_DOOR_SENSOR = 4;
const uint8_t PIN_LETTER_LED = 3;
const uint8_t PIN_COLLECT = 7;
const uint8_t PIN_PACKET_LED = 6;
const uint8_t PIN_CALLING_CARD = 8;
const uint8_t PIN_CALLING_CARD_LED = 5;

//char* SERVER = "letterbox.notraly.fr";
IPAddress SERVER(192,168,1,20);



void setup() {
    Serial.begin(9600);

    Sensor *slotSensor = new Sensor(PIN_SLOT_SENSOR, 200);
    Sensor *doorSensor = new Sensor(PIN_DOOR_SENSOR, 200);
    Led *letterLed = new Led(PIN_LETTER_LED, 0);
    Sensor *collectSensor = new Sensor(PIN_COLLECT);
    Led *packetLed = new Led(PIN_PACKET_LED, 0);

    Sensor *callingCardSensor = new Sensor(PIN_CALLING_CARD);
    Led *callingCardLed = new Led(PIN_CALLING_CARD_LED, 0);

    CommunicationService *communicationService = CommunicationService::getInstance();

    box = new Box(slotSensor, doorSensor, letterLed, collectSensor, packetLed, callingCardSensor, callingCardLed);

    pinMode(PIN_SLOT_SENSOR, INPUT);
    pinMode(PIN_DOOR_SENSOR, INPUT);
    pinMode(PIN_LETTER_LED, OUTPUT);
    pinMode(PIN_COLLECT, INPUT_PULLUP);
    pinMode(PIN_PACKET_LED, OUTPUT);
    pinMode(PIN_CALLING_CARD, INPUT_PULLUP);
    pinMode(PIN_CALLING_CARD_LED, OUTPUT);

    letterLed->init();
    packetLed->init();
    communicationService->init();
    communicationService->setServer(SERVER);
    delay(1);
}

void loop() {

    box->loop();

}
