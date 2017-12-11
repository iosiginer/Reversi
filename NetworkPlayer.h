#ifndef REVERSI_NETWORKPLAYER_H
#define REVERSI_NETWORKPLAYER_H


#include "HumanPlayer.h"
#include "Board.h"
#include "GameLogic.h"
#include "Client.h"

class NetworkPlayer : public Player {
private:
    Color content;
    Coordinate **lastMove;
    GameLogic &logic;
    Board *board;
    Printer *printer;
    Client *client;

    /**
     * The method converting the move from string to move
     * @return Move
     */
    Move *parseIntoMove(char* newMove);

public:
    NetworkPlayer(Color content, Coordinate **lastMove, Board *board, GameLogic &logic, Printer *printer,
                  Client *client);

    ~NetworkPlayer();
    /**
     * The method returns the player choice
     * @return move
     */
    virtual Move *move(vector<Move *> possibleMoves);

    /**
     * The method getting a cell and change its content to the color of the player
     */
    virtual void conquerCell(Cell *);

    /**
     * The method get the color
     * @return color
     */
    virtual Color getContent() const;

    /**
     * The method checks if the color belong to the opponent
     * @return true for yes, otherwise false
     */
    virtual bool isOpponent(Color) const;

    /**
     * Functio to deal with the Last move in a network game. Only does something in the network player.
     * @return Move - NULL in most kinds of players.
     */
    virtual void playLastMove() const;

    /**
    * Function to deal with when the player can't Move in this turn.
    */
    virtual void noMove() const;

};


#endif //REVERSI_NETWORKPLAYER_H