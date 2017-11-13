#include <string>
#include "GameFlow.h"

using namespace std;

int main(int argc, char *argv[]) {
    char p1 = 'B';
    char p2 = 'I';
    int size = 8;
    if (argc > 1) {
        p1 = *argv[1];
        p2 = *argv[2];
        istringstream(argv[3]) >> size;
    }
    GameFlow reversi(p1, p2, size);
    reversi.run();
}