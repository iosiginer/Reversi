/**
 * Josef Ginerman 332494830
 * Barak Talmor 308146240
 */

#include <cstdlib>
#include <cstdio>
#include "GameFlow.h"


GameFlow::GameFlow(char first, char second, int size) {
    this->board = new Board(size, first, second);
    this->logic = new ClassicLogic();
    this->player1 = new HumanPlayer(first);
    initPlayer2(first, second);
    this->player1Turn = true;
    this->noMove = false;
    this->noMoreMoves = false;
}

void GameFlow::initPlayer2(char first, char second) {
    int choice;
    cout << "Choose against who you want to play: \n\t 1. Human \n\t 2. AI" << endl;
    cin >> choice;
    if (choice == 1) {
        this->player2 = new HumanPlayer(second);
    } else {
        this->player2 = new AIPlayer(second, first, board, *this->logic);
    }
}

void GameFlow::playOneTurn() {
    board->print();
    Player *player;
    if (player1Turn) {
        cout << "Player 1 it's your turn!" << endl;
        player = player1;
        this->player1Turn = false;
    } else {
        cout << "Player 2 it's your turn!" << endl;
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
        cout << "No possible moves. Play passes back to the other player. Press any key to continue." << endl;
        char c = static_cast<char>(getchar());
        cout << c;
        cout << c;
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
        cout << "It's a tie!!" << endl;
    } else {
        int points1 = board->getPlayer1Points();
        int points2 = board->getPlayer2Points();
        cout << "Player " << winner << " has won. With a score of " << max(points1, points2) << " against " <<
             min(points1, points2) << endl;
    }
}

GameFlow::~GameFlow() {
    delete player1;
    delete player2;
    delete logic;
    delete board;
}