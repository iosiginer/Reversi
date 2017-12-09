#include <cstdlib>
#include <cstdio>
#include <limits>
#include "GameFlow.h"
#include "Client.h"
#include "NetworkPlayer.h"


GameFlow::GameFlow(int size, Printer *printer) : printer(printer) {
    this->board = new Board(BLACK, WHITE, 4, printer);
    this->logic = new ClassicLogic();
    this->lastMove = NULL;
    runMenu();
    this->turnManager = new TurnManager(players[0], players[1]);
}

void GameFlow::runMenu() {
    int choice;
    printer->printStream("Choose against who you want to play: \n\t 1. Human \n\t 2. AI\n\t 3. Network\n");
    cin >> choice;
    while (cin.fail() || (choice > 3)) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        printer->printStream("Wrong choice, try again \n");
        cin >> choice;
    }
    switch (choice) {
        case 1:
        default:
            this->players[0] = new HumanPlayer(BLACK, printer);
            this->players[1] = new HumanPlayer(WHITE, printer);
            break;
        case 2:
            this->players[0] = new HumanPlayer(BLACK, printer);
            this->players[1] = new AIPlayer(WHITE, BLACK, board, *logic, printer);
            break;
        case 3:
            static Client *client = new Client("127.0.0.1", 8001);
            try {
                client->connectToServer();
            } catch (const char *msg) {
                throw "Failed to connect to server";
            }
            int turn = client->receiveNumber();
            ostringstream turnStr;
            turnStr << turn;
            printer->printStream("You are player " + turnStr.str() + "\n");
            switch (turn) {
                case 1:
                    this->players[0] = new HumanPlayer(BLACK, printer);
                    this->players[1] = new NetworkPlayer(WHITE, &lastMove, board, *logic, printer, client);
                    break;
                case 2:
                    this->players[1] = new HumanPlayer(WHITE, printer);
                    this->players[0] = new NetworkPlayer(BLACK, &lastMove, board, *logic, printer, client);
                    break;
                default:
                    throw "Can't initialize players!";
            }
    }
}

void GameFlow::playOneTurn() {
    board->print();
    Player *player = turnManager->nextPlayer();
    vector<Move *> possibleMoves = logic->getPossibleMoves(player, board);
    Move *move = player->move(possibleMoves);
    if (move != NULL) {
        turnManager->yesMove();
        if (lastMove) {
            delete(lastMove);
        }
        this->lastMove = move->getCoordinate()->clone();
        board->applyMove(move, player);
    } else {
        turnManager->noMove();
        if (lastMove) { delete(lastMove); }
        (this->lastMove) = new Coordinate(0, 0);
    }
    if (gameOver()) {
        turnManager->nextPlayer()->lasMove();
    }
    bool notInVector = true;
    // delete extra data
    for (int i = 0; i < possibleMoves.size(); i++) {
        if (notInVector && possibleMoves[i]->getCoordinate() == move->getCoordinate()) { notInVector = false; }
        delete possibleMoves[i];
    }
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

