#ifndef TESTS_AIPLAYERTEST_H
#define TESTS_AIPLAYERTEST_H

#include "../HumanPlayer.h"
#include "../AIPlayer.h"
#include "../ClassicLogic.h"
#include "gtest/gtest.h"

struct AIPlayerTest : testing::Test{
    Board *board;
    ClassicLogic *logic;
    Player *aPlayer;
    Player *humanPlayer;
    Move* choice;
    vector<Move *> moves;
    vector<Coordinate *> direction;
    Printer *printer;
    AIPlayerTest() {
        board = new Board();
        logic = new ClassicLogic();
        printer = new ConsolePrinter();
        aPlayer = new AIPlayer(BLACK, WHITE, board, *logic, printer);
        humanPlayer = new HumanPlayer(BLACK, printer);
    }

    ~AIPlayerTest() {
        delete(board);
        delete(logic);
        delete(aPlayer);
        delete(humanPlayer);
        delete(printer);
        for (int i = 0; i < moves.size(); i++) { delete moves[i]; }
        moves.clear();
    }
};

#endif //TESTS_AIPLAYERTEST_H
