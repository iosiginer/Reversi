//
// Created by iosi on 11/6/17.
//

#include "Move.h"

Move::Move(Coordinate *position, vector<Coordinate *> directions) : position(position),
                                                                    directions(directions) {}

string Move::getCoordinateAsString() const {
    return this->position->toString();
}

Coordinate *Move::getCoordinate() const {
    return this->position;
}

vector<Coordinate *> Move::getDirections() const {
    return this->directions;
}

char Move::getContent() const {
    return this->player->content();
}

Player *Move::getPlayer() const {
    return this->player;
}

