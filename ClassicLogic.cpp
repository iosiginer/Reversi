//
// Created by iosi on 08/11/17.
//

#include "ClassicLogic.h"

ClassicLogic::ClassicLogic(Board *board) : board(board) {}


vector<Move *> ClassicLogic::getPossibleMoves(Player *player) const {
    vector<Move *> moves;
    for (int row = 1; row <= board->getSize(); row++) {
        for (int col = 1; col <= board->getSize(); col++) {
            if (board->getCell(row, col)->isEmpty()) {
                Coordinate *pos = new Coordinate(row, col);
                vector<Coordinate *> directions = getDirections(pos, player);
                if (!directions.empty()) {
                    Move *move = new Move(pos, directions);
                    moves.push_back(move);
                }
            }
        }
    }
    return moves;
}


vector<Coordinate *> ClassicLogic::getDirections(Coordinate *pos, Player *player) const {
    vector<Coordinate *> result;
    Cell *cell = board->getCell(*pos);
    vector<Coordinate *> directions = cell->getNeighboursByDirection();
    for (int i = 0; i < directions.size(); i++) {
        Coordinate *dir = directions[i];
        Cell *nextCell = board->getCell(pos->sum(*dir));
        if (player->isOpponent(nextCell)) {
            if (validDirection(nextCell->getPosition(), player, dir)) {
                result.push_back(dir);
            }
        }
    }
    return result;
}

bool ClassicLogic::validDirection(Coordinate *pos, Player *player, Coordinate *direction) const {
    Cell *next = board->getCell(pos->sum(*direction));
    if (player->isOpponent(next)) {
        return validDirection(next->getPosition(), player, direction);
    } else if (next->isEmpty()) { return false; }
    return true;
}

