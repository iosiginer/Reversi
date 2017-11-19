//
// Created by iosi on 19/11/17.
//

#ifndef REVERSI_AIPLAYER_H
#define REVERSI_AIPLAYER_H


#include "Player.h"

class AIPlayer : public Player {
public:
    virtual Move *move(vector<Move *> possibleMoves);

    virtual bool isOpponent(char) const;


private:
};


#endif //REVERSI_AIPLAYER_H
