/**
 * Josef Ginerman 332494830
 * Barak Talmor 308146240
 */

#ifndef REVERSI_CLASSICLOGIC_H
#define REVERSI_CLASSICLOGIC_H


#include "GameLogic.h"

/**
 * The classic set of rules for the Reversi Game. It inherits from GameLogic, to make it more easy to find.
 */
class ClassicLogic : public GameLogic {
private:
    /**
     * Get the directions in which the Player should check for possible Moves.
     * @return vector<Coordinate *> the list of possible directions to move.
     */
    virtual vector<Coordinate *> getDirections(Coordinate, Player *, int *, Board *) const;

    /**
     * Checks whether the direction is valid. It runs toward the desired direction and checks it as a Turing Machine.
     * @return bool - true only if the direction gives any gains for the Move.
     */
    bool validDirection(Coordinate *, Player *, Coordinate *, int *, Board *) const;
public:
    /**
     * Constructor for ClassicLogic.
     */
    ClassicLogic();

    /**
     * Analizes each empty cell and finds all the possible moves for the Player.
     * @return vector<Move *> - the list of possible moves for the Player.
     */
    virtual vector<Move *> getPossibleMoves(Player *, Board *) const;

    /**
     * Destructor.
     */
    ~ClassicLogic() {}
};


#endif //REVERSI_CLASSICLOGIC_H
