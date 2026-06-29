#include "game.hpp"

int main(void)
{

    Pong::Game game;
    game.init();
    game.run();
    game.clean();

    return 0;
}