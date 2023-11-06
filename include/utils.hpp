#pragma once

#include <SDL2/SDL.h>

namespace utils
{
    // Return the time since the launching of the game in seconds
    inline float hireTimeInSeconds()
    {
        // Get the time since the launching of the game in milliseconds
        float t = SDL_GetTicks();
        // Convert the time in seconds
        t *= 0.001f;

        return t;
    }
}
