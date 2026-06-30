#include "paint.hpp"

#include "raylib.h"

namespace Pong
{
    void paintBackground(const Color& color)
    {
        ClearBackground(color);
    }
    void paintBall(const Ball& ball)
    {
        DrawCircleV(ball.position, ball.radius, ball.color);
    }
    void paintBar(const Bar& bar)
    {
        DrawRectangleRec(bar.rect, bar.color);
    }

    void paintGame(const GameState& state)
    {
        BeginDrawing();
        paintBackground(BLACK);
        paintBall(state.getBallState());
        paintBar(state.getBarP1());
        paintBar(state.getBarP2());
        EndDrawing();
    }
} // namespace Pong