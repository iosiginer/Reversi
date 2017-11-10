//
// Created by iosi on 11/5/17.
//

#include "Player.h"


Player::Player(char myContent) : myContent(myContent) {}

void Player::conquerCell(Cell* cell) {
    if (cell->isEmpty()) { cell->setContent(this->myContent);}
}

bool Player::isOpponent(Cell *cell) {
    return (!cell->isEmpty() && cell->getContent() != myContent);
}

char Player::content() const {
    return this->myContent;
}
