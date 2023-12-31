#include "game.hpp"
#include "utils.hpp"
#include "constants.hpp"

#include <cmath>

// Constructor
Game::Game() :
    currentTime(utils::hireTimeInSeconds()),
    timeStep(TIME_STEP),
    window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT),
    eventManager(),
    level(window, loadMusic(GAME_MUSIC_PATH)),
    player(player),
    updateManager(eventManager, level),
    renderManager(window, level),
    endGameMenu(window.getRenderer()) {}

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
    Mix_VolumeMusic(64);

    int lastAction = 0;
    int timer = 0;
    float pausedTimer = 0;

    // Game loop
    while (eventManager.isGameRunning())
    {
        eventManager.processEvents(player, level);

        if (!eventManager.isGamePaused())
        {
            // Calculate logic game frames beside the rendered frames
            float newTime = utils::hireTimeInSeconds() - pausedTimer;
            float frameTime = newTime - currentTime;
            currentTime = newTime;
            accumulator += frameTime;
            // Time in seconds
            timer = std::floor(currentTime);

            while (accumulator >= timeStep)
            {
                updateManager.update();
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
        } else
        {
            pausedTimer = utils::hireTimeInSeconds() - currentTime;
        }

        renderManager.render();

        // Display static text
        utils::RenderText(font, renderer, "Timer", 16, 8);

        // Update timer text
        utils::RenderText(font, renderer, std::to_string(timer).c_str(), 32, 36);

        // Update log quantity text
        utils::RenderText(font, renderer, std::to_string(player.getLog()).c_str(), 24, 128);
        // Update honey quantity text
        utils::RenderText(font, renderer, std::to_string(player.getHoney()).c_str(), 24, 212);
        // Update coal quantity text
        utils::RenderText(font, renderer, std::to_string(player.getCoal()).c_str(), 24, 296);
        // Update iron quantity text
        utils::RenderText(font, renderer, std::to_string(player.getIron()).c_str(), 24, 380);
        // Update carrot quantity text
        utils::RenderText(font, renderer, std::to_string(player.getCarrot()).c_str(), 24, 464);
        // Update salad quantity text
        utils::RenderText(font, renderer, std::to_string(player.getSalad()).c_str(), 24, 548);

        // Render the changing texts
        SDL_RenderPresent(renderer);

        // End the game
        if (timer >= 180) {
            int score = player.getLog() + player.getHoney() * 5 + player.getCoal() + player.getIron() * 5 + player.getCarrot() + player.getSalad() * 5;

            while (eventManager.isGameFinished())
            {
                // Calculate logic game frames beside the rendered frames
                float newTime = utils::hireTimeInSeconds();
                float frameTime = newTime - currentTime;
                currentTime = newTime;
                accumulator += frameTime;

                while (accumulator >= timeStep)
                {
                    accumulator -= timeStep;
                }
                
                eventManager.processEvents(player, level);
                endGameMenu.render(renderer, score);
            }
        }
    }

    TTF_CloseFont(font);
}

// Clean all resources
void Game::cleanUp()
{
    // Clean resources from SDL_mixer
    Mix_CloseAudio();
    // Clean resources from the rendered window
    window.cleanUp();
    // Clean resources from SDL_image
    IMG_Quit();
    // Clean resources from SDL
    SDL_Quit();
    // Clean resources from SDL_ttf
    TTF_Quit();
    // Clean resources from End Game Menu
    endGameMenu.cleanUp();
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
