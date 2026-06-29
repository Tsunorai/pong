#include "GameState.hpp"

#include "raylib.h"

namespace Pong
{
    GameState::GameState(const Settings& settings)
    {
        initializePos(settings);
    }

    const Ball& GameState::getBallState() const
    {
        return ballState;
    }
    const Bar& GameState::getBarP1() const
    {
        return barsState[0];
    }
    const Bar& GameState::getBarP2() const
    {
        return barsState[1];
    }

    Ball& GameState::getBallState()
    {
        return ballState;
    }
    Bar& GameState::getBarP1()
    {
        return barsState[0];
    }
    Bar& GameState::getBarP2()
    {
        return barsState[1];
    }

    void GameState::initializePos(const Settings& settings)
    {
        Vector2 ballPos{settings.windowW / 2, settings.windowH / 2};
        ballState = Ball(ballPos, settings.windowH / 50, 400, RAYWHITE);

        int width = settings.windowW / 50;
        int height = settings.windowH / 5;
        Vector2 barPosP1{settings.windowW - width, settings.windowH / 2 - height / 2.0f};
        Vector2 barPosP2{0, settings.windowH / 2 - height / 2.0f};
        barsState = {
            Bar(barPosP1, 200, width, height, KEY_W, KEY_S, RAYWHITE),
            Bar(barPosP2, 200, width, height, KEY_UP, KEY_DOWN, RAYWHITE)};
    }

    void GameState::startGame()
    {
        ballState.direction.x = GetRandomValue(-100, 100) / 100.0f;
        ballState.direction.y = GetRandomValue(-100, 100) / 100.0f;
    }

} // namespace Pong