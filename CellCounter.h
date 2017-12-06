#ifndef REVERSI_CELLCOUNTER_H
#define REVERSI_CELLCOUNTER_H

#include <iostream>
#include "Color.h"
#include "Cloneable.h"

using namespace std;

class CellCounter : public Cloneable {
private:
    Color player1, player2;
    int points1, points2;

public:
    CellCounter();

    CellCounter(int points1, int points2);

    void changeValue(Color previous, Color current);

    int getWinner() const;

    bool gameOver(int size) const;

    int getPoints1() const;

    int getPoints2() const;

    CellCounter *clone() const;

    ~CellCounter() {}
};


#endif //REVERSI_CELLCOUNTER_H
