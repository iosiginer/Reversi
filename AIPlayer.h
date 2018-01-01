#ifndef REVERSI_AIPLAYER_H
#define REVERSI_AIPLAYER_H

#include <map>

#include "Player.h"
#include "Board.h"
#include "GameLogic.h"

/**
 * This class inherits from the Player class, and it is a player controlled solely by an algorithm,
 * allowing the player to play 'against the computer'.
 */
class AIPlayer : public Player {
private:
    Color content, oppContent;
    Board *cleanBoard;
    GameLogic &logic;
    Printer *printer;

    map<Move *, int> getMovesMap(vector<Move *> possibleMoves);

public:
    /**
     * Constructor for AIPlayer.
     * @param content  - the content of this player.
     * @param oppContent - the content of the opponent.
     */
    AIPlayer(Color content, Color oppContent, Board *, GameLogic &, Printer *printer);

    /**
     * Perform the logic of picking a move for this turn.
     * @param possibleMoves - the vector of possible moves the player has.
     * @return Move * - the move to be performed by the GameFlow.
     */
    virtual Move *move(vector<Move *> possibleMoves);

    /**
     * Checks to see if the given content belongs to the opposing player.
     * @return bool - true if the char belongs to the opponent
     */
    virtual bool isOpponent(Color) const;

    /**
     * Set the Cell's content to be the same as the Player's own.
     */
    virtual void conquerCell(Cell *);

    /**
     * Gets the content of the Player, the color.
     * @return Color - the char representing the player.
     */
    virtual Color getContent() const;

    /**
    * Function to deal with when the player can't Move in this turn.
    */
    virtual void noMove() const;

    /**
     * Destructor.
     */
    virtual ~AIPlayer() {}
};


#endif //REVERSI_AIPLAYER_H
