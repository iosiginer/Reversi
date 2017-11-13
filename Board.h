//
// Created by iosi on 11/3/17.
//

#ifndef REVERSI_BOARD_H
#define REVERSI_BOARD_H

#include "Move.h"
#include "BoardPrinter.h"
#include "Player.h"
#include "CellCounter.h"

#include <iostream>

class Board {
private:
    int size;
    Cell ***matrix;
    CellCounter *counter;
    BoardPrinter *printer;

    void flipGains(Coordinate *, Player *, Coordinate *);


public:
    Board(char play1 = 'X', char play2 = 'O', int size = 8);

    void print() const;

    Cell *getCell(int, int) const;

    Cell *getCell(Coordinate) const;

    void setNeighbours(Cell *);

    Cell *nextCell(Cell *, Coordinate) const;

    bool contains(Coordinate) const;

    int getSize() const;

    void applyMove(Move *, Player *);

    bool gameOver() const;

    int getWinner() const;

    int getPlayer1Points() const;

    int getPlayer2Points() const;

    string getPoints() const;

    ~Board();
};


#endif //REVERSI_BOARD_H
