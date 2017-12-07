/**
 * Created by Josef Ginerman on 07/12/17.
 * ID : 332494830
 **/

#include "NetworkPlayer.h"


NetworkPlayer::~NetworkPlayer() {
    delete client;
}

NetworkPlayer::NetworkPlayer(Color content, Move **lastMove, Board *board, GameLogic &logic, Printer *printer,
                             Client *client) :
        content(content), lastMove(lastMove), board(board), logic(logic), printer(printer), client(client) {}

Move *NetworkPlayer::move(vector<Move *> possibleMoves) {
    if (*lastMove) {
        string str = (*lastMove)->getCoordinate()->toString();
        char* copy = new char[str.size() + 1];
        strcpy(copy, str.c_str());
        client->sendMove(copy);
        delete[] copy;
    }
    char* newMove = client->receiveMove();
    Move *move = parseIntoMove(newMove);
    return move;
}

Move *NetworkPlayer::parseIntoMove(char* newMove) {
    NetworkPlayer *self = this;
    int row, col;
    Coordinate *position;
    // newMove is in the form "X, Y"
    // X is row and Y is col
    string newMoveStr(newMove, 9);
    string rowAsString = newMoveStr.substr(0, newMoveStr.find(", "));
    string colAsString = newMoveStr.substr(newMoveStr.find(", ") + 1, newMoveStr.size());
    stringstream convertRow(rowAsString);
    stringstream convertCol(colAsString);
    if ((convertRow >> row) && (convertCol >> col)) {
        position = new Coordinate(row, col);
    } else {
        throw "Couldn't receive move";
    }
    delete[] newMove;
    return logic.getMoveByPosition(position, self, board);
}

bool NetworkPlayer::isOpponent(Color color) const {
    return ((color != this->content) && (color != EMPTY));
}

void NetworkPlayer::conquerCell(Cell *cell) {
    cell->sumOne(cell->getContent(), this->getContent());
    cell->setContent(this->content);
}

Color NetworkPlayer::getContent() const {
    return this->content;
}



