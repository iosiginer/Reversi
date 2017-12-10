#ifndef REVERSI_FILEREADER_H
#define REVERSI_FILEREADER_H

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

class FileReader {
public:

    /**
     * Constructor
     */
    FileReader(string s);

    /**
     * The method read the IP from the file
     */
    const char* readIP();

    /**
     * The method read the port from the file
     */
    int readPort();

private:
    ifstream inFile;
};


#endif //REVERSI_FILEREADER_H