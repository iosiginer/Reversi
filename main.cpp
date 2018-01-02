#include <string>
#include "GameFlow.h"
#include "MainMenu.h"

using namespace std;

int main(int argc, char *argv[]) {
    GameFlow *reversi = NULL;
    do {
        MainMenu menu;
        reversi = menu.run();
        if (reversi) reversi->run();
    } while (reversi != NULL);
    delete(reversi);
}