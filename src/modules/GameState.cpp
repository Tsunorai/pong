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
        ballState = Ball(ballPos, settings.windowH / 50.0f, 500.0f, RAYWHITE);

        float width = settings.windowW / 100.0f;
        float height = settings.windowH / 5.0f;
        Rectangle barP1{settings.windowW - width, settings.windowH / 2 - height / 2.0f, width, height};
        Rectangle barP2{0, settings.windowH / 2 - height / 2.0f, width, height};
        barsState = {
            Bar(barP1, 300.0f, KEY_UP, KEY_DOWN, RAYWHITE),
            Bar(barP2, 300.0f, KEY_W, KEY_S, RAYWHITE)};
    }

    void GameState::startGame()
    {
        ballState.direction.x = GetRandomValue(-100, 100) / 100.0f;
        ballState.direction.y = GetRandomValue(-100, 100) / 100.0f;
    }

} // namespace Pong