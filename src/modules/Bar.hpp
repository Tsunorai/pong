#pragma once

#include "raylib.h"

namespace Pong
{
    struct Bar
    {
        Bar() = default;
        Bar(Vector2 position, const float speed, const float width, const float height, const int up, const int down, const Color color) : position(position), speed(speed), width(width), height(height), keyUp(up), keyDown(down), color(color) {}
        Vector2 position;
        float speed;
        int width, height;
        int keyUp, keyDown;
        Color color;
    };
} // namespace Pong