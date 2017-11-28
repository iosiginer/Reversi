#ifndef REVERSI_GAMEFLOW_H
#define REVERSI_GAMEFLOW_H

#include "Board.h"
#include "GameLogic.h"
#include "ClassicLogic.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"

/**
 * Class in charge of holding all other classes and controling the Flow of the Game (duh...).
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
    bool player1Turn;
    bool noMove;
    bool noMoreMoves;

    /**
     * Let one player play.
     */
    void playOneTurn();

    /**
     * Finish the Game. Presenting the player with a "Game over screen" //
     */
    void gameOver() const;

    /**
     * The method initialize the second player by user choice: AI or Human.
     */
    void initPlayer2(char first, char second);

public:
    /**
     * Constructor. Gets two chars and an int, used to create the Board and the Players.
     */
    explicit GameFlow(char = 'X', char = 'O', int = 8, Printer *printer = new ConsolePrinter());

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
