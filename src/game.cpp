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
    player(player),
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
    // Overlay constants
    TTF_Font *font = utils::loadFont(FONT_PATH, 24);
    SDL_Renderer *renderer = window.getRenderer();

    int lastAction = 0;

    // Game loop
    while (eventManager.isGameRunning())
    {
        // Calculate logic game frames beside the rendered frames
        float newTime = utils::hireTimeInSeconds();
        float frameTime = newTime - currentTime;
        currentTime = newTime;
        accumulator += frameTime;
        int timer = int(currentTime);

        eventManager.processEvents(player, window, level);

        while (accumulator >= timeStep)
        {
            accumulator -= timeStep;
        }

        // Perform action each second
        if (timer - lastAction >= 1)
        {
            player.addLog();
            player.addCoal();
            player.addCarrot();
            lastAction = timer;
        }

        renderManager.render();

        // Display static text
        utils::RenderText(font, renderer, "Timer", 32, 16);

        // Update timer text
        utils::RenderText(font, renderer, std::to_string(timer).c_str(), 48, 48);

        // Update log quantity text
        utils::RenderText(font, renderer, std::to_string(player.getLog()).c_str(), 48, 144);
        // Update honey quantity text
        utils::RenderText(font, renderer, std::to_string(player.getHoney()).c_str(), 48, 240);
        // Update coal quantity text
        utils::RenderText(font, renderer, std::to_string(player.getCoal()).c_str(), 48, 336);
        // Update iron quantity text
        utils::RenderText(font, renderer, std::to_string(player.getIron()).c_str(), 48, 432);
        // Update carrot quantity text
        utils::RenderText(font, renderer, std::to_string(player.getCarrot()).c_str(), 48, 528);
        // Update salad quantity text
        utils::RenderText(font, renderer, std::to_string(player.getSalad()).c_str(), 48, 624);

        // Render the changing texts
        SDL_RenderPresent(renderer);
    }

    TTF_CloseFont(font);
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
    // Clean ressources from SDL_ttf
    TTF_Quit();
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
