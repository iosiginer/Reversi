//
// Created by iosi on 11/6/17.
//

#ifndef REVERSI_MOVE_H
#define REVERSI_MOVE_H


#include "Cell.h"
//#include "Player.h"

/**
 * Class used to define a Move in the Game. It holds a position (Coordinate) and a list (vector) of directions, which
 * are the directions that need to be flipped by the Board.
 */
class Move {
private:
    Coordinate *position;
    vector<Coordinate *> directions;
    int gain;

public:
    /**
     * Constructor. Gets the position and the vector, ready for using.
     */
    Move(Coordinate *, vector<Coordinate *>);

    /**
     * Getter for the Coordinates string form, used to show the user the possible Moves.
     * @return string - string expression of the Coordinate.
     */
    string getCoordinateAsString() const;

    /**
     * Getter for the position of the Move.
     * @return Coordinate - the position of the Cell the user can conquer.
     */
    Coordinate *getCoordinate() const;

    /**
     * Getter for the list of directions in which to move to flip cells.
     * @return vector<Coordinate*> directions - the directions of gains for the Move.
     */
    vector<Coordinate *> getDirections() const;

    /**
     * Getter for the number of Cells that will be flipped if this Move is chosen. Used mostly for bots decisions.
     * @return int - the number of flipped cells this move will get if used.
     */
    int getGain() const;

    /**
     * Setter for the gain of this Move. This is because the gain is calculated by the Logic, and not the Move itself.
     */
    void setGain(int);

    ~Move();
};


#endif //REVERSI_MOVE_H
