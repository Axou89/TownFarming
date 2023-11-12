#include <iostream>

#include "game.hpp"

// Initialize all SDL2 libraries
bool initSDL()
{
    // Initialize SDL2
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Initialize SDL2_image
    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cerr << "IMG_Init Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    // Initialize SDL Audio
    if (SDL_Init(SDL_INIT_AUDIO) < 0)
    {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Initialize SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        std::cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return false;
    }

    // Initialize SDL_ttf
    if (TTF_Init() < 0)
    {
        std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
        return false;
    }

    return true;
}

// Main game function
int runGame()
{
    if (!initSDL())
        return 1;

    Game game;
    game.run();

    return 0;
}

// Main program function
int main(int argc, char *argv[])
{
    return runGame();
}