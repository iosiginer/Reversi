/**
 * Barak Talmor
 * 308146240
 */

#ifndef TESTS_BOARDTEST_H
#define TESTS_BOARDTEST_H

#include "gtest/gtest.h"
#include "../Board.h"
#include "../HumanPlayer.h"

struct BoardTest : testing::Test {
    Board* board;
    Player* blackPlayer;
    Player* whitePlayer;
    Move* move;
    BoardTest() {
        board = new Board();
        blackPlayer = new HumanPlayer('X');
        whitePlayer = new HumanPlayer('O');
    }

    ~BoardTest() {
        delete(board);
        delete(blackPlayer);
        delete(whitePlayer);
    }
};

#endif //TESTS_BOARDTEST_H
