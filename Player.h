//
// Created by iosi on 11/5/17.
//

#ifndef REVERSI_PLAYER_H
#define REVERSI_PLAYER_H

#include <vector>
#include "Cell.h"


class Player {
private:
    char myContent;
    vector<Coordinate*> neighbourCells;

public:
    Player(char);
    void conquerCell(Cell*);
    bool isOpponent(Cell*);
    char content() const;


};


#endif //REVERSI_PLAYER_H
