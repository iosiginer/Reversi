#ifndef REVERSI_COORDINATE_H
#define REVERSI_COORDINATE_H


#include <iostream>
#include <sstream>
#include <cstring>
#include "Cloneable.h"

using namespace std;

/**
 * Class in charge of storing a pair of ints. To be used as Coordinates for the Cells in the Board
 * and as directions for the gains in Move.
 */
class Coordinate {
private:
    int row, col;

public:
    /**
     * Constructor. Must get two ints.
     */
    Coordinate(int, int);

    /**
     * Getter for the row index.
     * @return int - row index.
     */
    int getRow() const;

    /**
     * Getter for column index.
     * @return int - col index.
     */
    int getCol() const;

    /**
     * Returns the coordinate in string form ---> (row,col)
     * @return string - the coordinates human-readable.
     */
    string toString() const;

    /**
     * Sum Coordinates. Used to get next Cell in a determined direction.
     * @return Coordinate - The place of the resulting Cell.
     */
    Coordinate sum(Coordinate *) const;

    /**
     * Gets the direction from the current Cell to the next one ( by coordinates, duh).
     * @return Coordinate - direction to next cell.
     */
    Coordinate *getDirectionTo(Coordinate *) const;

};


#endif //REVERSI_COORDINATE_H
