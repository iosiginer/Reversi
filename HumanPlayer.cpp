//
// Created by iosi on 10/11/17.
//

#include <limits>
#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(char content) : content(content) {}


Move *HumanPlayer::move(vector<Move *> possibleMoves) {
    int row, col;
    char comma;
    int &rowRef = row, colRef = col;
    bool validMove = false;
    Move *move = NULL;
    do {
        showPossibleMoves(possibleMoves);
        cout << "Please enter your move row,col: ";
        cin >> row >> comma >> col;
        checkInput(rowRef, colRef);
        for (int i = 0; i < possibleMoves.size(); i++) {
            Move *moveToCheck = possibleMoves[i];
            Coordinate *checkPos = moveToCheck->getCoordinate();
            if (checkPos->getRow() == row && checkPos->getCol() == col) {
                move = moveToCheck;
                validMove = true;
                break;
            }
        }
        if (!validMove) {
            cout << "Wrong move, please try again." << endl;
        }
    } while (!validMove);
    cout << "You picked " << move->getCoordinateAsString() << endl;
    return move;
}


bool HumanPlayer::isOpponent(char adv) const {
    return (content != adv && adv != ' ' && adv != '*');
}


void HumanPlayer::showPossibleMoves(vector<Move *> moves) const {
    cout << "You play with: " << this->content << endl;
    cout << "You possible moves are: ";
    for (int i = 0; i < moves.size(); i++) {
        cout << " " << moves[i]->getCoordinateAsString() << " ";
    }
    cout << endl << endl;
}

char HumanPlayer::getContent() const {
    return this->content;
}

void HumanPlayer::conquerCell(Cell *cell) {
    cell->sumOne(cell->getContent(), this->getContent());
    cell->setContent(this->content);
}

void HumanPlayer::checkInput(int &row, int &col) const {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        row = 0;
        col = 0;
    }
}