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

    /**
     * Prints the Menu options, and lets the user decide.
     * According to the User choice, it creates the players.
     */
    void runMenu();


public:

    /**
     * Constructor for creating Human vs Network or Network vs Human
     */
    GameFlow(int size, Printer *printer, int typeOfGames, Client *client);

    /**
     * Constructor for creating Human Vs Human or Human Vs AI
     */
    GameFlow(int size, Printer *printer, int typeOfGame);

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
