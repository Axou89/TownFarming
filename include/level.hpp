#pragma once

#include "render_window.hpp"
#include "platform.hpp"
#include "zone.hpp"

#include <vector>
#include <SDL2/SDL_mixer.h>

class Level
{
public:
    Level(RenderWindow &window, Mix_Music* music);
    ~Level();

    std::vector<Zone> getZones() { return zones; }
    
    void render(RenderWindow &window);
    // Update 
    void update();

private:
    RenderWindow &window;
    std::vector<Platform> platforms;
    Mix_Music* music;
    std::vector<Zone> zones;
};
