//
// Created by iosi on 10/11/17.
//

#include "BoardConsolePrinter.h"

BoardConsolePrinter::BoardConsolePrinter() {}

void BoardConsolePrinter::print(Cell ***board, int size, string message) const {
    cout << endl;
    cout << "\e[1mCurrent Board:" << endl;
    for (int row = 0; row <= size; row++) {
        for (int col = 0; col <= size; col++) {
            if (row == 0) {
                if (col == 0) { cout << " |"; }
                else { cout << " " << col << " |"; }
            } else if (col == 0) { cout << row << "|"; }
            else { cout << board[row - 1][col - 1]->toString(); }
        }
        if (row == size / 2) { cout << "\t" << message; }
        cout << endl;
        for (int i = 0; i < size * 2 + 1; i++) { cout << "--"; };
        cout << endl;
    }
    cout << " \e[0m";
}
