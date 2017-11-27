/**
 * Josef Ginerman 332494830
 * Barak Talmor 308146240
 */

#include "Board.h"
#include "BoardConsolePrinter.h"

Board::Board(int size, char play1, char play2) : size(size) {
    this->matrix = new Cell **[size];
    this->counter = new CellCounter(play1, play2);
    this->printer = new BoardConsolePrinter();
    initialize(play1, play2, counter);
}

Board::Board(int size, char play1, char play2, CellCounter *counter) : size(size) {
    this->matrix = new Cell **[size];
    this->printer = new BoardConsolePrinter();
    this->counter = counter;
    initialize(play1, play2, counter);
}


void Board::initialize(char play1, char play2, CellCounter *counter) {
    for (int row = 0; row < size; row++) {
        this->matrix[row] = new Cell *[size];
        for (int col = 0; col < size; col++) {
            this->matrix[row][col] = new Cell(new Coordinate(row + 1, col + 1), counter, getNeighbours(row, col));
        }
    }
    int middle = size / 2;
    matrix[middle][middle - 1]->setContent(play1);
    matrix[middle - 1][middle]->setContent(play1);
    matrix[middle][middle]->setContent(play2);
    matrix[middle - 1][middle - 1]->setContent(play2);
}


void Board::print() const {
    this->printer->print(matrix, size, getPoints());
}

Cell *Board::getCell(Coordinate pos) const {
    int row = pos.getRow();
    int col = pos.getCol();
    return getCell(row, col);
}

Cell *Board::getCell(int row, int col) const {
    return this->matrix[row - 1][col - 1];
}

vector<Coordinate> Board::getNeighbours(int row, int column) {
    vector<Coordinate> neighbours;
    Coordinate coor = Coordinate(row + 1, column + 1);
    Coordinate directions[] = {Coordinate(-1, -1), Coordinate(-1, 0), Coordinate(-1, 1), Coordinate(0, -1),
                               Coordinate(0, 1), Coordinate(1, -1), Coordinate(1, 0), Coordinate(1, 1),};

    for (int i = 0; i < 8; i++) {
        Coordinate position = coor.sum(&directions[i]);
        if (this->contains(position)) {
            neighbours.push_back(position);
        }
    }
    return neighbours;
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
    player->conquerCell(this->getCell(*pos));
    vector<Coordinate *> directions = move->getDirections();
    for (int i = 0; i < directions.size(); i++) {
        Coordinate *dir = directions[i];
        flipGains(pos, player, dir);
    }
}


void Board::flipGains(Coordinate *position, Player *player, Coordinate *direction) {
    Cell *next = getCell(position->sum(direction));
    if (player->isOpponent(next->getContent())) {
        player->conquerCell(next);
        flipGains(next->getPosition(), player, direction);
    }
}

bool Board::gameOver() const {
    return counter->gameOver(size);
}

int Board::getWinner() const {
    return counter->getWinner();
}

int Board::getPlayer1Points() const {
    return counter->getPoints1();
}

int Board::getPlayer2Points() const {
    return counter->getPoints2();
}

int Board::getPoints() const {
    return counter->getPoints1() - counter->getPoints2();
}

Board::~Board() {
    delete counter;
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            delete matrix[row][col];
        }
        delete[] matrix[row];
    }
    delete[] matrix;
    delete printer;
}

Board* Board::clone() const {
    Board *cloneBoard = new Board(this->size, ' ', ' ', this->counter->clone());
    for (int row = 1; row <= size; row++) {
        for (int col = 1; col <= size; col++) {
            cloneBoard->getCell(row, col)->setContent(this->getCell(row, col)->getContent());
        }
    }
    return cloneBoard;
}
