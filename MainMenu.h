#ifndef REVERSI_MAINMENU_H
#define REVERSI_MAINMENU_H

#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "NetworkPlayer.h"
#include "ConsolePrinter.h"
#include "GameFlow.h"

class MainMenu {
public:
    MainMenu();
    GameFlow *run();
    ~MainMenu(){}
private:
    /**
     * The method handle printing list of the open rooms
     */
    void printListOfGames(Client *client);
    /**
     * The method handling the client choice
     * @return GameFlow*
     */
    GameFlow *createNetworkGameFlow();
    /**
     * The method handle opening a room
     * @return GameFlow*
     */
    GameFlow *openGame(Client *client);
    /**
     * The method handle joining a room
     * @return GameFlow*
     */
    GameFlow *joinGame(Client *client);
    /**
     * The method builds the message and reading the room name
     * @return char*
     */
    char *buildMessage(string str);
    Printer *printer;
};


#endif //REVERSI_MAINMENU_H
