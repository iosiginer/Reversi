#include "FileReader.h"

FileReader::FileReader(string s) {
    inFile.open(s.c_str(), ios::in);
}

const char* FileReader::readIP() {
    string ipStr;
    inFile >> ipStr;
    char *ip = new char[ipStr.length() + 1];
    strcpy(ip, ipStr.c_str());
    return ip;
}

int FileReader::readPort() {
    string readingPort;
    int port;
    inFile >> readingPort;
    port = atoi(readingPort.c_str());
    inFile.close();
    return port;
}