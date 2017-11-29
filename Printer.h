#ifndef REVERSI_BOARDPRINTER_H
#define REVERSI_BOARDPRINTER_H


#include "Cell.h"

/**
 * Virtual class in charge of dealing with showing the Board on the desired interface.
 */
class Printer {
public:
    /**
     * Print the board to the interface.
     * @param board - the Board to print.
     * @param size - the size of the Board.
     * @param message - an optional message to print for the user.
     */
    virtual void printBoard(Cell ***board, int size, string points) const = 0;

    /**
     * Print the stream to the interface
     * @param string - the stream to print
     */
    virtual void printStream(string) const = 0;
    /**
     * Destructor.
     */
    virtual ~Printer() {}
};

#endif //REVERSI_BOARDPRINTER_H
