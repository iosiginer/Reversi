//
// Created by iosi on 10/11/17.
//

#ifndef REVERSI_BOARDPRINTER_H
#define REVERSI_BOARDPRINTER_H


#include "Cell.h"

/**
 * Virtual class in charge of dealing with showing the Board on the desired interface.
 */
class BoardPrinter {
public:
    /**
     * Print the board to the interface.
     * @param board - the Board to print.
     * @param size - the size of the Board.
     * @param message - an optional message to print for the user.
     */
    virtual void print(Cell ***board, int size) const = 0;

    /**
     * Destructor.
     */
    virtual ~BoardPrinter() {}
};

#endif //REVERSI_BOARDPRINTER_H
