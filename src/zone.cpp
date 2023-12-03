#include "zone.hpp"
#include <vector>

// Constructor
Zone::Zone(Vector2f p_position, SDL_Texture* p_texture, int frameWidth, int frameHeight,
    std::pair<int, int> spriteSheetConfiguration, std::string p_zoneType) :
    Entity(p_position, p_texture, frameWidth, frameHeight, spriteSheetConfiguration), zoneType(p_zoneType) {}

// Create new zone
Zone Zone::createZone(SDL_Texture* texture, int frameWidth, int frameHeight,
    std::pair<int, int> spriteSheetConfiguration, std::string zoneType)
{
    return (Zone(Vector2f(256, 0),
        texture, frameWidth, frameHeight,
        spriteSheetConfiguration, zoneType));
}