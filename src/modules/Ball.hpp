#pragma once

#include "raylib.h"

namespace Pong
{
    struct Ball
    {
        Ball() = default;
        Ball(const Vector2 position, const float radius, const float speed, const Color color) : position(position), speed(speed), radius(radius), color(color) {}
        Vector2 position;
        Vector2 direction;
        float speed;
        float radius;
        Color color;
    };
} // namespace Pong