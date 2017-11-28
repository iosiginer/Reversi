#include "AIPlayerTest.h"

TEST_F(AIPlayerTest, checkMove) {
    //Playing one move for the human player
    direction.push_back(new Coordinate(1,0));
    choice = new Move(new Coordinate(3,4), direction);
    board->applyMove(choice, humanPlayer);
    delete choice;
    //
    moves = logic->getPossibleMoves(aPlayer, board);
    choice = aPlayer->move(moves);

    //There are 4 possibleMoves but only 3 are with the same grade choice
    EXPECT_TRUE(*(choice->getCoordinate()) == Coordinate(3,3) ||
                *(choice->getCoordinate()) == Coordinate(5,3) ||
                *(choice->getCoordinate()) == Coordinate(5,6));
}
