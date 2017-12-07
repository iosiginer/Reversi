/**
 * Created by Josef Ginerman on 07/12/17.
 * ID : 332494830
 **/

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

    Move *parseIntoMove(char* newMove);

public:
    NetworkPlayer(Color content, Coordinate **lastMove, Board *board, GameLogic &logic, Printer *printer,
                  Client *client);

    ~NetworkPlayer();

    virtual Move *move(vector<Move *> possibleMoves);

    virtual void conquerCell(Cell *);

    virtual Color getContent() const;

    virtual bool isOpponent(Color) const;

    /**
    * Function to deal with when the player can't Move in this turn.
    */
    virtual void noMove() const;

};


#endif //REVERSI_NETWORKPLAYER_H
