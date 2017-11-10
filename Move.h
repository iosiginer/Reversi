//
// Created by iosi on 11/6/17.
//

#ifndef REVERSI_MOVE_H
#define REVERSI_MOVE_H


#include "Coordinate.h"
#include "Cell.h"
#include "Player.h"

class Move {
private:
    Coordinate *position;
    Player *player;
    vector<Coordinate*> directions;
public:
    Move(Coordinate*, vector<Coordinate*>);
    string getCoordinateAsString() const;
    Coordinate* getCoordinate() const;
    vector<Coordinate*> getDirections() const;
    char getContent() const;
    Player* getPlayer() const;
};


#endif //REVERSI_MOVE_H
