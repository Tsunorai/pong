#pragma once

#include "GameState.hpp"
#include "Settings.hpp"

namespace Pong
{
    class Game
    {
    public:
        void init();
        void run();
        void clean();

    private:
        Settings settings;
        GameState state{settings};
    };
} // namespace Pong