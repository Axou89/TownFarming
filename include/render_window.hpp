#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "entity.hpp"

class RenderWindow
{
public:
    SDL_Window* getWindow() { return window; }

    RenderWindow(const char* p_title, int width, int height);

    SDL_Texture* loadTexture(const char* p_filePath);

    void cleanUp();

    void clear();
    void render(Entity& p_entity);
    void display();

private:
    SDL_Window* window{nullptr};
    SDL_Renderer* renderer{nullptr};
};
