#include "MainMenu.h"
#include <limits>

#define BOARD_SIZE 8
#define HUMAN_VS_HUMAN 1
#define HUMAN_VS_AI 2
#define HUMAN_VS_NETWORK 1
#define NETWORK_VS_HUMAN 2

using namespace std;

MainMenu::MainMenu() {
    printer = new ConsolePrinter();
}

GameFlow *MainMenu::run() {
    int choice;
    printer->printStream("Choose against who you want to play: \n\t 1. Human \n\t 2. AI\n\t 3. Network\n");
    while (true) {
        cin >> choice;
        while (cin.fail() || (choice > 3)) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printer->printStream("Wrong choice, try again \n");
            cin >> choice;
        }
        switch (choice) {
            case 1:
                return new GameFlow(BOARD_SIZE, printer, HUMAN_VS_HUMAN);
            case 2:
                return new GameFlow(BOARD_SIZE, printer, HUMAN_VS_AI);
            case 3:
                return this->createNetworkGameFlow();
            default:
                printer->printStream("Try again...\n");
        }
    }
}


GameFlow *MainMenu::createNetworkGameFlow() {
    GameFlow *game = NULL;
    int choice;
    Client *client = new Client(printer);
    while (NULL == game) {
        try {
            client->connectToServer();
        } catch (const char *msg) {
            throw "Failed to connect to server";
        }
        printer->printStream("Choose the next option:\n\t1.\tOpen new room\n\t"
                                     "2.\tJoin a room\n\t3.\tPrint list of open rooms\n\t");
        cin >> choice;
        switch (choice) {
            case 1:
//                openGame(client);
                game = openGame(client);
                break;
            case 2:
                game = joinGame(client);
                break;
            case 3:
                printListOfGames(client);
                break;
            default:
                printer->printStream("Try again...\n");
                cin >> choice;
                break;
        }
    }
}

void MainMenu::printListOfGames(Client *client) {
    char listOfGames[] = "list_games";
    cout << sizeof(listOfGames);
    client->send(listOfGames);
    char *list = client->receive();
    printer->printStream(list);
}

GameFlow *MainMenu::openGame(Client *client) {
    string roomName, str = "start ";
    printer->printStream("Please enter the name of the room you want to open\n");
    char *message = b