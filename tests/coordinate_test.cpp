#include "gtest/gtest.h"
#include "../Board.h"

TEST(CoordinateTest, coordinateChecks) {
    //Checks equality between two coordinates
    Coordinate coord1(1,1);
    Coordinate coord2(1,1);
    EXPECT_EQ(coord1.toString() == "(1,1)", 1);
    EXPECT_EQ(coord1 == coord2, 1);

    //Checks direction between two coordinates
    Coordinate coord3(2,2);
    Coordinate direction(-1,-1);
    EXPECT_EQ(*(coord3.getDirectionTo(&coord2)) == direction, 1);
}

