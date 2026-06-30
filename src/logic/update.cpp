#include "Ball.hpp"
#include "Bar.hpp"
#include "GameState.hpp"

namespace Pong
{
    void updateBar(Bar& bar)
    {
        float dt = GetFrameTime();

        if (IsKeyDown(bar.keyUp))
        {
            bar.rect.y -= bar.speed * dt;
        }

        if (IsKeyDown(bar.keyDown))
        {
            bar.rect.y += bar.speed * dt;
        }
    }
    void updateBall(GameState& state)
    {
        Ball& ball = state.getBallState();

        float dt = GetFrameTime();

        ball.position.x += ball.direction.x * ball.speed * dt;
        ball.position.y += ball.direction.y * ball.speed * dt;
    }

    void update(GameState& state)
    {
        updateBall(state);
        updateBar(state.getBarP1());
        updateBar(state.getBarP2());
    }
} // namespace Pong