#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "constants.hpp"

namespace utils
{
    // Return the time since the launching of the game in seconds
    inline float hireTimeInSeconds()
    {
        // Get the time since the launching of the game in milliseconds
        float t = SDL_GetTicks();
        // Convert the time in seconds
        t *= 0.001f;

        return t;
    }

    // Load the font for the texts
    inline TTF_Font* loadFont(const char *filePath, int fontSize)
    {
        // Load the font
        TTF_Font* font = TTF_OpenFont(filePath, fontSize);
        // Check if the font has been loaded
        if (font == nullptr)
        {
            // Display an error message in the terminal
            std::cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
        }

        return font;
    }

    // Render the text and display it
    inline void RenderText(TTF_Font *font, SDL_Renderer *renderer, const char *text, int positionY)
    {
        SDL_Surface *surface = TTF_RenderText_Solid(font, text, TEXT_COLOR);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_Rect dstrect = { 32, positionY, 0, 0 };
        SDL_QueryTexture(texture, NULL, NULL, &dstrect.w, &dstrect.h);

        SDL_RenderCopy(renderer, texture, NULL, &dstrect);

        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }
}
