#include "level.hpp"
#include "platform.hpp"
#include "constants.hpp"

// Constructor
Level::Level(RenderWindow &window) : window(window)
{
    for (int i = 0; i < (WINDOW_WIDTH / SCALE_FACTOR); i += PLATFORM_WIDTH)
    {
        platforms.push_back(Platform(Vector2f(i, ((WINDOW_HEIGHT / SCALE_FACTOR) - PLATFORM_HEIGHT)),
            window.loadTexture(PLATFORM_TEXTURE_PATH), PLATFORM_WIDTH, PLATFORM_HEIGHT,
            std::make_pair(PLATFORM_SPRITE_SHEET_CONFIGURATION_X, PLATFORM_SPRITE_SHEET_CONFIGURATION_Y)));
    }

    /* NOT YET INCLUDED
    // Play the music in loop
    if (Mix_PlayMusic(music, -1) == -1)
    {
        std::cerr << "Failed to play music! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }
    */
}

// Destructor
Level::~Level()
{
    Mix_HaltMusic();
    /* NOT YET INCLUDED
    Mix_FreeMusic(music);
    */
}

// Render all the platforms
void Level::render(RenderWindow &window)
{
    for (Platform platform : platforms)
    {
        window.render(platform);
    }

}
