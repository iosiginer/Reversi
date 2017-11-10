//
// Created by iosi on 11/5/17.
//

#include "GameFlow.h"


GameFlow::GameFlow(char first, char second, int size) {
    this->board = new Board(size);
    this->player1 = new Player(first);
    this->player2 = new Player(second);
    this->player1Turn = true;
    this->logic = new ClassicLogic(board);
}

void GameFlow::playOneTurn() {
    board->print();
    if (player1Turn) {
        showPossibleMoves(player1);
        this->player1Turn = false;
    } else {
        showPossibleMoves(player2);
        this->player1Turn = true;
    }

}

void GameFlow::showPossibleMoves(Player *player) const {
    vector<Move *> moves = logic->getPossibleMoves(player);
    for (int i = 0; i < moves.size(); i++) {
        Move move = *moves[i];
        cout << move.getCoordinateAsString() << " ";
    }
}


