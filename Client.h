/**
 * Created by Josef Ginerman on 07/12/17.
 * ID : 332494830
 **/

#ifndef REVERSI_NETWORKCLIENT_H
#define REVERSI_NETWORKCLIENT_H

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <cstring>
#include <unistd.h>

class Client {
public:
    Client(const char *serverIP, int serverPort);

    void connectToServer();

    void sendMove(char* position);

    char* receiveMove();

    int receiveNumber();

private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};


#endif //REVERSI_NETWORKCLIENT_H
