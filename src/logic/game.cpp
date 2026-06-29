#include "game.hpp"

#include "paint.hpp"
#include "update.hpp"
#include "raylib.h"

#include <print>

namespace Pong
{
    void Game::init()
    {
        state = GameState(settings);
        InitWindow(settings.windowW, settings.windowH, "Pong");
    }

    void Game::run()
    {        
        std::print("Direction");
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
