/**
 * Created by Josef Ginerman on 07/12/17.
 * ID : 332494830
 **/

#include <cstdio>
#include "NetworkPlayer.h"


NetworkPlayer::~NetworkPlayer() {
    delete client;
}

NetworkPlayer::NetworkPlayer(Color content, Coordinate **lastMove, Board *board, GameLogic &logic, Printer *printer,
                             Client *client) :
        content(content), lastMove(lastMove), board(board), logic(logic), printer(printer), client(client) {}

Move *NetworkPlayer::move(vector<Move *> possibleMoves) {
    if (*lastMove) {
        string str = ( *lastMove )->toString();
        if (strcmp(str.c_str(), "0, 0") == 0) {
            char *noMove = const_cast<char *>("NoMove");
            client->sendMove(noMove);
        } else {
            char *copy = new char[MAX_MOVE];
            memset(copy,0,MAX_MOVE);
            strcpy(copy, str.c_str());
            client->sendMove(copy);
            delete[] copy;
            printer->printStream("Waiting for the other player's move...\n");
        }
    }
    if (possibleMoves.empty()) {
        noMove();
    }
    char *newMove = client->receiveMove();
    Move *move = parseIntoMove(newMove);
    if (move) {
        printer->printStream("Your opponent chose: " + move->getCoordinate()->toString() + "\n");
    }
    return move;
}

Move *NetworkPlayer::parseIntoMove(char *newMove) {
    if (strcmp(newMove, "NoMove") == 0) {
        return NULL;
    }
    NetworkPlayer *self = this;
    int row, col;
    Coordinate *position;
    // newMove is in the form "X, Y"
    // X is row and Y is col
    string newMoveStr(newMove, MAX_MOVE);
    string rowAsString = newMoveStr.substr(0, newMoveStr.find(", "));
    string colAsString = newMoveStr.substr(newMoveStr.find(", ") + 1, MAX_MOVE);
    stringstream convertRow(rowAsString);
    stringstream convertCol(colAsString);
    if (( convertRow >> row ) && ( convertCol >> col )) {
        position = new Coordinate(row, col);
    } else {
        throw "Couldn't receive move";
    }
    delete[] newMove;
    return logic.getMoveByPosition(position, self, board);
}

bool NetworkPlayer::isOpponent(Color color) const {
    return (( color != this->content ) && ( color != EMPTY ));
}

void NetworkPlayer::conquerCell(Cell *cell) {
    cell->sumOne(cell->getContent(), this->getContent());
    cell->setContent(this->content);
}

Color NetworkPlayer::getContent() const {
    return this->content;
}

void NetworkPlayer::noMove() const {
    printer->printStream("Your opponent can't play, so you go again!"
                                 " Waiting to the other player to be notified.\n");
}

void NetworkPlayer::lasMove() const {
    string str = ( *lastMove )->toString();
    char *copy = new char[MAX_MOVE];
    strcpy(copy, str.c_str());
    client->sendMove(copy);
    delete[] copy;
    client->sendMove("End");
}
