//
// Created by iosi on 11/6/17.
//

#ifndef REVERSI_MOVE_H
#define REVERSI_MOVE_H


#include "Cell.h"
//#include "Player.h"

class Move {
private:
    Coordinate *position;
    vector<Coordinate*> directions;
    int gain;

public:
    Move(Coordinate*, vector<Coordinate*>);
    string getCoordinateAsString() const;
    Coordinate* getCoordinate() const;
    vector<Coordinate*> getDirections() const;

    int getGain() const;

    void setGain(int);
};


#endif //REVERSI_MOVE_H
