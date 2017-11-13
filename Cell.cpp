//
// Created by iosi on 11/3/17.
//

#include "Cell.h"

Cell::Cell(Coordinate *position, CellCounter *counter, char content) : content(content), position(position),
                                                                       counter(counter) {
    this->neighbours = vector<Cell *>();
    this->numOfNeighbours = 0;
}


char Cell::getContent() const { return this->content; }

Coordinate *Cell::getPosition() const { return this->position; }

void Cell::setContent(char content) { this->content = content; }

string Cell::toString() const {
    std::string cont = string(1, content);
    return " " + cont + " |";
}

bool Cell::isEmpty() const {
    return this->content == ' ';
}

vector<Cell *> Cell::getNeighbours() const {
    return this->neighbours;
}

void Cell::setNeighbours(vector<Cell *> neighbours) {
    this->neighbours = neighbours;
    this->numOfNeighbours = (int) neighbours.size();
}

void Cell::setNumOfNeighbours(int num) {
    this->numOfNeighbours = num;
}

vector<Coordinate *> Cell::getNeighboursByDirection() {
    vector<Coordinate *> directions;
    vector<Cell *> neigh = getNeighbours();
    for (int i = 0; i < neigh.size(); i++) {
        Cell *cell = neigh[i];
        directions.push_back(this->getPosition()->getDirectionTo(cell->getPosition()));
    }
    return directions;
}

void Cell::sumOne(char previous, char current) {
    this->counter->changeValue(previous, current);
}

Cell::~Cell() {
    delete position;
    neighbours.clear();
}
