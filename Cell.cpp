//
// Created by iosi on 11/3/17.
//

#include "Cell.h"

Cell::Cell(Coordinate *position, char content) : content(content), position(position) {
    this->neighbours = vector<Cell*>();
}


char Cell::getContent() const { return this->content; }

Coordinate* Cell::getPosition() const { return this->position; }

string Cell::getPostionAsString() const { return this->position->toString(); }

void Cell::setContent(char content) { this->content = content; }

string Cell::toString() const {
    std::string cont = string(1, content);
    return " " + cont + " |";
}

bool Cell::isBlack() const {
    return this->content == 'X' || this->content == 'x';
}

bool Cell::isWhite() const {
    return this->content == 'O' || this->content == 'o';
}

bool Cell::isEmpty() const {
    return this->content == ' ';
}


Cell::~Cell() {}

vector<Cell*> Cell::getNeighbours() const {
    return this->neighbours;
}

void Cell::setNeighbours(vector<Cell*> neighbours) {
    this->neighbours = neighbours;
}

void Cell::setNumOfNeighbours(int num) {
    this->numOfNeighbours = num;
}

int Cell::getNumOfNeighbours() {
    return this->numOfNeighbours;
}

vector<Coordinate *> Cell::getNeighboursByDirection() {
    vector<Coordinate *> directions;
    vector<Cell*> neigh = getNeighbours();
    for (int i = 0; i < neigh.size(); i++) {
        Cell *cell = neigh[i];
        directions.push_back(this->getPosition()->getDirectionTo(cell->getPosition()));
    }
    return directions;
}
