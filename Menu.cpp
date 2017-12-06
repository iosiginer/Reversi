#include <limits>
#include "Menu.h"

Menu::Menu(Printer *printer) : printer(printer) {
}

void Menu::runMenu(Player *player1, Player *player2, Board *board, GameLogic &logic) const {
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
            player1 = new HumanPlayer(BLACK, printer);
            player2 = new HumanPlayer(WHITE, printer);
            break;
        case 2:
            player1 = new HumanPlayer(BLACK, printer);
            player2 = new AIPlayer(WHITE, BLACK, board, logic, printer);
            break;
        case 3:
            player1 = new HumanPlayer(BLACK, printer);
            player2 = new HumanPlayer(WHITE, printer);

    }
}
//int Menu::runMenu() const {
//    int choice;
//    printer->printStream("Choose against who you want to play: \n\t 1. Human \n\t 2. AI\n");
//    cin >> choice;
//    while (cin.fail() || (choice != 2 && choice != 1)) {
//        cin.clear();
//        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//        printer->printStream("Wrong choice, try again \n");
//        cin >> choice;
//    }
//    return choice;
//}



