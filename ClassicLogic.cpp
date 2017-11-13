//
// Created by iosi on 08/11/17.
//

#include "ClassicLogic.h"

ClassicLogic::ClassicLogic(Board &board) : board(board) {}


vector<Move *> ClassicLogic::getPossibleMoves(Player *player) const {
    vector<Move *> moves;
    int gain;
    int *rgain = &gain;
    for (int row = 1; row <= board.getSize(); row++) {
        for (int col = 1; col <= board.getSize(); col++) {
            if (board.getCell(row, col)->isEmpty()) {
                Coordinate *pos = new Coordinate(row, col);
                gain = 0;
                vector<Coordinate *> directions = getDirections(pos, player, &gain);
                if (!directions.empty()) {
                    Move *move = new Move(pos, directions);
                    move->setGain(gain);
                    moves.push_back(move);

                }
            }
        }
    }
    return moves;
}


vector<Coordinate *> ClassicLogic::getDirections(Coordinate *pos, Player *player, int *rgain) const {
    vector<Coordinate *> result;
    Cell *cell = board.getCell(*pos);
    vector<Coordinate *> directions = cell->getNeighboursByDirection();
    for (int i = 0; i < directions.size(); i++) {
        Coordinate *dir = directions[i];
        int maybe = 0;
        Cell *nextCell = board.getCell(pos->sum(*dir));
        if (player->isOpponent(nextCell->getContent())) {
            maybe += 1;
            if (validDirection(nextCell->getPosition(), player, dir, &maybe)) {
                result.push_back(dir);
            }
        }
        *rgain += maybe;
    }
    return result;
}

bool ClassicLogic::validDirection(Coordinate *pos, Player *player, Coordinate *direction, int *maybe) const {
    Coordinate newPos = pos->sum(*direction);
    if (!board.contains(newPos)) {
        *maybe = 0;
        return false;
    } // for a cell outside the board
    Cell *next = board.getCell(newPos);
    if (player->isOpponent(next->getContent())) {
        *maybe += 1;
        return validDirection(next->getPosition(), player, direction, maybe);
    } else if (next->isEmpty()) {
        *maybe = 0;
        return false;
    }
    return true;
}
