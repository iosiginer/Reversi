//
// Created by iosi on 10/11/17.
//

#ifndef REVERSI_BOARDPRINTER_H
#define REVERSI_BOARDPRINTER_H


#include "Cell.h"

class BoardPrinter {
public:
    virtual void print(Cell ***board, int size) const = 0;
};
#endif //REVERSI_BOARDPRINTER_H
