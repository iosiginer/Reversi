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
    Printer *printer;
    BoardTest() {
        board = new Board();
        printer = new ConsolePrinter();
        blackPlayer = new HumanPlayer(BLACK, printer);
        whitePlayer = new HumanPlayer(WHITE, printer);
    }

    ~BoardTest() {
        delete(board);
        delete(blackPlayer);
        delete(whitePlayer);
        delete(printer);
    }
};

#endif //TESTS_BOARDTEST_H
