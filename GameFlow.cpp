#include <cstdlib>
#include <cstdio>
#include "GameFlow.h"
#include "Menu.h"


GameFlow::GameFlow(int size, Printer *printer) : printer(printer) {
    this->board = new Board(BLACK, WHITE, size, printer);
    this->logic = new ClassicLogic();
    this->player1 = new HumanPlayer(BLACK, printer);
    initPlayer2(BLACK, WHITE);
    // Menu menu(printer);
    // menu.runMenu(player1, player2, board, *logic);
    this->turnManager = new TurnManager(player1, player2);
}

void GameFlow::initPlayer2(Color first, Color second) {
    Menu menu(printer);
    if ((menu.runMenu()) == 1) {
        this->player2 = new HumanPlayer(second, printer);
    } else {
        this->player2 = new AIPlayer(second, first, board, *this->logic, printer);
    }
}

void GameFlow::playOneTurn() {
    board->print();
    Player *player = turnManager->nextPlayer();
    vector<Move *> possibleMoves = logic->getPossibleMoves(player, board);
    if (possibleMoves.empty()) {
        turnManager->noMove();
        printer->printStream("No possible moves. Play passes back to the other player."
                                     " Press any key to continue.\n");
        char c = static_cast<char>(getchar());
    } else {
        turnManager->yesMove();
        board->applyMove(player->move(possibleMoves), player);
        // delete extra data
        for (int i = 0; i < possibleMoves.size(); i++) { delete possibleMoves[i]; }
    }
}

void GameFlow::run() {
    while (!(board->gameOver() || turnManager->noMoreMoves())) {
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
        maxPoint << max(points1, points2);
        minPoint << min(points1, points2);
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

