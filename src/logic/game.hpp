#pragma once

#include "GameState.hpp"
#include "Settings.hpp"

namespace Pong
{
    class Game
    {
    public:
        Game();
        void run();
        void clean();

    private:
        Settings settings;
        GameState state;
    };
} // namespace Pong