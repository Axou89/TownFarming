#pragma once

#include "entity.hpp"

class Platform : public Entity
{
public:
    // Constructor
    Platform(Vector2f p_pos, SDL_Texture *p_tex, int width, int height, std::pair<int, int> spriteSheetConfiguration)
        : Entity(p_pos, p_tex, width, height, spriteSheetConfiguration) {}
};
