#include "Ball.hpp"
#include "Bar.hpp"
#include "GameState.hpp"
#include <math.h>
#include <iostream>
#include <raylib.h>

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
        Bar& barP1 = state.getBarP1();
        Bar& barP2 = state.getBarP2();

        float dt = GetFrameTime();

        ball.position.x += ball.direction.x * ball.speed * dt;
        ball.position.y += ball.direction.y * ball.speed * dt;

        bool collisionP1 = CheckCollisionCircleRec(ball.position, ball.radius, barP1.rect);
        bool collisionP2 = CheckCollisionCircleRec(ball.position, ball.radius, barP2.rect);
        bool collisionWallLeft = CheckCollisionCircleLine(ball.position, ball.radius, {0, 0}, {0, static_cast<float>(GetScreenHeight())});
        bool collisionWallRight = CheckCollisionCircleLine(ball.position, ball.radius, {static_cast<float>(GetScreenWidth()), 0}, {static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight())});

        if (collisionP1)
        {
            ball.position.x = barP1.rect.x - ball.radius;
            ball.direction.x *= -1;
            ball.speed *= 1.05f;
        }

        if (collisionP2)
        {
            ball.position.x = barP2.rect.x + barP2.rect.width + ball.radius;
            ball.direction.x *= -1;
            ball.speed *= 1.05f;
        }

        if (collisionWallLeft || collisionWallRight)
        {
            ball.position = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
        }

        if (ball.position.y - ball.radius <= 0)
        {
            ball.position.y = ball.radius;
            ball.direction.y = std::abs(ball.direction.y);
        }

        if (ball.position.y + ball.radius >= GetScreenHeight())
        {
            ball.position.y = GetScreenHeight() - ball.radius;
            ball.direction.y = -std::abs(ball.direction.y);
        }

        std::cout << "Ball position: (" << ball.position.x << ", " << ball.position.y << ")\n";
    }

    void update(GameState& state)
    {
        updateBall(state);
        updateBar(state.getBarP1());
        updateBar(state.getBarP2());
    }
} // namespace Pong