#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "constants.hpp"
#include "math.hpp"

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
    inline void RenderText(TTF_Font *font, SDL_Renderer *renderer, const char *text, int positionX, int positionY)
    {
        SDL_Surface *surface = TTF_RenderText_Solid(font, text, TEXT_COLOR);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_Rect dstrect = { positionX, positionY, 0, 0 };
        SDL_QueryTexture(texture, NULL, NULL, &dstrect.w, &dstrect.h);

        SDL_RenderCopy(renderer, texture, NULL, &dstrect);

        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }

    // Utility function to check if a point is within a frame
    inline bool clickOnEntity(int x, int y, const Vector2f &entityPosition)
    {
        return x >= entityPosition.x && x <= entityPosition.x + 32 && y >= entityPosition.y && y <= entityPosition.y + 32;
    }

    // Utility function to check if clicked on add zone button
    inline bool clickOnAddZoneButton(int x, int y)
    {
        return x >= 8*3 && x <= 24*3 && y >= 200*3 && y <= 216*3;
    }

    // Utility function to check if clicked on upgrade zone button
    inline bool clickOnUpgradeZoneButton(int x, int y)
    {
        return x >= 8*3 && x <= 24*3 && y >= 220*3 && y <= 236*3;
    }

    // Render the text and display it (used for the end game menu)
    inline void RenderEndText(TTF_Font *font, SDL_Renderer *renderer, const char *text, int positionX, int positionY)
    {
        SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, TEXT_COLOR);
        SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

        SDL_Rect textRect = { positionX, positionY, textSurface->w, textSurface->h };

        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);
    }

    inline void RenderEndImage(SDL_Renderer *renderer, const char *filePath, int positionX, int positionY)
    {
        SDL_Rect rect = {positionX, positionY, 64, 64};
        SDL_Texture *texture = IMG_LoadTexture(renderer, filePath);

        SDL_RenderCopy(renderer, texture, NULL, &rect);

        SDL_DestroyTexture(texture);
    }
}
