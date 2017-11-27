/**
 * Josef Ginerman 332494830
 * Barak Talmor 308146240
 */

#include "CellCounter.h"

CellCounter::CellCounter(char player1, char player2) : player1(player1), player2(player2) {
    points1 = points2 = 2;
}


CellCounter::CellCounter(char player1, char player2, int points1, int points2) : player1(player1), player2(player2),
                                                                                 points1(points1), points2(points2) {}


void CellCounter::changeValue(char previous, char current) {
    if (current == player1) {
        points1 += 1;
        if (previous != ' ') { points2 -= 1; }
    } else if (current == player2) {
        points2 += 1;
        if (previous != ' ') { points1 -= 1; }
    }
}

int CellCounter::getWinner() const {
    if (points1 > points2) { return 1; }
    else if (points2 > points1) { return 2; }
    else { return 0; }    //tie
}

bool CellCounter::gameOver(int size) const {
    return (points1 + points2 == size * size);
}

int CellCounter::getPoints1() const {
    return this->points1;
}

int CellCounter::getPoints2() const {
    return this->points2;
}

CellCounter *CellCounter::clone() const {
    return new CellCounter(this->player1, this->player2, this->points1, this->points2);
}
