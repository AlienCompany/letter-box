//
// Created by ferna on 09/09/2018.
//

#include <stddef.h>
#include "CommunicationService.h"
#include <SPI.h>

CommunicationService* CommunicationService::communicationService = NULL;

CommunicationService::CommunicationService() {}

CommunicationService::~CommunicationService() {

}

CommunicationService *CommunicationService::getInstance() {
    if (communicationService == NULL) {

        communicationService = new CommunicationService(); //new blablabla creer un objet et devient un pointeur sur celui-ci

    }
    return communicationService;


}

void CommunicationService::init() {

    // start the Ethernet connection:
    Serial.println("Initialize Ethernet with DHCP:");
    if (Ethernet.begin(mac) == 0) {
        Serial.println("Failed to configure Ethernet using DHCP");
        // Check for Ethernet hardware present
        if (Ethernet.hardwareStatus() == EthernetNoHardware) {
            Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
            while (true) {
                delay(1); // do nothing, no point running without Ethernet hardware
            }
        }
        if (Ethernet.linkStatus() == LinkOFF) {
            Serial.println("Ethernet cable is not connected.");
        }
        // try to congifure using IP address instead of DHCP:
        Ethernet.begin(mac, ip, myDns);
    } else {
        Serial.print("  DHCP assigned IP ");
        Serial.println(Ethernet.localIP());
    }
}

const IPAddress &CommunicationService::getIp() const {
    return ip;
}

void CommunicationService::setIp(const IPAddress &ip) {
    CommunicationService::ip = ip;
}

const IPAddress &CommunicationService::getMyDns() const {
    return myDns;
}

void CommunicationService::setMyDns(const IPAddress &myDns) {
    CommunicationService::myDns = myDns;
}

void CommunicationService::setServer(IPAddress serverIp, uint16_t port) {
    serverType = 1;
    CommunicationService::serverIp = serverIp;
    serverPort = port;
}

void CommunicationService::setServer(char *serverName, uint16_t port) {
    serverType = 2;
    CommunicationService::serverName = serverName;
    serverPort = port;
}

bool CommunicationService::sendNotificationReceive(bool hasLetter, bool hasPacket, bool hasCallingCard) {
    EthernetClient* client = generateConnexion();
    if(client != NULL) {
        client->println("POST /sendNotif.php HTTP/1.1");
        client->println("Host: letterbox.notraly.fr");
        client->println("Content-Type: application/x-www-form-urlencoded");
        client->println("Content-length: 70");
        client->println("Connection: close");
        client->println();
        client->print("letter=");
        client->print(hasLetter ? "1" : "0");  // si hasLetter == 1 alors "1" sinon "0"
        client->print("&packet=");
        client->print(hasPacket ? "1" : "0");
        client->print("&callingCard=");
        client->print(hasCallingCard ? "1" : "0");
        client->print("&notif=receive");
        client->print("&password=iloveyouforever");
        client->println();
        client->println();

        return true;

    }else{
        Serial.println("sendNotificationReceive failed");

        return false;
    }

}

bool CommunicationService::sendNotificationCollect() {
    EthernetClient* client = generateConnexion();
    if(client != NULL) {
        client->println("POST /sendNotif.php HTTP/1.1");
        client->println("Host: letterbox.notraly.fr");
        client->println("Content-Type: application/x-www-form-urlencoded");
        client->println("Content-length: 38");
        client->println("Connection: close");
        client->println();
        client->print("password=iloveyouforever");
        client->print("&notif=collect");
        client->println();
        client->println();

        return true;
    }else{
        Serial.println("sendNotificationCollect failed");
        return false;
    }

}

EthernetClient *CommunicationService::generateConnexion() {
    EthernetClient *client = new EthernetClient();
    clients.pushBack(client);
    Serial.print("Connection (");
    Serial.print((uint16_t) client);
    Serial.println(")");
    int res;
    switch (serverType) {
        case 0:
            Serial.println("NO SERVER DEFINED");
            break;
        case 1:
            res = client->connect(serverIp, serverPort);
            Serial.print("Connection par Ip : ");
            Serial.print(serverIp);
            Serial.print(":");
            Serial.println(serverPort);
            break;
        case 2:
            res = client->connect(serverName, serverPort);
            Serial.print("Connection par nom de domaine : ");
            Serial.print(serverName);
            Serial.print(":");
            Serial.println(serverPort);
            break;
    }
    if(res){
        Serial.print("connected to ");
        Serial.println(client->remoteIP());
        Serial.print(clients.length());
        Serial.println(" clients");
        return client;
    }else {
        Serial.println("connection failed");
        clients.removeLast();
        delete client;
        return NULL;
    }

}

void CommunicationService::loop() {

    for(ChainElement<EthernetClient*>* clientElement = clients.getFirst(); clientElement != NULL;){
        EthernetClient* client = clientElement->getValue();
        int len= client->available();
        if(len){
            Serial.print("Connection (");
            Serial.print((uint16_t) client);
            Serial.println(") RESAVE:");
            Serial.println("---------- DATA : begin ---------");
            do{
                byte buffer[80];
                if (len > 80) len = 80;
                client->read(buffer, len);
                Serial.write(buffer, len);
                len = client->available();
            }while(len);
            Serial.println("");
            Serial.println("---------- DATA : end ---------");
        }
        if (!client->connected()) {
            Serial.print("Connection (");
            Serial.print((uint16_t) client);
            Serial.println(") CLOSED!");
            client->stop();
            ChainElement<EthernetClient*>* next = clientElement->getNext();
            clients.remove(clientElement);
            Serial.print(clients.length());
            Serial.println(" clients");
            clientElement = next;
        }else{
            clientElement = clientElement->getNext();
        }
    }
}
