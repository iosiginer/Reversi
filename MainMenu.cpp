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
    int choice;
    Client *client = new Client(printer);
    while (true) {
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
                return openGame(client);
            case 2:
                return joinGame(client);
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
    string listOfGames = "list_games";
    client->send(listOfGames);
    string list = client->receive();
    printer->printStream(list);

}

GameFlow *MainMenu::openGame(Client *client) {
    string message = "start ", fullMessage;
    printer->printStream("Please enter the name of the room you want to open\n");
    fullMessage = buildMessage(message);
    client->send(fullMessage);
    string num = client->receive();
    message = "I received" + num + "and that's it\n";
    if (strcmp("1", num.c_str()) == 0) {
        return new GameFlow(BOARD_SIZE, printer, HUMAN_VS_NETWORK, client);
    } else {
        cout << "Could not open game." << endl;
        return NULL;
    }
}

GameFlow *MainMenu::joinGame(Client *client) {
    string message = "join ", fullMessage;
    printer->printStream("Please enter the name of the room you want to join\n");
    fullMessage = buildMessage(message);
    cout << fullMessage << endl;
    client->send(fullMessage);
    string num = client->receive();
    message = "I received" + num + "and that's it\n";
    printer->printStream(message);
    if (strcmp("2", num.c_str()) == 0) {
        return new GameFlow(BOARD_SIZE, printer, NETWORK_VS_HUMAN, client);
    } else {
        printer->printStream("Joining the room was failed\n");
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