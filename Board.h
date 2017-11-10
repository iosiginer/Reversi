//
// Created by iosi on 11/3/17.
//

#ifndef REVERSI_BOARD_H
#define REVERSI_BOARD_H

#include "Move.h"
#include "BoardPrinter.h"

#include <iostream>

class Board {
private:
    int size;
    Cell ***matrix;
    int blackCells;
    int whiteCells;
    BoardPrinter *printer;

    void flipGains(Move *, Player *);

    void flipCell(Cell *);

public:
    Board(int size = 8);

    void print() const;

    Cell *getCell(int, int) const;

    Cell *getCell(Coordinate) const;

    void setNeighbours(Cell *);

    Cell *nextCell(Cell *, Coordinate) const;

    bool contains(Coordinate) const;

    int getSize() const;

    void applyMove(Move *, Player *);

    bool gameOver() const;
};


#endif //REVERSI_BOARD_H
