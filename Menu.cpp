/**
 * Barak Talmor
 * 308146240
 */

#include <limits>
#include "Menu.h"

Menu::Menu(Printer *printer) : printer(printer){
}

int Menu::runMenu() const {
    int choice;
    printer->printStream("Choose against who you want to play: \n\t 1. Human \n\t 2. AI\n");
    cin >> choice;
    while (cin.fail() || (choice != 2 && choice != 1)) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        printer->printStream("Wrong choice, try again \n");
        cin >> choice;
    }
    return choice;
}




