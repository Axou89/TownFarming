#pragma once

#include "render_window.hpp"
#include "platform.hpp"

#include <vector>
#include <SDL2/SDL_mixer.h>

class Level
{
public:
    Level(RenderWindow &window, Mix_Music* music);
    ~Level();
    
    void render(RenderWindow &window);

private:
    RenderWindow &window;
    std::vector<Platform> platforms;
    Mix_Music* music;
};
