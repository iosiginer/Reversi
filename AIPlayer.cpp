//
// Created by iosi on 19/11/17.
//

#include <map>
#include <cstdlib>
#include "AIPlayer.h"
#include "HumanPlayer.h"


AIPlayer::AIPlayer(char content, char oppContent, Board *board, GameLogic &logic) : content(content),
                                                                                    oppContent(oppContent),
                                                                                    logic(logic),
                                                                                    cleanBoard(board) {
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
    map<Move *, int> movesMap; // map to store each move with its correspondent max opponent gain
    Player *dummyPlayer = new HumanPlayer(oppContent);
    vector<Move *> opponentMoves;
    Board *testBoard;
    // Loop through each possible move the AIPlayer has, and for each find the maximum score the opposing
    // player can achieve
    for (int i = 0; i < possibleMoves.size(); i++) {
        testBoard = cleanBoard->clone();            // get a clean board for testing
        testBoard->applyMove(possibleMoves[i], this);   // apply the current move
        opponentMoves = this->logic.getPossibleMoves(dummyPlayer, testBoard);
        // if the opponents doesn't have moving options, this is the best move
        if (opponentMoves.empty()) { return possibleMoves[i]; }

        int score = testBoard->getPoints();
        int currentScore, maxScore = score;
        for (int j = 0; j < opponentMoves.size(); j++) {
            currentScore = score + opponentMoves[j]->getGain() * 2 + 1;
            if (currentScore > maxScore) {
                maxScore = currentScore;
            }
        }
        movesMap.insert(map<Move *, int>::value_type(possibleMoves[i], maxScore));
        delete testBoard;
    }

    map<Move *, int>::iterator it;
    Move *chosenMove = movesMap.begin()->first;
    int minGain = movesMap.begin()->second;
    for (it = movesMap.begin(); it != movesMap.end(); it++) {
        if (it->second < minGain) {
            chosenMove = it->first;
            minGain = it->second;
        }
        if (it->second == minGain) {
            int randomChoice = rand() % 10;
            cout << randomChoice << endl;
            if (randomChoice < 8) { chosenMove = it->first; }
        }
    }
    cout << "The computer played " << chosenMove->getCoordinateAsString() << endl;
    delete dummyPlayer;
    return chosenMove;
}
