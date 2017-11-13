//
// Created by iosi on 10/11/17.
//

#ifndef REVERSI_HUMANCONSOLEPLAYER_H
#define REVERSI_HUMANCONSOLEPLAYER_H


#include "Player.h"

class HumanConsolePlayer : public Player {
private:
    char content;
    vector<Cell *> neighbours;

    virtual void showPossibleMoves(vector<Move *>) const;

    void checkInput(int &row, int &col) const;


public:
    HumanConsolePlayer(char content);

    virtual Move *move(vector<Move *> possibleMoves);

    virtual bool isOpponent(char) const;

    virtual char getContent() const;

    virtual void conquerCell(Cell *);

    void getInput(int &, int &);


};


#endif //REVERSI_HUMANCONSOLEPLAYER_H
