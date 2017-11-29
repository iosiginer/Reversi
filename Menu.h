#ifndef REVERSI_MENU_H
#define REVERSI_MENU_H

#include "Printer.h"

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
    int runMenu() const;
private:
    Printer *printer;
};

#endif //REVERSI_MENU_H
