//
// Created by iosi on 11/6/17.
//

#include "Move.h"

Move::Move(Coordinate *position, vector<Coordinate *> directions) : position(position),
                                                                    directions(directions) {
    this->gain = 0;
}

string Move::getCoordinateAsString() const {
    return this->position->toString();
}

Coordinate *Move::getCoordinate() const {
    return this->position;
}

vector<Coordinate *> Move::getDirections() const {
    return this->directions;
}

void Move::setGain(int x) {
    this->gain = x;
}

int Move::getGain() const {
    return this->gain;
}

