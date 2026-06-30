#include "Settings.hpp"
#include <raylib.h>

namespace Pong
{
    Settings::Settings()
    {
        int monitor = GetCurrentMonitor();
        int newWindowW = GetMonitorWidth(monitor);
        int newWindowH = GetMonitorHeight(monitor);

        if (newWindowW > 0)
        {
            windowW = newWindowW;
        }

        if (newWindowH > 0)
        {
            windowH = newWindowH;
        }
    }
} // namespace Pong