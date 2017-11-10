//
// Created by iosi on 11/3/17.
//

#ifndef REVERSI_CELL_H
#define REVERSI_CELL_H


#include <vector>
#include "Coordinate.h"

class Cell {
private:
    Coordinate *position;
    char content;
    vector<Cell*> neighbours;
    int numOfNeighbours;

public:
    Cell(Coordinate*, char = ' ');

    ~Cell();

    char getContent() const;

    void setContent(char);

    vector<Cell*> getNeighbours() const;

    void setNeighbours(vector<Cell*>);

    Coordinate* getPosition() const;

    string getPostionAsString() const;

    string toString() const;

    bool isBlack() const;

    bool isWhite() const;

    bool isEmpty() const;

    void setNumOfNeighbours(int);

    int getNumOfNeighbours();

    vector<Coordinate*> getNeighboursByDirection();
};


#endif //REVERSI_CELL_H
