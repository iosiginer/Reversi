#ifndef REVERSI_BOARDCONSOLEPRINTER_H
#define REVERSI_BOARDCONSOLEPRINTER_H


#include "BoardPrinter.h"

class BoardConsolePrinter : public BoardPrinter {
public:
    BoardConsolePrinter() {};

    virtual void print(Cell ***board, int size, int points) const;

    ~BoardConsolePrinter() {}

};


#endif //REVERSI_BOARDCONSOLEPRINTER_H
