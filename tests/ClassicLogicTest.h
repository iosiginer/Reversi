/**
 * Barak Talmor
 * 308146240
 */
//

#ifndef TESTS_CLASSICLOGICTEST_H
#define TESTS_CLASSICLOGICTEST_H

#include "gtest/gtest.h"
#include "../ClassicLogic.h"
#include "../Board.h"
#include "../HumanPlayer.h"

struct ClassicLogicTest : testing::Test {
    Board *board;
    ClassicLogic *logic;
    Player *player;
    vector<Move *> moves;
    Printer *printer;
    ClassicLogicTest() {
        board = new Board();
        logic = new ClassicLogic();
        printer = new ConsolePrinter();
        player = new HumanPlayer('X', printer);
    }

    ~ClassicLogicTest() {
        delete board;
        delete logic;
        delete player;
        delete printer;
        for (int i=0; i<moves.size(); i++) { delete(moves[i]); }
        moves.clear();
    }
};

#endif //TESTS_CLASSICLOGICTEST_H
