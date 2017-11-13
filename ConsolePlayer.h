//
// Created by iosi on 10/11/17.
//

#ifndef REVERSI_CONSOLEPLAYER_H
#define REVERSI_CONSOLEPLAYER_H


#include "Player.h"

class ConsolePlayer : public Player {
private:
    virtual void showPossibleMoves(vector<Move *>) const = 0;


public:
    virtual Move *move(vector<Move *> possibleMoves) = 0;

    virtual bool isOpponent(char) const = 0;

    virtual void conquerCell(Cell *) = 0;
};


#endif //REVERSI_CONSOLEPLAYER_H
