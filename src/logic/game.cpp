#include "game.hpp"

#include "paint.hpp"
#include "raylib.h"
#include "update.hpp"

namespace Pong
{
    void Game::init()
    {
        InitWindow(settings.windowW, settings.windowH, "Pong");
    }

    void Game::run()
    {
        state.startGame();
        while (!WindowShouldClose())
        {
            update(state);
            paintGame(state);
        }
    }

    void Game::clean()
    {
        CloseWindow();
    }
} // namespace Pong
