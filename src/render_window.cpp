#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "render_window.hpp"
#include "constants.hpp"

// RenderWindow is called at the creation of a RenderWindow object
RenderWindow::RenderWindow(const char* p_title, int width, int height) :
    window(SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN)),
    renderer(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC))
{
    if (window == nullptr)
    {
        std::cerr << "Window failed to init. Error: " << SDL_GetError() << std::endl;
    }
    if (renderer == nullptr)
    {
        std::cerr << "Renderer failed to init. Error: " << SDL_GetError() << std::endl;
    }
}

// Load a texture
SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
    // Initialize texture
    SDL_Texture* texture = nullptr;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == nullptr)
    {
        std::cerr << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
    }
    return texture;
}

// Clean up the memory
void RenderWindow::cleanUp()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

// Erase the render
void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

// Render a texture
void RenderWindow::render(Entity& p_entity)
{
    // Create a source rectangle
    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;

    // Create a destination rectangle
    SDL_Rect dst;
    dst.x = p_entity.getPosition().x * SCALE_FACTOR;
    dst.y = p_entity.getPosition().y * SCALE_FACTOR;
    dst.w = p_entity.getCurrentFrame().w * SCALE_FACTOR;
    dst.h = p_entity.getCurrentFrame().h * SCALE_FACTOR;

    // Display a texture in the renderer
    SDL_RenderCopy(renderer, p_entity.getTexture(), &src, &dst); 
}

// Display the renderer
void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}
