#ifndef REVERSI_BOARD_H
#define REVERSI_BOARD_H

#include "Color.h"
#include "Move.h"
#include "Printer.h"
#include "Player.h"
#include "CellCounter.h"
#include "Cloneable.h"
#include "ConsolePrinter.h"

#include <iostream>

/**
 * Class holding most of the Data. It holds a two-dimensional array which in turn holds pointers to Cells,
 * which can be empty or have a char content. It also holds a printer (depending on the interface) and a Counter
 * to be in charge of the points throughout the Game.
 */
class Board : public Cloneable {
private:
    int size;
    Cell ***matrix;
    CellCounter *counter;
    Printer *printer;
    Color colorP1, colorP2;

    /**
     * Recieves a direction to move towards, and flip every Cell until it reaches one that belongs to the Player.
     */
    void flipGains(Coordinate *startingPos, Player *currentPlayer, Coordinate *directionToMoveTo);

    /**
    * Finds which are the neighbouring Cells of the given Cell, and assigns them to it.
    */
    vector<Coordinate> getNeighbours(int row, int column);

public:

    /**
    * Constructor. Has all default arguments that can be changed by hand or by arguments in the Terminal.
    * @param play1 - the content for Player 1.
    * @param play2 - the content for Player 2.
    * @param size  - the desired size of the Board.
    * @param counter - the counter cells of the Board.
    */
    Board(Color = BLACK, Color = WHITE, int size = 8,
          Printer *printer = new ConsolePrinter(), CellCounter *counter = new CellCounter());

    /**
     * Calls an outern Printer class to deal with showing the Board on the GUI.
     */
    void print() const;

    /**
     * Returns the Cell on the given coordinates.
     * @return Cell - the Cell at the given coordinates.
     */
    Cell *getCell(int, int) const;

    /**
     * Same as getCell(int, int), but gets a Coordinate.
     * @return Cell - the Cell at the given Coordinate.
     */
    Cell *getCell(Coordinate) const;


    /**
     * Checks whether the Board contains a Cell at the given Coordinates.
     * @return true of the Coordinates define a Cell, false if not.
     */
    bool contains(Coordinate) const;

    /**
     * Getter for the size of the Board.
     * @return int - the size of the two-dimensional array 'board'.
     */
    int getSize() const;

    /**
     * Performs the actual work of conquering a Cell.
     */
    void applyMove(Move *, Player *);

    /**
     * Checks whether the game has to end.
     * @return true if the Game should end now.
     */
    bool gameOver() const;

    /**
     * Compares the points of the players, and returns the winner (or tie).
     * @return int - and integer representing who won (0 for tie, 1 for P1, 2 for P2).
     */
    int getWinner() const;

    /**
     * Getter for the points of P1.
     * @return int - the points of Player 1.
     */
    int getPlayer1Points() const;

    /**
     * Getter for the points of P2.
     * @return int - the points of Player 2.
     */
    int getPlayer2Points() const;

    /**
     * Returns a string showing the points of both players. To be showed in GUI.
     * @return string - the points of both players.
     */
    string getPoints() const;

    /**
     * Function to return a cloned version of the Board. That is, a new Board with the same contents.
     * @return Board * - pointer to a new Board.
     */
    Board *clone() const;

    /**
     * Destructor!!! Use carefully.
     */
    ~Board();
};


#endif //REVERSI_BOARD_H
