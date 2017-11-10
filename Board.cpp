//
// Created by iosi on 11/3/17.
//

#include "Board.h"
#include "BoardConsolePrinter.h"

Board::Board(int size) : size(size) {
    this->matrix = new Cell **[size];
    char empty = ' ', black = 'X', white = 'O';
    for (int row = 0; row < size; row++) {
        this->matrix[row] = new Cell *[size];
        for (int col = 0; col < size; col++) {
            this->matrix[row][col] = new Cell(new Coordinate(row + 1, col + 1));
        }
    }
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            setNeighbours(this->matrix[row][col]);
        }
    }
    int middle = size / 2;
    matrix[middle][middle - 1]->setContent(black);
    matrix[middle - 1][middle]->setContent(black);
    matrix[middle][middle]->setContent(white);
    matrix[middle - 1][middle - 1]->setContent(white);
    this->blackCells = this->whiteCells = 2;
    this->printer = new BoardConsolePrinter();
}

void Board::print() const {
    this->printer->print(matrix, size);
}

void Board::flipCell(Cell *cell) {
    if (cell->isBlack()) {
        cell->setContent('O');
        this->blackCells--;
        this->whiteCells++;

    } else if (cell->isWhite()) {
        cell->setContent('X');
        this->blackCells++;
        this->whiteCells--;
    }
}

Cell *Board::getCell(Coordinate pos) const {
    int row = pos.getRow();
    int col = pos.getCol();
    return getCell(row, col);
}

Cell *Board::getCell(int row, int col) const {
    return this->matrix[row - 1][col - 1];
}

void Board::setNeighbours(Cell *cell) {
    vector<Cell *> neighbours;
    Coordinate directions[] = {Coordinate(-1, -1), Coordinate(-1, 0), Coordinate(-1, 1), Coordinate(0, -1),
                               Coordinate(0, 1), Coordinate(1, -1), Coordinate(1, 0), Coordinate(1, 1),};

    for (int i = 0; i < 8; i++) {
        Coordinate position = cell->getPosition()->sum(directions[i]);
        if (this->contains(position)) {
            neighbours.push_back(this->getCell(position));
        }
    }
    cell->setNeighbours(neighbours);
    cell->setNumOfNeighbours(neighbours.size());
}

Cell *Board::nextCell(Cell *cell, Coordinate dir) const {
    int x = dir.getRow();
    int y = dir.getCol();
    return this->getCell(cell->getPosition()->getRow() + x, cell->getPosition()->getCol() + y);
}

bool Board::contains(Coordinate pos) const {
    return (pos.getRow() > 0 && pos.getRow() <= this->size &&
            pos.getCol() > 0 && pos.getCol() <= this->size);
}

int Board::getSize() const {
    return this->size;
}

void Board::applyMove(Move *move, Player *player) {
    Coordinate *pos = move->getCoordinate();
    vector<Coordinate *> directions = move->getDirections();
    this->getCell(*pos)->setContent(move->getContent());
    flipGains(move, player);
}

void Board::flipGains(Move *move, Player *player) {
    vector<Coordinate *> directions;
    for (int i = 0; i < directions.size(); i++) {
        Coordinate dir = *directions[i];
        Cell *next = this->getCell(move->getCoordinate()->sum(dir));
        while (!player->isOpponent(next)) {
            flipCell(next);
            next = this->getCell(next->getPosition()->sum(dir));
        }
    }
}

bool Board::gameOver() const {
    return (blackCells + whiteCells == size * size);
}

