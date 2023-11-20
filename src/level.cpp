#include "level.hpp"
#include "platform.hpp"
#include "constants.hpp"

// Constructor
Level::Level(RenderWindow &window, Mix_Music* music) :
    window(window), music(music)
{
    entities.push_back(Entity(Vector2f(64, 0),
        window.loadTexture(TREE_TEXTURE_PATH), SPRITE_WIDTH, SPRITE_HEIGHT,
        std::make_pair(PLATFORM_SPRITE_SHEET_CONFIGURATION_X, PLATFORM_SPRITE_SHEET_CONFIGURATION_Y)));
    entities.push_back(Entity(Vector2f(128, 0),
        window.loadTexture(MINE_TEXTURE_PATH), SPRITE_WIDTH, SPRITE_HEIGHT,
        std::make_pair(PLATFORM_SPRITE_SHEET_CONFIGURATION_X, PLATFORM_SPRITE_SHEET_CONFIGURATION_Y)));
    entities.push_back(Entity(Vector2f(192, 0),
        window.loadTexture(FIELD_TEXTURE_PATH), SPRITE_WIDTH, SPRITE_HEIGHT,
        std::make_pair(PLATFORM_SPRITE_SHEET_CONFIGURATION_X, PLATFORM_SPRITE_SHEET_CONFIGURATION_Y)));

    for (int w = 0; w < (WINDOW_WIDTH / SCALE_FACTOR); w += SPRITE_WIDTH)
    {
        for (int h = 0; h < (WINDOW_HEIGHT / SCALE_FACTOR); h += SPRITE_HEIGHT)
        {
            if (w == 0)
            {
                // Overlay
                platforms.push_back(Platform(Vector2f(w, h),
                    window.loadTexture(OVERLAY_TEXTURE_PATH), SPRITE_WIDTH, SPRITE_HEIGHT,
                    std::make_pair(PLATFORM_SPRITE_SHEET_CONFIGURATION_X, PLATFORM_SPRITE_SHEET_CONFIGURATION_Y)));
            }
            else if (w%64 == 0 && h%64 == 0)
            {
                platforms.push_back(Platform(Vector2f(w, h),
                    window.loadTexture(EMPTY_TERRAIN_TEXTURE_PATH), SPRITE_WIDTH, SPRITE_HEIGHT,
                    std::make_pair(PLATFORM_SPRITE_SHEET_CONFIGURATION_X, PLATFORM_SPRITE_SHEET_CONFIGURATION_Y)));
            }
            else if (w%64 == 0 && h%64 != 0)
            {
                platforms.push_back(Platform(Vector2f(w, h),
                    window.loadTexture(HORIZONTAL_ROAD_TEXTURE_PATH), SPRITE_WIDTH, SPRITE_HEIGHT,
                    std::make_pair(PLATFORM_SPRITE_SHEET_CONFIGURATION_X, PLATFORM_SPRITE_SHEET_CONFIGURATION_Y)));
            }
            else if (w%64 != 0 && h%64 == 0)
            {
                platforms.push_back(Platform(Vector2f(w, h),
                    window.loadTexture(VERTICAL_ROAD_TEXTURE_PATH), SPRITE_WIDTH, SPRITE_HEIGHT,
                    std::make_pair(PLATFORM_SPRITE_SHEET_CONFIGURATION_X, PLATFORM_SPRITE_SHEET_CONFIGURATION_Y)));
            }
            else {
                platforms.push_back(Platform(Vector2f(w, h),
                    window.loadTexture(CROSS_ROAD_TEXTURE_PATH), SPRITE_WIDTH, SPRITE_HEIGHT,
                    std::make_pair(PLATFORM_SPRITE_SHEET_CONFIGURATION_X, PLATFORM_SPRITE_SHEET_CONFIGURATION_Y)));
            }
        }
    }
    // Log
    platforms.push_back(Platform(Vector2f(8, 20),
        window.loadTexture(LOG_TEXTURE_PATH), 16, 16,
        std::make_pair(PLATFORM_SPRITE_SHEET_CONFIGURATION_X, PLATFORM_SPRITE_SHEET_CONFIGURATION_Y)));
    // Honey
    platforms.push_back(Platform(Vector2f(8, 44),
        window.loadTexture(HONEY_TEXTURE_PATH), 16, 16,
        std::make_pair(PLATFORM_SPRITE_SHEET_CONFIGURATION_X, PLATFORM_SPRITE_SHEET_CONFIGURATION_Y)));

    // Play the music in loop
    if (Mix_PlayMusic(music, -1) == -1)
    {
        std::cerr << "Failed to play music! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }
}

// Destructor
Level::~Level()
{
    Mix_HaltMusic();
    Mix_FreeMusic(music);
}

// Render all the platforms
void Level::render(RenderWindow &window)
{
    // Render platforms
    for (Platform platform : platforms)
    {
        window.render(platform);
    }

    // Render entities
    for (Entity entity : entities)
    {
        window.render(entity);
    }
}

void Level::update()
{
}