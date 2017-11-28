#ifndef REVERSI_BOARDCONSOLEPRINTER_H
#define REVERSI_BOARDCONSOLEPRINTER_H


#include "Printer.h"

class ConsolePrinter : public Printer {
public:
    ConsolePrinter() {};

    /**
     * Print the board to the console.
     * @param board - the Board to print.
     * @param size - the size of the Board.
     * @param message - an optional message to print for the user.
     */
    virtual void printBoard(Cell ***board, int size, int points) const;

    ~ConsolePrinter() {}

    /**
     * Print the stream to the console
     * @param string - the stream to print
     */
    virtual void printStream(string) const;
};

#endif //REVERSI_BOARDCONSOLEPRINTER_H
