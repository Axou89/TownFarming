#include "level.hpp"
#include "platform.hpp"
#include "constants.hpp"
#include "global_variables.hpp"

// Constructor
Level::Level(RenderWindow &window, Mix_Music* music) :
    window(window), music(music)
{
    // Add base forest zone
    zones.push_back(Zone(Vector2f(64, 0),
        window.loadTexture(TREE_TEXTURE_PATH), SPRITE_WIDTH, SPRITE_HEIGHT,
        std::make_pair(ZONE_SPRITE_SHEET_CONFIGURATION_X, ZONE_SPRITE_SHEET_CONFIGURATION_Y), "forest"));
    // Add base mine zone
    zones.push_back(Zone(Vector2f(128, 0),
        window.loadTexture(MINE_TEXTURE_PATH), SPRITE_WIDTH, SPRITE_HEIGHT,
        std::make_pair(ZONE_SPRITE_SHEET_CONFIGURATION_X, ZONE_SPRITE_SHEET_CONFIGURATION_Y), "mine"));
    // Add base farm zone
    zones.push_back(Zone(Vector2f(192, 0),
        window.loadTexture(FIELD_TEXTURE_PATH), SPRITE_WIDTH, SPRITE_HEIGHT,
        std::make_pair(ZONE_SPRITE_SHEET_CONFIGURATION_X, ZONE_SPRITE_SHEET_CONFIGURATION_Y), "farm"));

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
    platforms.push_back(Platform(Vector2f(8, 24),
        window.loadTexture(LOG_TEXTURE_PATH), 16, 16,
        std::make_pair(PLATFORM_SPRITE_SHEET_CONFIGURATION_X, PLATFORM_SPRITE_SHEET_CONFIGURATION_Y)));
    // Honey
    platforms.push_back(Platform(Vector2f(8, 52),
        window.loadTexture(HONEY_TEXTURE_PATH), 16, 16,
        std::make_pair(PLATFORM_SPRITE_SHEET_CONFIGURATION_X, PLATFORM_SPRITE_SHEET_CONFIGURATION_Y)));
    // Coal
    platforms.push_back(Platform(Vector2f(8, 80),
        window.loadTexture(COAL_TEXTURE_PATH), 16, 16,
        std::make_pair(PLATFORM_SPRITE_SHEET_CONFIGURATION_X, PLATFORM_SPRITE_SHEET_CONFIGURATION_Y)));
    // Iron
    platforms.push_back(Platform(Vector2f(8, 108),
        window.loadTexture(IRON_TEXTURE_PATH), 16, 16,
        std::make_pair(PLATFORM_SPRITE_SHEET_CONFIGURATION_X, PLATFORM_SPRITE_SHEET_CONFIGURATION_Y)));
    // Carrot
    platforms.push_back(Platform(Vector2f(8, 136),
        window.loadTexture(CARROT_TEXTURE_PATH), 16, 16,
        std::make_pair(PLATFORM_SPRITE_SHEET_CONFIGURATION_X, PLATFORM_SPRITE_SHEET_CONFIGURATION_Y)));
    // Salad
    platforms.push_back(Platform(Vector2f(8, 164),
        window.loadTexture(SALAD_TEXTURE_PATH), 16, 16,
        std::make_pair(PLATFORM_SPRITE_SHEET_CONFIGURATION_X, PLATFORM_SPRITE_SHEET_CONFIGURATION_Y)));
    // Add new farming zone button
    platforms.push_back(Platform(Vector2f(8, 168),
        window.loadTexture(ADD_ZONE_TEXTURE_PATH), 16, 16,
        std::make_pair(PLATFORM_SPRITE_SHEET_CONFIGURATION_X, PLATFORM_SPRITE_SHEET_CONFIGURATION_Y)));
    // Upgrade farming zone button
    platforms.push_back(Platform(Vector2f(8, 192),
        window.loadTexture(UPGRADE_ZONE_TEXTURE_PATH), 16, 16,
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
    for (Zone zone : zones)
    {
        window.render(zone);
    }
}

// Create new zone
void Level::createZone(SDL_Texture* texture, int frameWidth, int frameHeight,
    std::pair<int, int> spriteSheetConfiguration, std::string zoneType)
{
    zones.push_back(Zone(Vector2f(FARMING_ZONE_POSITION_X, FARMING_ZONE_POSITION_Y),
        texture, frameWidth, frameHeight,
        spriteSheetConfiguration, zoneType));
    if (FARMING_ZONE_POSITION_X == 384)
    {
        FARMING_ZONE_POSITION_X = 64;
        FARMING_ZONE_POSITION_Y += 64;
    } else {
        FARMING_ZONE_POSITION_X += 64;
    }

    if (zoneType == "forest")
    {
        LOG_TO_ADD += 1;
    } else if (zoneType == "mine")
    {
        COAL_TO_ADD += 1;
    } else if (zoneType == "farm")
    {
        CARROT_TO_ADD += 1;
    }
}

void Level::update()
{
    for (Zone& zone : zones)
    {
        zone.updateAnimation();
    }
}

void Level::cleanUp()
{
    for (Platform platform : platforms)
    {
        SDL_DestroyTexture(platform.getTexture());
    }
    for (Zone zone : zones)
    {
        SDL_DestroyTexture(zone.getTexture());
    }
}