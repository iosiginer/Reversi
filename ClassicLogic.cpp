//
// Created by iosi on 08/11/17.
//

#include "ClassicLogic.h"

ClassicLogic::ClassicLogic(Board *board) : board(board) {}


vector<Move *> ClassicLogic::getPossibleMoves(Player *player) const {

    vector<Move *> moves;
    int gain = 0;
    for (int row = 1; row <= board->getSize(); row++) {
        for (int col = 1; col <= board->getSize(); col++) {
            if (board->getCell(row, col)->isEmpty()) {
                Coordinate pos = Coordinate(row, col);
                gain = 0;
                vector<Coordinate *> directions = getDirections(pos, player, &gain);
                if (!directions.empty()) {
                    moves.push_back(new Move(new Coordinate(row, col), directions));
                    moves[moves.size() - 1]->setGain(gain);
                }
            }
        }
    }
    return moves;
}


vector<Coordinate *> ClassicLogic::getDirections(Coordinate pos, Player *player, int *rgain) const {
    vector<Coordinate *> result;
    Cell *cell = board->getCell(pos);
    vector<Coordinate *> directions;
    vector<Coordinate> neighbours = cell->getNeighbours();
    for (int i = 0; i < neighbours.size(); i++) {
        Coordinate *dir = cell->getPosition()->getDirectionTo(&neighbours[i]);
        int maybe = 0;
        Cell *nextCell = board->getCell(pos.sum(dir));
        if (player->isOpponent(nextCell->getContent())) {
            maybe += 1;
            if (validDirection(nextCell->getPosition(), player, dir, &maybe)) {
                result.push_back(dir);
            } else { delete dir; }
        } else { delete dir; }
        *rgain += maybe;
    }
    return result;
}

bool ClassicLogic::validDirection(Coordinate *pos, Player *player, Coordinate *direction, int *maybe) const {
    Coordinate newPos = pos->sum(direction);
    if (!board->contains(newPos)) {
        *maybe = 0;
        return false;
    } // for a cell outside the board
    Cell *next = board->getCell(newPos);
    if (player->isOpponent(next->getContent())) {
        *maybe += 1;
        return validDirection(next->getPosition(), player, direction, maybe);
    } else if (next->isEmpty()) {
        *maybe = 0;
        return false;
    }
    return true;
}