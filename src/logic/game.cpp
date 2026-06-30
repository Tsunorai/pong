#include "game.hpp"

#include "paint.hpp"
#include "raylib.h"
#include "update.hpp"

namespace Pong
{
    Game::Game()
    {
        InitWindow(settings.windowW, settings.windowH, "Pong");
        settings = Settings();
        state = GameState(settings);
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
