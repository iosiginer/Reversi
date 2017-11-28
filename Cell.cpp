#include "Cell.h"

Cell::Cell(Coordinate *position, CellCounter *counter, vector<Coordinate> neighbours, char content) : content(content),
                                                                                                      position(
                                                                                                              position),
                                                                                                      counter(counter),
                                                                                                      neighbours(
                                                                                                              neighbours) {
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

vector<Coordinate> Cell::getNeighbours() const {
    return this->neighbours;
}

void Cell::sumOne(char previous, char current) {
    this->counter->changeValue(previous, current);
}

bool Cell::operator ==(const Cell& cell2) {
    return (getPosition()->getRow() == cell2.getPosition()->getRow() &&
            getPosition()->getCol() == cell2.getPosition()->getCol() &&
            getContent() == cell2.getContent());
}

Cell::~Cell() {
    delete position;
    neighbours.clear();
}
