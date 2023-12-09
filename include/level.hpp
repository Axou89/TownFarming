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

    // Create a new zone
    void createZone(SDL_Texture* texture, int frameWidth, int frameHeight,
        std::pair<int, int> spriteSheetConfiguration, std::string zoneType);

    void cleanUp();

private:
    RenderWindow &window;
    std::vector<Platform> platforms;
    Mix_Music* music;
    std::vector<Zone> zones;
};
