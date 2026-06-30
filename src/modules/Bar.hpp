#pragma once

#include "raylib.h"

namespace Pong
{
    struct Bar
    {
        Bar() = default;
        Bar(Rectangle rect, const float speed, const int up, const int down, const Color color) : rect(rect), speed(speed), keyUp(up), keyDown(down), color(color) {}
        Rectangle rect;
        float speed;
        int keyUp, keyDown;
        Color color;
    };
} // namespace Pong