#include "gtest/gtest.h"
#include "../Board.h"
#include "BoardTest.h"

using namespace std;

TEST_F(BoardTest, simpleTest) {
    EXPECT_EQ(board->getSize(), 8);
    EXPECT_EQ(board->getCell(4, 4)->getContent(), 'O');
    EXPECT_EQ(board->getCell(4, 5)->getContent(), 'X');
    EXPECT_EQ(board->getCell(5, 4)->getContent(), 'X');
    EXPECT_EQ(board->getCell(5, 5)->getContent(), 'O');
}

TEST_F(BoardTest, pointsTest) {
    //Getting player points through the cellCounter
    EXPECT_EQ(board->getPlayer1Points(), board->getPlayer1Points());
}

TEST_F(BoardTest, assignTest) {
    vector<Coordinate *> d;
    d.push_back(new Coordinate(1, 0));
    move = new Move(new Coordinate(3, 4), d);
    board->applyMove(move, blackPlayer);
    EXPECT_EQ(board->getCell(3, 4)->getContent(), 'X');
    EXPECT_EQ(board->getCell(4, 4)->getContent(), 'X');
    delete (move);
}

TEST_F(BoardTest, cloneBoard) {
    Board *cloneBoard = board->clone();
    for (int i = 1; i <= board->getSize(); i++) {
        for (int j = 1; j <= board->getSize(); j++) {
            EXPECT_TRUE(*(board->getCell(i, j)) == *(cloneBoard->getCell(i, j)));
        }
    }
    delete cloneBoard;
}

TEST_F(BoardTest, gameOver) {
    //Making board without moves for 'X'
    board->getCell(4, 4)->sumOne(WHITE, BLACK);
    board->getCell(5, 5)->sumOne(WHITE, BLACK);
    EXPECT_TRUE(board->gameOver());
}
