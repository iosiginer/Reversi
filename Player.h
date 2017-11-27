/**
 * Josef Ginerman 332494830
 * Barak Talmor 308146240
 */

#ifndef REVERSI_PLAYER_H
#define REVERSI_PLAYER_H

#include <vector>
#include "Move.h"

/**
 * Completely virtual Player class. It is used to determine a general definition of Player, and let me define
 * different kinds of them, like: console or GUI, human or AI, local or network.
 */
class Player {

public:
    /**
     * Performs a move on the Board, according to input by the user.
     * This is the interface for playing. CAREFUL. IT WORKS PERFECTLY.
     * @param possibleMoves - list of Coordinates where the Player can conquer a Cell.
     * @return Move - the move to be applied by the Board (called in GameFlow).
     */
    virtual Move *move(vector<Move *> possibleMoves) = 0;

    /**
     * Checks whether a Cell's content belongs to the opponent.
     * @return true if the Cell's content is not empty and is different from own content.
     */
    virtual bool isOpponent(char) const = 0;

    /**
     * Set the Cell's content to be the same as the Player's own.
     */
    virtual void conquerCell(Cell *) = 0;

    /**
     * Destructor.
     */
    virtual ~Player() {}
};


#endif //REVERSI_PLAYER_H
