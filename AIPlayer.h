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
    char content, oppContent;
    Board *cleanBoard;
    GameLogic &logic;

    map<Move *, int> getMovesMap(vector<Move *> possibleMoves);

public:
    /**
     * Constructor for AIPlayer.
     * @param content  - the content of this player.
     * @param oppContent - the content of the opponent.
     */
    AIPlayer(char content, char oppContent, Board *, GameLogic &);

    /**
     * Perform the logics of picking a move for this turn.
     * @param possibleMoves - the vector of possible moves the player has.
     * @return Move * - the move to be performed by the GameFlow.
     */
    virtual Move *move(vector<Move *> possibleMoves);

    /**
     * Checks to see if the given content belongs to the opposing player.
     * @return bool - true if the char belongs to the opponent
     */
    virtual bool isOpponent(char) const;

    /**
     * Set the Cell's content to be the same as the Player's own.
     */
    virtual void conquerCell(Cell *);

    /**
     * Gets the content of the Player, the color.
     * @return char - the char representing the player.
     */
    char getContent() const;

    /**
     * Destructor.
     */
    virtual ~AIPlayer() {}
};


#endif //REVERSI_AIPLAYER_H
