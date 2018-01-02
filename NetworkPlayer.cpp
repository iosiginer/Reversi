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
            string noMove = "play noMove";
            client->send(noMove);
        } else {
            string play = "play ";
            play.append(str);
            client->send(play);
            printer->printStream("Waiting for the other player's move...\n");
        }
    }
    if (possibleMoves.empty()) {
        string str = ( *lastMove )->toString();
        noMove();
        if (strcmp(str.c_str(), "0, 0") == 0) {
            return NULL;
        }
    }
    string newMove = client->receive();
    Move *move = parseIntoMove(newMove);
    if (move) {
        if(*(move->getCoordinate()) == Coordinate(-1,-1)) {
            printer->printStream("The other player has disconnected");
        } else {
            printer->printStream("Your opponent chose: " + move->getCoordinate()->toString() + "\n");
        }
    }
    return move;
}

Move *NetworkPlayer::parseIntoMove(string newMove) {
    cout << newMove << endl;
    if (strcmp(newMove.c_str(), "noMove") == 0) {
        return NULL;
    }
    NetworkPlayer *self = this;
    int row, col;
    Coordinate *position;
    // newMove is in the form "X, Y"
    // X is row and Y is col
    if (newMove.find(",") == string::npos) {
        position = new Coordinate(-1,-1);
    } else {
        string rowAsString = newMove.substr(0, newMove.find(", "));
        string colAsString = newMove.substr(newMove.find(", ") + 1, MAX_MOVE);
        stringstream convertRow(rowAsString);
        stringstream convertCol(colAsString);
        if (( convertRow >> row ) && ( convertCol >> col )) {
            position = new Coordinate(row, col);
        } else {
            throw "Couldn't receive move";
        }
    }
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

void NetworkPlayer::playLastMove() const {
    string str = ( *lastMove )->toString();
    if (strcmp(str.c_str(), "0, 0") == 0) {
        char *endMove = const_cast<char *>("END");
        client->send(endMove);
    } else {
        char *copy = new char[MAX_MOVE];
        memset(copy, 0, MAX_MOVE);
        string strClose = "close ";
        strClose.append(str);
        strcpy(copy, strClose.c_str());
        client->send(copy);
        delete[] copy;
    }
}
