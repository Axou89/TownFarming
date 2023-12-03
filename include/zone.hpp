#pragma once

#include "entity.hpp"

class Zone : public Entity
{
public:
    Zone(Vector2f p_position, SDL_Texture* p_texture, int frameWidth, int frameHeight,
        std::pair<int, int> spriteSheetConfiguration, std::string p_zoneType);

    // Getters
    std::string getZoneType() { return zoneType; }
    std::string getPostionString() { Vector2f entityPosition = getPosition(); return std::to_string(entityPosition.x) + ", " + std::to_string(entityPosition.y); }

    // Create new zone
    Zone createZone(SDL_Texture* texture, int frameWidth, int frameHeight,
        std::pair<int, int> spriteSheetConfiguration, std::string zoneType);

private:
    std::string zoneType;
};
