/**
 * Created by Josef Ginerman on 05/12/17.
 * ID : 332494830
 **/

#ifndef REVERSI_TURNMANAGER_H
#define REVERSI_TURNMANAGER_H


#include "Player.h"

class TurnManager {
private:
    Player *players[2];
    bool noMoves[2];
    int turns;

public:
    TurnManager(Player *, Player *);

    void noMove();

    void yesMove();

    bool noMoreMoves() const;

    Player *nextPlayer();
};


#endif //REVERSI_TURNMANAGER_H
