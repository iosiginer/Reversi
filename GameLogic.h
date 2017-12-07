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

    /**
     * Returns a Move instantation with the Coordinate in arguments as position.
     * @param pos - the wanted position for the Move.
     * @param player - the current playing player.
     * @param board - the current board.
     * @return Move - the move, ready to be used.
     */
    virtual Move *getMoveByPosition(Coordinate *pos, Player *player, Board *board) = 0;

};

#endif //REVERSI_GAMELOGIC_H
