//
// Created by ferna on 09/09/2018.
//

#ifndef LETTER_BOX_COMMUNICATIONSERVICE_H
#define LETTER_BOX_COMMUNICATIONSERVICE_H

#include <stddef.h>
#include <IPAddress.h>
#include "Chain.h"
#include <Ethernet.h>

class CommunicationService {
private:
    CommunicationService();

    virtual ~CommunicationService();

    static CommunicationService *communicationService;

    IPAddress ip = IPAddress(192, 168, 0, 177);

    IPAddress serverIp;
    char * serverName;
    uint8_t serverType; // 0: no server set, 1: serverIp, 2 serverName

    IPAddress myDns = IPAddress(192, 168, 0, 1);

    Chain<EthernetClient *> clients = Chain<EthernetClient *>();

    byte mac[6] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

    uint16_t serverPort;

public:
    const IPAddress &getIp() const;

    void setIp(const IPAddress &ip);

    const IPAddress &getMyDns() const;

    void setMyDns(const IPAddress &myDns);

    void setServer(IPAddress serverIp, uint16_t port = 80);

    void setServer(char * serverName, uint16_t port = 80);

    static CommunicationService *getInstance();

    void init();

    void sendNotification(bool hasLetter, bool hasPacket, bool hasCallingCard);

    EthernetClient* generateConnexion();
};


#endif //LETTER_BOX_COMMUNICATIONSERVICE_H



