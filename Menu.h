#ifndef REVERSI_MENU_H
#define REVERSI_MENU_H

#include "Printer.h"
#include "GameFlow.h"

class Menu {
public:
    /**
     * Constructor
     */
    Menu(Printer *);
    /**
     * Running the menu and return the choice
     * @return choice
     */
    void runMenu(Player *player1, Player *player2, Board *board, GameLogic &logic) const;
private:
    Printer *printer;
};

#endif //REVERSI_MENU_H
