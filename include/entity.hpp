#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "math.hpp"

class Entity
{
public:
    Entity(Vector2f p_position, SDL_Texture* p_texture, int frameWidth, int frameHeight, std::pair<int, int> spriteSheetConfiguration);

    // Setters
    void setTex(SDL_Texture* p_texture) { texture = p_texture; }

    // Getters
    Vector2f& getPosition() { return position; }
    SDL_Texture* getTexture() { return texture; }
    SDL_Rect getCurrentFrame() { return currentFrame; }

private:
    Vector2f position;
    SDL_Rect currentFrame;
    SDL_Texture* texture;

    std::pair<int, int> spriteSheetConfiguration{0, 0};
    std::pair<int, int> currentFrameCoordinates{0, 0};
};
