#pragma once

#include "raylib.h"

namespace Pong
{
    struct Ball
    {
        Ball() = default;
        Ball(const float x, const float y, const float radius, const float speed, const Color color) : x(x), y(y), speed(speed), radius(radius), color(color) {}
        float x, y;
        Vector2 direction;
        float speed;
        float radius;
        Color color;
    };
} // namespace Pong