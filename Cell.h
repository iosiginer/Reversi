//
// Created by iosi on 11/3/17.
//

#ifndef REVERSI_CELL_H
#define REVERSI_CELL_H


#include <vector>
#include "Coordinate.h"
#include "CellCounter.h"

/**
 * Class containing the definition of a Ce
 */
class Cell {
private:
    Coordinate *position;
    CellCounter *counter;
    char content;
    vector<Cell *> neighbours;
    int numOfNeighbours;

public:
    Cell(Coordinate *, CellCounter *, char = ' ');

    char getContent() const;

    void setContent(char);

    vector<Cell *> getNeighbours() const;

    void setNeighbours(vector<Cell *>);

    Coordinate *getPosition() const;

    string getPostionAsString() const;

    string toString() const;

    bool isEmpty() const;

    void setNumOfNeighbours(int);

    int getNumOfNeighbours();

    vector<Coordinate *> getNeighboursByDirection();

    void sumOne(char previous, char current);

    ~Cell();

};


#endif //REVERSI_CELL_H
