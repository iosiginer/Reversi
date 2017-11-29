#include <cstdlib>
#include <cstdio>
#include "GameFlow.h"
#include "Menu.h"


GameFlow::GameFlow(char first, char second, int size, Printer *printer) : printer(printer) {
    this->board = new Board(size, first, second, printer);
    this->logic = new ClassicLogic();
    this->player1 = new HumanPlayer(first, printer);
    initPlayer2(first, second);
    this->player1Turn = true;
    this->noMove = false;
    this->noMoreMoves = false;
}

void GameFlow::initPlayer2(char first, char second) {
    Menu menu(printer);
    if ((menu.runMenu()) == 1) {
        cout << "here";
        this->player2 = new HumanPlayer(second, printer);
    } else {
        this->player2 = new AIPlayer(second, first, board, *this->logic, printer);
    }
}

void GameFlow::playOneTurn() {
    board->print();
    Player *player;
    if (player1Turn) {
        printer->printStream("Player 1 it's your turn!\n");
        player = player1;
        this->player1Turn = false;
    } else {
        printer->printStream("Player 2 it's your turn!\n");
        player = player2;
        this->player1Turn = true;
    }
    vector<Move *> possibleMoves = logic->getPossibleMoves(player, board);
    if (possibleMoves.empty()) {
        if (!noMove) {
            noMove = true;
        } else {
            noMoreMoves = true;
        }
        printer->printStream("No possible moves. Play passes back to the other player."
                                     " Press any key to continue.\n");
        char c = static_cast<char>(getchar());
    } else {
        noMove = false;
        board->applyMove(player->move(possibleMoves), player);
        for (int i = 0; i < possibleMoves.size(); i++) { delete possibleMoves[i]; }
    }
}

void GameFlow::run() {
    while (!board->gameOver() && !noMoreMoves) {
        playOneTurn();
    }
    gameOver();
}

void GameFlow::gameOver() const {
    board->print();
    int winner = board->getWinner();
    if (0 == winner) {
        printer->printStream("It's a tie!!\n");
    } else {
        int points1 = board->getPlayer1Points();
        int points2 = board->getPlayer2Points();
        ostringstream win, maxPoint, minPoint;
        win << winner;
        maxPoint << max(points1,points2);
        minPoint << min(points1,points2);
        printer->printStream("Player " + win.str() + " has won with a score of " +
                                     maxPoint.str() + " against " + minPoint.str() + "\n");
    }
}

GameFlow::~GameFlow() {
    delete player1;
    delete player2;
    delete logic;
    delete board;
    delete printer;
}
