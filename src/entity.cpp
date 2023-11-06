#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "entity.hpp"

// Constructor
Entity::Entity(Vector2f p_position, SDL_Texture* p_texture, int frameWidth, int frameHeight, std::pair<int, int> spriteSheetConfiguration) :
    position(p_position), texture(p_texture), currentFrame{0, 0, frameWidth, frameHeight}, 
    spriteSheetConfiguration(spriteSheetConfiguration) {}
