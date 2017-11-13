//
// Created by iosi on 11/5/17.
//

#ifndef REVERSI_PLAYER_H
#define REVERSI_PLAYER_H

#include <vector>
#include "Move.h"


class Player {
public:
    virtual Move *move(vector<Move *> possibleMoves) = 0;

    virtual bool isOpponent(char) const = 0;

    virtual void conquerCell(Cell *) = 0;


private:
    virtual void showPossibleMoves(vector<Move *>) const = 0;

};


#endif //REVERSI_PLAYER_H
