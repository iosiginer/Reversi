#include <limits>
#include <cstdio>
#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(Color content, Printer *printer) : content(content), printer(printer) {}


Move *HumanPlayer::move(vector<Move *> possibleMoves) {
    if (possibleMoves.empty()) {
        return NULL;
    }
    int row, col;
    char comma;
    int &rowRef = row, colRef = col;
    bool validMove = false;
    Move *move = NULL;
    do {
        showPossibleMoves(possibleMoves);
        printer->printStream("Please enter your move row,col: ");
        cin >> row >> comma >> col;
        checkInput(rowRef, colRef);
        for (int i = 0; i < possibleMoves.size(); i++) {
            Move *currentMove = possibleMoves[i];
            Coordinate *checkPos = currentMove->getCoordinate();
            if (checkPos->getRow() == row && checkPos->getCol() == col) {
                move = currentMove;
                validMove = true;
                break;
            }
        }
        if (!validMove) {
            printer->printStream("Wrong move, please try again.\n");
        }
    } while (!validMove);
    printer->printStream("You picked " + move->getCoordinateAsString() + "\n");
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return move;
}


void HumanPlayer::noMove() const {
    printer->printStream("No possible moves. Play passes back to the other player."
                                 " Press any key to continue.\n");
    char c = static_cast<char>(getchar());
}


bool HumanPlayer::isOpponent(Color adv) const {
    return (content != adv && adv != EMPTY);
}


void HumanPlayer::showPossibleMoves(vector<Move *> moves) const {
    string cont;
    if (this->content == BLACK) {
        cont = "blacks";
    } else if (this->content == WHITE) {
        cont = "whites";
    }
    printer->printStream("You play with: " + cont + "\n" + "You possible moves are: ");
    for (int i = 0; i < moves.size(); i++) {
        printer->printStream(" (" + moves[i]->getCoordinateAsString() + ") ");
    }
    printer->printStream("\n\n");
}

Color HumanPlayer::getContent() const {
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
