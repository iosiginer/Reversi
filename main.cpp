#include <string>
#include "GameFlow.h"
#include "MainMenu.h"

using namespace std;

int main(int argc, char *argv[]) {
    MainMenu menu;
    GameFlow *reversi = menu.run();
    reversi->run();
    delete(reversi);
}