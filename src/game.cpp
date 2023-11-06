#include "game.hpp"
#include "utils.hpp"
#include "constants.hpp"

// Constructor
Game::Game() :
    currentTime(utils::hireTimeInSeconds()),
    timeStep(TIME_STEP),
    window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT),
    eventManager(),
    level(window, loadMusic(GAME_MUSIC_PATH)),
    updateManager(eventManager, level),
    renderManager(window, level) {}

// Destructor
Game::~Game()
{
    cleanUp();
}

// Execute the game loop
void Game::run()
{
    // Game loop
    while (eventManager.isGameRunning())
    {
        // Calculate logic game frames beside the rendered frames
        float newTime = utils::hireTimeInSeconds();
        float frameTime = newTime - currentTime;
        currentTime = newTime;
        accumulator += frameTime;

        eventManager.processEvents();

        while (accumulator >= timeStep)
        {
            accumulator -= timeStep;
        }

        renderManager.render();
    }
}

// Clean all ressources
void Game::cleanUp()
{
    // Clean ressources from SDL_mixer
    Mix_CloseAudio();
    // Clean ressources from the rendered window
    window.cleanUp();
    // Clean ressources from SDL_image
    IMG_Quit();
    // Clean ressources from SDL
    SDL_Quit();
}

// Load the game music
Mix_Music *Game::loadMusic(const char *filePath)
{
    Mix_Music *music = Mix_LoadMUS(filePath);
    if (!music)
    {
        std::cerr << "Failed to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }
    return music;
}

// Load a sound
Mix_Chunk *Game::loadSound(const char *filePath)
{
    Mix_Chunk *sound = Mix_LoadWAV(filePath);
    if (!sound)
    {
        std::cerr << "Failed to load sound! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }
    return sound;
}
