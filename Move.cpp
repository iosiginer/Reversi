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

Move::~Move() {
    delete position;
    for (int i = 0; i < directions.size(); i++) { delete directions[i]; }
    directions.clear();
}



