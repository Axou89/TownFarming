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

    std::vector<Entity> getEntities() { return entities; }
    
    void render(RenderWindow &window);
    // Update 
    void update();

private:
    RenderWindow &window;
    std::vector<Platform> platforms;
    Mix_Music* music;
    std::vector<Entity> entities;
};
