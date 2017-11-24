//
// Created by iosi on 19/11/17.
//

#include "AIPlayer.h"
#include "HumanPlayer.h"


AIPlayer::AIPlayer(char content, char oppContent, Board *board, GameLogic &logic) : content(content),
                                                                                   oppContent(oppContent),
                                                                                   logic(logic),
                                                                                   cleanBoard(board){
}

bool AIPlayer::isOpponent(char adv) const {
    return (content != adv && adv != ' ' && adv != '*');
}

void AIPlayer::conquerCell(Cell *cell) {
    cell->sumOne(cell->getContent(), this->getContent());
    cell->setContent(this->content);
}


char AIPlayer::getContent() const {
    return this->content;
}

Move *AIPlayer::move(vector<Move *> possibleMoves) {
    int opponentPoints = 0, maxOpponentPoints = 0, currentMaxOpPoints;
    Player *dummyPlayer = new HumanPlayer(oppContent);
    Move *chosenMove = possibleMoves[0];
    vector<Move *> opponentMoves;
    Board *testBoard;
    // loop through all the AIPlayer moves
    for (int i = 0; i < possibleMoves.size(); i++) {
        testBoard = cleanBoard->clone();            // get a clean board for testing
        testBoard->applyMove(possibleMoves[i], this);   // apply the current move
        opponentMoves = this->logic.getPossibleMoves(dummyPlayer);
        for (int j = 0; j < opponentMoves.size(); j++) {    // loop through the opp moves
            testBoard->applyMove(opponentMoves[j], dummyPlayer);
            currentMaxOpPoints = testBoard->getPoints();
            if (currentMaxOpPoints > maxOpponentPoints) {
                maxOpponentPoints = currentMaxOpPoints;
            }
        }
        if (i == 0) { opponentPoints = maxOpponentPoints; }
        if (maxOpponentPoints <= opponentPoints) {
            chosenMove = possibleMoves[i];
        }
    }
    return chosenMove;
}

