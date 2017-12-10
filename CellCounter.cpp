/**
 * Josef Ginerman 332494830
 * Barak Talmor 308146240
 */

#include "CellCounter.h"

CellCounter::CellCounter() {
    player1 = BLACK;
    player2 = WHITE;
    points1 = points2 = 2;
}


CellCounter::CellCounter(int points1, int points2) : points1(points1), points2(points2) {
    player1 = BLACK;
    player2 = WHITE;
}


void CellCounter::changeValue(Color previous, Color current) {
    if (current == player1) {
        points1 += 1;
        if (previous != EMPTY) { points2 -= 1; }
    } else if (current == player2) {
        points2 += 1;
        if (previous != EMPTY) { points1 -= 1; }
    }
}

int CellCounter::getWinner() const {
    if (points1 > points2) { return 1; }
    else if (points2 > points1) { return 2; }
    else { return 0; }    //tie
}

bool CellCounter::gameOver(int size) const {
    return (points1 + points2 == size * size) || (points1 == 0) || (points2 == 0);
}

int CellCounter::getPoints1() const {
    return this->points1;
}

int CellCounter::getPoints2() const {
    return this->points2;
}

CellCounter *CellCounter::clone() const {
    return new CellCounter(this->points1, this->points2);
}
