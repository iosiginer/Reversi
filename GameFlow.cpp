#include <cstdlib>
#include "GameFlow.h"
#include "NetworkPlayer.h"

GameFlow::GameFlow(int size, Printer *printer, int typeOfGames, Client *client) : printer(printer) {
    CellCounter *counter = new CellCounter();
    this->board = new Board(BLACK, WHITE, 4, printer, counter);
    this->logic = new ClassicLogic();
    this->lastMove = NULL;
    switch (typeOfGames) {
        case 1:
            this->players[0] = new HumanPlayer(BLACK, printer);
            this->players[1] = new NetworkPlayer(WHITE, &lastMove, board, *logic, printer, client);
            break;
        case 2:
            this->players[0] = new NetworkPlayer(BLACK, &lastMove, board, *logic, printer, client);
            this->players[1] = new HumanPlayer(WHITE, printer);
            break;
        default:
            throw "Can't initialize players!";
    }
    this->turnManager = new TurnManager(players[0], players[1]);
}

GameFlow::GameFlow(int size, Printer *printer,int typeOfGame) : printer(printer) {
    CellCounter *counter = new CellCounter();
    this->board = new Board(BLACK, WHITE, 4, printer, counter);
    this->logic = new ClassicLogic();
    this->lastMove = NULL;
    switch (typeOfGame) {
        case 1:
            this->players[0] = new HumanPlayer(BLACK, printer);
            this->players[1] = new HumanPlayer(WHITE, printer);
            break;
        case 2:
            this->players[0] = new HumanPlayer(BLACK, printer);
            this->players[1] = new AIPlayer(WHITE, BLACK, board, *logic, printer);
            break;
        default:
            throw "Can't initialize players!";
    }
    this->turnManager = new TurnManager(players[0], players[1]);
}

void GameFlow::playOneTurn() {
    board->print();
    Player *player = turnManager->nextPlayer();
    vector<Move *> possibleMoves = logic->getPossibleMoves(player, board);
    Move *move = player->move(possibleMoves);
    if (lastMove) { delete (lastMove); }
    if (move != NULL) {
        if (*(move->getCoordinate()) == Coordinate(-1, -1)) {
            deletePossibleMoves(possibleMoves, move);
            this->~GameFlow();
            exit(0);
        }
        turnManager->yesMove();
        this->lastMove = move->getCoordinate()->clone();
        board->applyMove(move, player);
    } else {
        turnManager->noMove();
        (this->lastMove) = new Coordinate(0, 0);
    }
    if (gameOver()) {
        turnManager->nextPlayer()->playLastMove();
    }
    deletePossibleMoves(possibleMoves, move);
}

void GameFlow::deletePossibleMoves(vector<Move *> &possibleMoves, Move *move) {
    bool notInVector = true;
    // delete extra data
    for (int i = 0; i < possibleMoves.size(); i++) {
        if (notInVector && (possibleMoves[i]->getCoordinate() == move->getCoordinate())) {
            notInVector = false;
        }
        delete possibleMoves[i];
    }
    possibleMoves.clear();
    if(notInVector && move) {
        delete move;
    }
}

void GameFlow::run() {
    while (!gameOver()) {
        playOneTurn();
    }
    delete lastMove;
    finishGame();
}

void GameFlow::finishGame() const {
    board->print();
    int winner = board->getWinner();
    if (0 == winner) {
        printer->printStream("It's a tie!!\n");
    } else {
        int points1 = board->getPlayer1Points();
        int points2 = board->getPlayer2Points();
        ostringstream win, maxPoint, minPoint;
        win << winner;
        maxPoint << max(points1, points2);
        minPoint << min(points1, points2);
        printer->printStream("Player " + win.str() + " has won with a score of " +
                             maxPoint.str() + " against " + minPoint.str() + "\n");
    }
}

GameFlow::~GameFlow() {
    delete players[0];
    delete players[1];
    delete logic;
    delete board;
    delete printer;
    delete turnManager;
}

bool GameFlow::gameOver() const {
    return (board->gameOver() || turnManager->noMoreMoves());
}