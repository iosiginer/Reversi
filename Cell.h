#ifndef REVERSI_CELL_H
#define REVERSI_CELL_H


#include <vector>
#include "Coordinate.h"
#include "CellCounter.h"
#include "Cloneable.h"

/**
 * Class containing the definition of a Cell, which conforms the Board matrix.
 * The Cell class knows it's position, content and neighbours. It also holds a reference to the Board's Cell Counter.
 */
class Cell {
private:
    Coordinate *position;
    CellCounter *counter;
    char content;
    vector<Coordinate> neighbours;

public:
    /**
     * Constructor. Recieves a Coordinate, a pointer to the Counter, and content.
     */
    Cell(Coordinate *, CellCounter *, vector<Coordinate> neighbours, char = ' ');

    /**
     * Getter for the Cell's content.
     * @return char - content.
     */
    char getContent() const;

    /**
     * Setter for the Cell's content.
     */
    void setContent(char);

    /**
     * Getter for the list (vector) of the Cell's neighbouring Cells.
     * @return vector<Cell*> - neighbours.
     */
    vector<Coordinate> getNeighbours() const;

    /**
     * Getter for the Cell's position.
     * @return Coordinate - position.
     */
    Coordinate *getPosition() const;

    /**
     * Returns a string representing the Cell with its content (for console).
     * @return
     */
    string toString() const;

    /**
     * Checks wether the Cell is empty or not ('empty' meaning content == ' ').
     * It also accepts a Cell with the content '*' since it marks possible moves.
     * @return bool - true if content
     */
    bool isEmpty() const;

    /**
     * Function to deal with the counting of the Cells through their flipping.
     * @param previous - the previous content of the flipped Cell.
     * @param current  - the new content of the flipped Cell.
     */
    void sumOne(char previous, char current);
    /**
     * Overloading for operator ==
     * @return true for euqal, otherwise false.
     */
    bool operator ==(const Cell&);
    /**
     * Destructor.
     */
    ~Cell();

};


#endif //REVERSI_CELL_H
