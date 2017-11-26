//
// Created by iosi on 11/5/17.
//

#ifndef REVERSI_GAMELOGIC_H
#define REVERSI_GAMELOGIC_H


#include "Board.h"
#include "Move.h"

/**
 * Class in charge of the Logic (the rules) of the Game.
 * This one is completely virtual, to allow easy changes and different sets of rules.
 */
class GameLogic {
private:
    /**
     * Get the directions in which the Player should check for possible Moves.
     * @return vector<Coordinate *> the list of possible directions to move.
     */
    virtual vector<Coordinate *> getDirections(Coordinate, Player *, int *, Board *) const = 0;

public:
    /**
     * Analizes each empty cell and finds all the possible moves for the Player.
     * @return vector<Move *> - the list of possible moves for the Player.
     */
    virtual vector<Move *> getPossibleMoves(Player *, Board *) const = 0;
};

#endif //REVERSI_GAMELOGIC_H
