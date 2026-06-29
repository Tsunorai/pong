#include "Ball.hpp"
#include "Bar.hpp"
#include "GameState.hpp"

#include <iostream>

namespace Pong
{
    void updateBar(Bar& bar)
    {
        float dt = GetFrameTime();

        if (IsKeyDown(bar.keyUp))
        {
            bar.position.y -= bar.speed * dt;
        }

        if (IsKeyDown(bar.keyDown))
        {
            bar.position.y += bar.speed * dt;
        }
    }
    void updateBall(Ball& ball)
    {
        float dt = GetFrameTime();

        std::cout << ball.direction.x << " " << ball.direction.y << " " << ball.speed << std::endl;

        ball.position.x += ball.direction.x * ball.speed * dt;
        ball.position.y += ball.direction.y * ball.speed * dt;
    }

    void update(GameState& state)
    {
        updateBall(state.getBallState());
        updateBar(state.getBarP1());
        updateBar(state.getBarP2());
    }
} // namespace Pong