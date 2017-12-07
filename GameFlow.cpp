#include <cstdlib>
#include <cstdio>
#include <limits>
#include "GameFlow.h"
#include "Client.h"
#include "NetworkPlayer.h"


GameFlow::GameFlow(int size, Printer *printer) : printer(printer) {
    this->board = new Board(BLACK, WHITE, size, printer);
    this->logic = new ClassicLogic();
    this->lastMove = NULL;
    runMenu();
    this->turnManager = new TurnManager(player1, player2);
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
            this->player1 = new HumanPlayer(BLACK, printer);
            this->player2 = new HumanPlayer(WHITE, printer);
            break;
        case 2:
            this->player1 = new HumanPlayer(BLACK, printer);
            this->player2 = new AIPlayer(WHITE, BLACK, board, *logic, printer);
            break;
        case 3:
            Client *client = new Client("127.0.0.1", 8000);
            try {
                client->connectToServer();
            } catch (const char *msg) {
                cout << "Failed to connect to server. Reason:" << msg << endl;
                exit(-1);
            }
            int turn = client->receiveNumber();
            cout << "You are player number " << turn << endl;
            switch (turn) {
                case 1:
                    this->player1 = new HumanPlayer(BLACK, printer);
                    this->player2 = new NetworkPlayer(WHITE, lastMove, board, *logic, printer, client);
                    break;
                case 2:
                    this->player2 = new HumanPlayer(WHITE, printer);
                    this->player1 = new NetworkPlayer(BLACK, lastMove, board, *logic, printer, client);
                    break;
                default:
                    throw "Problem!";
            }
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
        Move *move = player->move(possibleMoves);
        this->lastMove = move;
        board->applyMove(move, player);
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

