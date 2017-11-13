//
// Created by iosi on 11/5/17.
//

#ifndef REVERSI_GAMEFLOW_H
#define REVERSI_GAMEFLOW_H

#include "Board.h"
#include "GameLogic.h"
#include "ClassicLogic.h"
#include "HumanConsolePlayer.h"


class GameFlow {
private:
    Board *board;
    GameLogic *logic;
    Player *player1;
    Player *player2;
    bool player1Turn;

    void playOneTurn();

    void gameOver() const;

    bool noMove;
    bool noMoreMoves;

public:
    GameFlow(char, char, int = 8);

    void run();

    ~GameFlow();
};


#endif //REVERSI_GAMEFLOW_H
