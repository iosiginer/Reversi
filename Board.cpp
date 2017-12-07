#include "Board.h"

Board::Board(Color color1, Color color2, int size, Printer *printer, CellCounter *counter) : size(size),
                                                                                             counter(counter),
                                                                                             printer(printer) {
    this->matrix = new Cell **[size];
    this->colorP1 = color1;
    this->colorP2 = color2;
    for (int row = 0; row < size; row++) {
        this->matrix[row] = new Cell *[size];
        for (int col = 0; col < size; col++) {
            Coordinate *coordinate = new Coordinate(row + 1, col + 1);
            vector<Coordinate> neighbours = getNeighbours(row, col);
            this->matrix[row][col] = new Cell(coordinate, counter, neighbours);
        }
    }
    int middle = size / 2;
    matrix[middle][middle - 1]->setContent(colorP1);
    matrix[middle - 1][middle]->setContent(colorP1);
    matrix[middle][middle]->setContent(colorP2);
    matrix[middle - 1][middle - 1]->setContent(colorP2);
}

void Board::print() const {
    this->printer->printBoard(matrix, size, getPoints());
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
    int maxNeighbours = 8;
    vector<Coordinate> neighbours;
    Coordinate coor = Coordinate(row + 1, column + 1);
    Coordinate directions[] = {Coordinate(-1, -1), Coordinate(-1, 0), Coordinate(-1, 1), Coordinate(0, -1),
                               Coordinate(0, 1), Coordinate(1, -1), Coordinate(1, 0), Coordinate(1, 1),};

    for (int i = 0; i < maxNeighbours; i++) {
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
    // No move was made, so the Board got the move (0, 0).
    if (pos->getRow() == 0 && pos->getCol() == 0) {
        return;
    }
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

string Board::getPoints() const {
    ostringstream p1Convert;
    ostringstream p2Convert;
    p1Convert << counter->getPoints1();
    p2Convert << counter->getPoints2();
    return "Points: Player 1: " + p1Convert.str() + " vs. Player 2: " + p2Convert.str();
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
}

Board *Board::clone() const {
    Board *cloneBoard = new Board(colorP1, colorP2, this->size, printer, this->counter->clone());
    for (int row = 1; row <= size; row++) {
        for (int col = 1; col <= size; col++) {
            cloneBoard->getCell(row, col)->setContent(this->getCell(row, col)->getContent());
        }
    }
    return cloneBoard;
}
