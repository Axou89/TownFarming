#pragma once

#include <SDL2/SDL_ttf.h>

#include "render_window.hpp"

class EndGameMenu
{
public:
    EndGameMenu(SDL_Renderer *renderer);

    void render(SDL_Renderer *renderer, int score);
    void cleanUp();

private:
    SDL_Renderer *renderer;
    TTF_Font *font;
    SDL_Texture *backgroundTexture;
};
