#include <csignal>
#include "Client.h"
#include <signal.h>

using namespace std;



Client::Client(Printer *printer) : clientSocket(0), printer(printer) {
    FileReader f("ServerDetails.txt");
    serverIP = f.readIP();
    serverPort = f.readPort();
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

bool Client::send(string message) {
    char buffer;
    int i = 0, n;
    try {
        while (i < message.length()) {
            buffer = message.at(i);
            try {
                n = (int) write(clientSocket, &buffer, sizeof(buffer));
            } catch (...) {
                return false;
            }

            if (ERROR == n) {
                printer->printStream("Failed sending message.\n");
                return false;
            }
            if (DISCONNECT == n) {
                printer->printStream("The server has fallen.\n");
                return false;
            }
            i++;
        }
        buffer = '\0';
        n = (int) write(clientSocket, &buffer, sizeof(buffer));
        if (ERROR == n) throw "Error sending message";
        return true;
    } catch (...) {
        return false;
    }

}

string Client::receive() {
    string message = "";
    char buffer = '\0';
    int i = 0, n;
    try {
        while (true) {
            n = read(clientSocket, &buffer, sizeof(char));
            if (ERROR == n) throw "Error sending message";
            if (buffer == '\0') break;
            message += buffer;
            i++;
        }
        return message;
    } catch (...) {
        throw "Error sending message";
    }
}


Client::~Client() {
    close(clientSocket);
    delete[]( serverIP );
}