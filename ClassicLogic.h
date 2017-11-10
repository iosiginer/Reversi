//
// Created by iosi on 08/11/17.
//

#ifndef REVERSI_CLASSICLOGIC_H
#define REVERSI_CLASSICLOGIC_H


#include "GameLogic.h"

class ClassicLogic : public GameLogic {
private:
    Board *board;
    virtual vector<Coordinate*> getDirections(Coordinate*, Player*) const;
    bool validDirection(Coordinate*, Player*, Coordinate*) const;
public:
    ClassicLogic(Board*);
    virtual vector<Move*> getPossibleMoves(Player*) const;
};


#endif //REVERSI_CLASSICLOGIC_H
