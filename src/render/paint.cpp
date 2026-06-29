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
        DrawCircle(static_cast<int>(ball.position.x), static_cast<int>(ball.position.y), ball.radius, ball.color);
    }
    void paintBar(const Bar& bar)
    {
        DrawRectangle(static_cast<int>(bar.position.x), static_cast<int>(bar.position.y), bar.width, bar.height, bar.color);
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