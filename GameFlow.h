#ifndef REVERSI_GAMEFLOW_H
#define REVERSI_GAMEFLOW_H

#include "Board.h"
#include "GameLogic.h"
#include "ClassicLogic.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "TurnManager.h"

/**
 * Class in charge of holding all other classes and controlling the Flow of the Game (duh...).
 * Holds a reference to: Board, Logic, two Players. Also holds three booleans to control the turns and
 * their logic.
 */
class GameFlow {
private:
    Board *board;
    GameLogic *logic;
    Player *player1;
    Player *player2;
    Printer *printer;
    TurnManager *turnManager;
    Move *lastMove;

    /**
     * Let one player play.
     */
    void playOneTurn();

    /**
     * Finish the Game. Presenting the player with a "Game over screen" //
     */
    void gameOver() const;

    /**
     * Prints the Menu options, and lets the user decide.
     * According to the User choice, it creates the players.
     */
    void runMenu();


public:

    /**
     * Constructor. Gets two chars and an int, used to create the Board and the Players.
     */
    GameFlow(int = 8, Printer *printer = new ConsolePrinter());

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
