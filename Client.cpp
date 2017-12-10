#include "Client.h"
#include <stdexcept>
using namespace std;

Client::Client(Printer *printer) : clientSocket(0), printer(printer) {
    FileReader f("ServerDetails.txt");
    serverIP = f.readIP();
    serverPort = f.readPort();
    printer->printStream("Client\n");
}

void Client::connectToServer() {
    // Create a socket point
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == ERROR) {
        __throw_runtime_error("Error opening socket");
    }
    // Convert the ip string to a network address
    struct in_addr address;
    if (!inet_aton(serverIP, &address)) {
        __throw_runtime_error("Can't parse IP address");
    }
    // Get a hostent structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void *) &address, sizeof
            address, AF_INET);
    if (server == NULL) {
        __throw_runtime_error("Host is unreachable");
    }
    // Create a structure for the server address
    struct sockaddr_in serverAddress;
    bzero((char *) &address, sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char *) &serverAddress.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
    // htons converts values between host and network byteorders
    serverAddress.sin_port = htons(serverPort);
    // Establish a connection with the TCP server
    if (connect(clientSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == ERROR) {
        __throw_runtime_error("Error connecting to server");
    }
    printer->printStream("Connected to server\n");
}

void Client::sendMove(char* position) {
    // Write the exercise arguments to the socket
    ssize_t n = write(clientSocket, position, MAX_MOVE);
    if (n == ERROR) {
        throw "Error writing Move to socket";
    }
}

char* Client::receiveMove() {
    char *newMove = new char[MAX_MOVE];
    int n = read(clientSocket, newMove, MAX_MOVE);
    if (n == ERROR) {
        throw "Error reading Move from socket";
    }
    return newMove;
}

int Client::receiveNumber() {
    int turn;
    ssize_t n = read(clientSocket, &turn, sizeof(turn));
    if (n == ERROR) {
        throw "Error reading Move from socket";
    }
    if (turn == 1) {
        ConsolePrinter printer;
        printer.printStream("Waiting for the other player to join...\n");
        ssize_t n = read(clientSocket, &turn, sizeof(turn));
        if (n == ERROR) {
            throw "Error reading Move from socket";
        }
    }
    return turn;
}

Client::~Client() {
    close(clientSocket);
    delete[](serverIP);
}
