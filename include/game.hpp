#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include "event_manager.hpp"
#include "update_manager.hpp"
#include "render_manager.hpp"
#include "render_window.hpp"
#include "level.hpp"

class Game
{
public:
    Game();
    ~Game();

    void run();
    Mix_Music* loadMusic(const char *filePath);
    Mix_Chunk* loadSound(const char *filePath);

private:
    void cleanUp();

    // Members for the calculation of the game logic frames
    float currentTime, accumulator{0.0f}, timeStep;
    RenderWindow window;
    EventManager eventManager;
    UpdateManager updateManager;
    RenderManager renderManager;
    Level level;
};
