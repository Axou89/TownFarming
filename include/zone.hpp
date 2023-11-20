#pragma once

#include "entity.hpp"

class Zone : public Entity
{
public:
    Zone(Vector2f p_position, SDL_Texture* p_texture, int frameWidth, int frameHeight,
        std::pair<int, int> spriteSheetConfiguration, std::string p_zoneType);

    // Getters
    std::string getZoneType() { return zoneType; }

private:
    std::string zoneType;
};
