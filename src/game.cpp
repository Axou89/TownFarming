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
    // Overlay

    TTF_Font *font = TTF_OpenFont("arial.ttf", 25);
    if (!font)
    {
        std::cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
    }

    SDL_Color color = { 255, 255, 255 };
    SDL_Surface *surface = TTF_RenderText_Solid(font, "250", color);
    
    SDL_Renderer *renderer = window.getRenderer();

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    int overlayWidht = 0;
    int overlayHeight = 0;
    SDL_QueryTexture(texture, NULL, NULL, &overlayWidht, &overlayHeight);
    SDL_Rect dstrect = { 32, 16, overlayWidht, overlayHeight };

    // End overlay

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
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        SDL_RenderPresent(renderer);
    }
	
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
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
