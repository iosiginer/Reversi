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
    ClassicLogicTest() {
        board = new Board();
        logic = new ClassicLogic();
        player = new HumanPlayer('X');
    }

    ~ClassicLogicTest() {
        delete board;
        delete logic;
        delete player;
        for (int i=0; i<moves.size(); i++) { delete(moves[i]); }
        moves.clear();
    }
};

#endif //TESTS_CLASSICLOGICTEST_H
