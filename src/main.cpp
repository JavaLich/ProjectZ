#include "Game.h"

#include <iostream>

int main() {
    Game* game = new Game();
    game->init();
    game->run();

    delete game;

    return 0;
}
