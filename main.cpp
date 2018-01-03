#include <string>
#include "GameFlow.h"
#include "MainMenu.h"
#include <signal.h>

using namespace std;
void start(int signum) {
    cout << "here";
}

int main(int argc, char *argv[]) {
    struct sigaction sigUserHandler;
    sigset_t blocked;
    sigemptyset(&blocked);
    sigUserHandler.sa_handler = start;
    sigUserHandler.sa_mask = blocked;
    sigUserHandler.sa_flags = 0;

    sigaction(SIGPIPE, &sigUserHandler, NULL);

    GameFlow *reversi = NULL;
    do {
        MainMenu menu;
        reversi = menu.run();
        if (reversi) {
            reversi->run();
            delete (reversi);
            break;
        }
    } while (reversi != NULL);
}