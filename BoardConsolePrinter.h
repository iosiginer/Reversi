//
// Created by iosi on 10/11/17.
//

#ifndef REVERSI_BOARDCONSOLEPRINTER_H
#define REVERSI_BOARDCONSOLEPRINTER_H


#include "BoardPrinter.h"

class BoardConsolePrinter : public BoardPrinter {
public:
    BoardConsolePrinter();
    virtual void print(Cell ***board, int size) const;

};


#endif //REVERSI_BOARDCONSOLEPRINTER_H
