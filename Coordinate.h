//
// Created by iosi on 11/3/17.
//

#ifndef REVERSI_COORDINATE_H
#define REVERSI_COORDINATE_H


#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Coordinate {
private:
    int row, col;

public:
    Coordinate(int, int);

    int getRow() const;

    int getCol() const;

    string toString() const;

    Coordinate sum(Coordinate) const;

    Coordinate* getDirectionTo(Coordinate*) const;
};


#endif //REVERSI_COORDINATE_H
