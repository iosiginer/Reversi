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
     * Returns a Move instantation with the Coordinate in arguments as position.
     * @param pos - the wanted position for the Move.
     * @param player - the current playing player.
     * @param board - the current board.
     * @return Move - the move, ready to be used.
     */
    virtual Move *getMoveByPosition(Coordinate *pos, Player *player, Board *board);

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
