#pragma once

#include "raylib.h"

namespace Pong
{
    struct Bar
    {
        Bar() = default;
        Bar(const float x, const float y, const float speed, const float width, const float height, const int up, const int down, const Color color) : x(x), y(y), speed(speed), width(width), height(height), keyUp(up), keyDown(down), color(color) {}
        float x, y, speed;
        int width, height;
        int keyUp, keyDown;
        Color color;
    };
} // namespace Pong