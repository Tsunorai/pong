#pragma once

#include "Ball.hpp"
#include "Bar.hpp"
#include "GameState.hpp"

namespace Pong
{

    void paintBackground(const Color& color);
    void paintBall(const Ball& ball);
    void paintBar(const Ball& bar);

    void paintGame(const GameState& state);
} // namespace Pong