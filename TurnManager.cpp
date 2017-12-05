/**
 * Created by Josef Ginerman on 05/12/17.
 * ID : 332494830
 **/

#include "TurnManager.h"


TurnManager::TurnManager(Player *p1, Player *p2) {
    players[0] = p1;
    players[1] = p2;
    noMoves[0] = noMoves[1] = false;
}

Player *TurnManager::nextPlayer() {
    return players[++turns % 2];
}


void TurnManager::noMove() {
    noMoves[turns % 2] = true;
}

void TurnManager::yesMove() {
    noMoves[turns % 2] = false;
}

bool TurnManager::noMoreMoves() const {
    return (noMoves[0] && noMoves[1]);
}





