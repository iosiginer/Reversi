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

MainMenu::~MainMenu() {
    delete printer;
}

GameFlow *MainMenu::run() {
    GameFlow *game = NULL;
    int choice;
    while (game == NULL) {
        printer->printStream("\n\t\t\t\e[1m MAIN MENU \e[0m\n\n");
        printer->printStream(
                "Choose your mode: \n\t 1. Two Players One Screen \n\t 2. Play Against Skynet!\n\t 3. Enjoy the magic of the INTERNET\n\t 0. Exit\n");
        cin >> choice;
        while (cin.fail() || choice > 3 || choice < 0) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printer->printStream("Wrong choice, try again\n");
            cin >> choice;
        }
        switch (choice) {
            case 1:
                game = new GameFlow(BOARD_SIZE, printer, HUMAN_VS_HUMAN);
                break;
            case 2:
                game = new GameFlow(BOARD_SIZE, printer, HUMAN_VS_AI);
                break;
            case 3:
                game = this->createNetworkGameFlow();
                break;
            case 0:
                return NULL;    //and thus exit the game
            default:
                printer->printStream("Wrong choice, try again\n");
        }
    }
    return game;
}


GameFlow *MainMenu::createNetworkGameFlow() {
    GameFlow *game = NULL;
    int choice;
    Client *client = new Client(printer);
    while (game == NULL) {
        try {
            client->connectToServer();
        } catch (const runtime_error &error) {
            printer->printStream("\nThe server seems to be down. Try a different mode instead.\n");
            delete(client);
            return NULL;
        }
        printer->printStream("Pick your poison:\n\t1.\tOpen a new game\n\t"
                                     "2.\tJoin an existing game\n\t3.\tPrint available games\n\t0.\tGo Back\n");
        cin >> choice;
        while (cin.fail() || choice > 3 || choice < 0) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printer->printStream("Wrong choice, try again \n");
            cin >> choice;
        }
        switch (choice) {
            case 1:
                return openGame(client);
            case 2:
                game = joinGame(client);
                break;
            case 3:
                printListOfGames(client);
                break;
            case 0:
                delete(client);
                return NULL;
            default:
                printer->printStream("Wrong choice, try again\n");
        }
    }
    return game;
}

void MainMenu::printListOfGames(Client *client) {
    string listOfGames = "list_games";
    client->send(listOfGames);
    string list = client->receive();
    printer->printStream(list);

}

GameFlow *MainMenu::openGame(Client *client) {
    string message = "start ", fullMessage;
    printer->printStream("Please enter the name of the room you want to open:\n");
    fullMessage = buildMessage(message);
    client->send(fullMessage);
    string num = client->receive();
    if (strcmp("1", num.c_str()) == 0) {
        cout << "starting room " << fullMessage << endl;
        return new GameFlow(BOARD_SIZE, printer, HUMAN_VS_NETWORK, client);
    } else {
        cout << "Could not open game." << endl;
        return NULL;
    }
}

GameFlow *MainMenu::joinGame(Client *client) {
    string message = "join ", fullMessage;
    printer->printStream("Please enter the name of the room you want to join:\n");
    fullMessage = buildMessage(message);
    client->send(fullMessage);
    string num = client->receive();
    if (strcmp("2", num.c_str()) == 0) {
        return new GameFlow(BOARD_SIZE, printer, NETWORK_VS_HUMAN, client);
    } else {
        printer->printStream("There is no room with that name, please try again.\n");
        return NULL;
    }
}

string MainMenu::buildMessage(string str) {
    string newStr(str), roomName;
    cin.ignore();
    getline(cin, roomName);
    newStr.append(roomName);
    return newStr;
}