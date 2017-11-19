//
// Created by iosi on 11/3/17.
//

#include "Cell.h"

Cell::Cell(Coordinate *position, CellCounter *counter, char content) : content(content), position(position),
                                                                       counter(counter) {
    this->neighbours = vector<Cell *>();
}


char Cell::getContent() const { return this->content; }

Coordinate *Cell::getPosition() const { return this->position; }

void Cell::setContent(char content) { this->content = content; }

string Cell::toString() const {
    std::string cont = string(1, content);
    return " " + cont + " |";
}

bool Cell::isEmpty() const {
    return (this->content == ' ' || this->content == '*');
}

vector<Cell *> Cell::getNeighbours() const {
    return this->neighbours;
}

void Cell::setNeighbours(vector<Cell *> neighbours) {
    this->neighbours = neighbours;
}


void Cell::sumOne(char previous, char current) {
    this->counter->changeValue(previous, current);
}

Cell::~Cell() {
    delete position;
    neighbours.clear();
}
