#ifndef REVERSI_GAMEFLOW_H
#define REVERSI_GAMEFLOW_H

#include "Board.h"
#include "GameLogic.h"
#include "ClassicLogic.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "TurnManager.h"
#include "Client.h"


/**
 * Class in charge of holding all other classes and controlling the Flow of the Game (duh...).
 * Holds a reference to: Board, Logic, two Players. Also holds three booleans to control the turns and
 * their logic.
 */
class GameFlow {
private:
    Board *board;
    GameLogic *logic;
    Player *players[2];
    Printer *printer;
    TurnManager *turnManager;
    Coordinate *lastMove;

    /**
     * Let one player play.
     */
    void playOneTurn();

    /**
     * Finish the Game. Presenting the player with a "Game over screen" //
     */
    void finishGame() const;

    /**
     * Deals with checking if the Game should end.
     * @return bool - true if the game has to end.
     */
    bool gameOver() const;

    void deletePossibleMoves(vector<Move*> &possibleMoves, Move* move);

public:

    /**
     * Constructor. Gets two chars and an int, used to create the Board and the Players.
     */
    GameFlow(int size, Printer *printer, int typeOfGame);

    /**
     * Constructor. Gets two chars and an int, used to create the Board and the Players.
     */
    GameFlow(int size, Printer *printer, int typeOfGame, Client *client);


    /**
     * Perform the loop that allows the Game to be played.
     */
    void run();

    /**
     * Destructor. Careful. Code equivalent to a (Reversi) Neutrino Bomb.
     */
    ~GameFlow();
};


#endif //REVERSI_GAMEFLOW_H
