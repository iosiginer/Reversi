#include <string>
#include <iostream>
#include "GameFlow.h"
#include "Menu.h"

using namespace std;

int main(int argc, char *argv[]) {
    char p1 = 'X';
    char p2 = 'O';
    int size = 8;
    if (argc > 1) {
        p1 = *argv[1];
        p2 = *argv[2];
        istringstream(argv[3]) >> size;
    }
    Printer *printer = new ConsolePrinter();
    GameFlow reversi(p1, p2, size, printer);
    reversi.run();
}
