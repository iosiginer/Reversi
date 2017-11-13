//
// Created by iosi on 11/5/17.
//

#ifndef REVERSI_GAMELOGIC_H
#define REVERSI_GAMELOGIC_H


#include "Board.h"
#include "Move.h"

class GameLogic {
private:
    virtual vector<Coordinate *> getDirections(Coordinate *, Player *, int *) const = 0;

public:
    virtual vector<Move*> getPossibleMoves(Player*) const = 0;
};

#endif //REVERSI_GAMELOGIC_H
