#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "entity.hpp"
#include "constants.hpp"

// Constructor
Entity::Entity(Vector2f p_position, SDL_Texture* p_texture, int frameWidth, int frameHeight, std::pair<int, int> spriteSheetConfiguration) :
    position(p_position), texture(p_texture), currentFrame{0, 0, frameWidth, frameHeight}, 
    spriteSheetConfiguration(spriteSheetConfiguration) {}

// Update the animation of the entity
void Entity::updateAnimation()
{
    if (logicUpdateCounter % ZONE_ANIMATION_FRAME_TIME == 0)
    {
        currentFrameCoordinates.first += 1;
        if (currentFrameCoordinates.first >= spriteSheetConfiguration.first)
        {
            currentFrameCoordinates.first = 0;
            currentFrameCoordinates.second += 1;
            if (currentFrameCoordinates.second >= spriteSheetConfiguration.second)
            {
                currentFrameCoordinates.second = 0;
            }
        }
        currentFrame.x = currentFrameCoordinates.first * currentFrame.w;
        currentFrame.y = currentFrameCoordinates.second * currentFrame.h;
    }

    logicUpdateCounter++;
}