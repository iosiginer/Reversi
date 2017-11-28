#ifndef REVERSI_HUMANCONSOLEPLAYER_H
#define REVERSI_HUMANCONSOLEPLAYER_H


#include "Player.h"

/**
 * Class for a Human player playing from the Console.
 * Inherits from Player.
 */
class HumanPlayer : public Player {
private:
    char content;

    /**
     * Checks the input given by the user, to check if it is of form (int,int).
     * @param row - reference to the int row, to be changed if necessary.
     * @param col - reference to the int col, to be changed if necessary.
     */
    void checkInput(int &row, int &col) const;


public:
    /**
     * Constructor. Recieves a char to act as content of the player throughout the Game.
     * @param content char - the content for the Player.
     */
    HumanPlayer(char content);

    /**
     * Performs a move on the Board, according to input by the user.
     * This is the interface for playing. CAREFUL. IT WORKS PERFECTLY.
     * @param possibleMoves - list of Coordinates where the Player can conquer a Cell.
     * @return Move - the move to be applied by the Board (called in GameFlow).
     */
    virtual Move *move(vector<Move *> possibleMoves);

    /**
     * Checks whether a Cell's content belongs to the opponent.
     * @return true if the Cell's content is not empty and is different from own content.
     */
    virtual bool isOpponent(char) const;

    /**
     * Getter for the content.
     * @return char - the content of the Player.
     */
    virtual char getContent() const;

    /**
     * Set the Cell's content to be the same as the Player's own.
     */
    virtual void conquerCell(Cell *);


    /**
     * Prints the possible moves of the Player for the current turn.
     */
    virtual void showPossibleMoves(vector<Move *>) const;

};


#endif //REVERSI_HUMANCONSOLEPLAYER_H
