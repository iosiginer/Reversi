//
// Created by iosi on 11/3/17.
//

#include "Coordinate.h"

Coordinate::Coordinate(int row, int col) : row(row), col(col) {}

int Coordinate::getRow() const { return row; }

int Coordinate::getCol() const { return col; }

string Coordinate::toString() const {
    ostringstream rowConvert;
    ostringstream colConvert;
    rowConvert << row;
    colConvert << col;
    return '(' + rowConvert.str() + ',' + colConvert.str() + ')';
}


Coordinate Coordinate::sum(Coordinate *col) const {
    return Coordinate(this->getRow() + col->getRow(), this->getCol() + col->getCol());
}

Coordinate *Coordinate::getDirectionTo(Coordinate *to) const {
    int fromRow = this->getRow();
    int fromCol = this->getCol();
    return new Coordinate(to->getRow() - fromRow, to->getCol() - fromCol);
}
