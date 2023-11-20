#include "zone.hpp"

// Constructor
Zone::Zone(Vector2f p_position, SDL_Texture* p_texture, int frameWidth, int frameHeight,
    std::pair<int, int> spriteSheetConfiguration, std::string p_zoneType) :
    Entity(p_position, p_texture, frameWidth, frameHeight, spriteSheetConfiguration), zoneType(p_zoneType) {}