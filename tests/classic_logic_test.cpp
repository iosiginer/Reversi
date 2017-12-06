#include "ClassicLogicTest.h"

using namespace testing;


TEST_F(ClassicLogicTest, moves) {
    moves = logic->getPossibleMoves(player, board);
    //Checks the first possible move: (3,4)
    EXPECT_TRUE(*(moves[0]->getCoordinate()) == Coordinate(3,4));
    EXPECT_TRUE(*(moves[0]->getDirections()[0]) == Coordinate(1,0));

    //Checks the second possible move: (4,3)
    EXPECT_TRUE(*(moves[1]->getCoordinate()) == Coordinate(4,3));
    EXPECT_TRUE(*(moves[1]->getDirections()[0]) ==  Coordinate(0,1));

    //Checks the third possible move: (5,6)
    EXPECT_TRUE(*(moves[2]->getCoordinate()) == Coordinate(5,6));
    EXPECT_TRUE(*(moves[2]->getDirections()[0]) ==  Coordinate(0,-1));

    //Checks the third possible move: (6,5)
    EXPECT_TRUE(*(moves[3]->getCoordinate()) == Coordinate(6,5));
    EXPECT_TRUE(*(moves[3]->getDirections()[0]) == Coordinate(-1,0));
}

TEST_F(ClassicLogicTest, noMoves) {
    //Making board without moves for 'X'
    board->getCell(4, 4)->setContent(BLACK);
    board->getCell(5, 5)->setContent(BLACK);
    moves = logic->getPossibleMoves(player, board);
    //Checking if the vector didn't get moves
    EXPECT_TRUE(moves.empty());
}