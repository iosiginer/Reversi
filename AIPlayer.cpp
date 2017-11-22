//
// Created by iosi on 19/11/17.
//

#include "AIPlayer.h"


AIPlayer::AIPlayer(char content, char oppContent, Board board, GameLogic &logic) : content(content),
                                                                                   oppContent(oppContent),
                                                                                   logic(logic) {
    this->cleanBoard = this->testBoard = board.clone();

}



bool AIPlayer::isOpponent(char) const {
    return false;
}

Move *AIPlayer::move(vector<Move *> possibleMoves) {
    return NULL;
}

void AIPlayer::conquerCell(Cell *) {

}
