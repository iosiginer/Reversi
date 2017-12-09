/**
 * Created by Josef Ginerman on 07/12/17.
 **/

#include "Client.h"
#include "ConsolePrinter.h"

using namespace std;

Client::Client(const char *serverIP, int serverPort) :
        serverIP(serverIP), serverPort(serverPort),
        clientSocket(0) {
    cout << "Client" << endl;
}

void Client::connectToServer() {
    // Create a socket point
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw "Error opening socket";
    }
    // Convert the ip string to a network address
    struct in_addr address;
    if (!inet_aton(serverIP, &address)) {
        throw "Can't parse IP address";
    }
    // Get a hostent structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void *) &address, sizeof
            address, AF_INET);
    if (server == NULL) {
        throw "Host is unreachable";
    }
    // Create a structure for the server address
    struct sockaddr_in serverAddress;
    bzero((char *) &address, sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char *) &serverAddress.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
    // htons converts values between host and network byteorders
    serverAddress.sin_port = htons(serverPort);
    // Establish a connection with the TCP server
    if (connect(clientSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    }
    cout << "Connected to server" << endl;
}

void Client::sendMove(char* position) {
    // Write the exercise arguments to the socket
    ssize_t n = write(clientSocket, position, sizeof(position));
    if (n == -1) {
        throw "Error writing Move to socket";
    }
}

char* Client::receiveMove() {
    char *newMove = new char[9];
    int n = read(clientSocket, newMove, sizeof(char) * 9);
    if (n == -1) {
        throw "Error reading Move from socket";
    }
    return newMove;
}

int Client::receiveNumber() {
    int turn;
    ssize_t n = read(clientSocket, &turn, sizeof(turn));
    if (n == -1) {
        throw "Error reading Move from socket";
    }
    if (turn == 1) {
        ConsolePrinter printer;
        printer.printStream("Waiting for the other player to join...\n");
        ssize_t n = read(clientSocket, &turn, sizeof(turn));
        if (n == -1) {
            throw "Error reading Move from socket";
        }
    }
    return turn;
}


