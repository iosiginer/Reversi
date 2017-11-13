//
// Created by iosi on 10/11/17.
//

#ifndef REVERSI_CELLCOUNTER_H
#define REVERSI_CELLCOUNTER_H

#include <iostream>

using namespace std;

class CellCounter {
private:
    char player1, player2;
    int points1, points2;

public:
    CellCounter(char player1 = 'X', char player2 = 'O');

    void changeValue(char previous, char current);

    int getWinner() const;

    bool gameOver(int size) const;

    int getPoints1() const;

    int getPoints2() const;

    ~CellCounter() {}
};


#endif //REVERSI_CELLCOUNTER_H
