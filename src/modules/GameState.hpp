#pragma once

#include "Ball.hpp"
#include "Bar.hpp"
#include "Settings.hpp"

#include <array>

namespace Pong
{
    struct GameState
    {
    public:
        GameState() = default;
        GameState(const Settings& settings);
        const Ball& getBallState() const;
        const Bar& getBarP1() const;
        const Bar& getBarP2() const;
        
        Ball& getBallState();
        Bar& getBarP1();
        Bar& getBarP2();

    public:
        void startGame();

    private:
        void initializePos(const Settings& settings);

    private:
        Ball ballState;
        std::array<Bar, 2> barsState;
    };
} // namespace Pong