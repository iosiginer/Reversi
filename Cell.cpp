#include "Cell.h"

Cell::Cell(Coordinate *position, CellCounter *counter, vector<Coordinate> neighbours) : position(position),
                                                                                        counter(counter),
                                                                                        neighbours(neighbours) {
    this->content = EMPTY;
}


Color Cell::getContent() const { return this->content; }

Coordinate *Cell::getPosition() const { return this->position; }

void Cell::setContent(Color content) { this->content = content; }

string Cell::toString() const {
    string cont;
    switch (content) {
        case BLACK:
            cont = 'X';
            break;
        case WHITE:
            cont = 'O';
            break;
        case EMPTY:
            cont = ' ';
            break;
    }
    return " " + cont + " |";
}

bool Cell::isEmpty() const {
    return (this->content == EMPTY);
}

vector<Coordinate> Cell::getNeighbours() const {
    return this->neighbours;
}

void Cell::sumOne(Color previous, Color current) {
    this->counter->changeValue(previous, current);
}

bool Cell::operator==(const Cell &cell2) {
    return (getPosition()->getRow() == cell2.getPosition()->getRow() &&
            getPosition()->getCol() == cell2.getPosition()->getCol() &&
            getContent() == cell2.getContent());
}

Cell::~Cell() {
    delete position;
    neighbours.clear();
}
