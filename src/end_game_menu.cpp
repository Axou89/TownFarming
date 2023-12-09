#include "end_game_menu.hpp"
#include "constants.hpp"
#include "utils.hpp"

// Constructor
EndGameMenu::EndGameMenu(SDL_Renderer *renderer) : renderer(renderer)
{
    // Load font
    font = TTF_OpenFont(FONT_PATH, 36);

    // Load background texture (black screen)
    SDL_Surface *backgroundSurface = SDL_CreateRGBSurface(0, WINDOW_WIDTH, WINDOW_HEIGHT, 32, 0, 0, 0, 0);
    SDL_FillRect(backgroundSurface, NULL, SDL_MapRGB(backgroundSurface->format, 0, 0, 0));
    backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
    SDL_FreeSurface(backgroundSurface);
}

// Render the end game menu
void EndGameMenu::render(SDL_Renderer *renderer, int score)
{
    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

    std::string scoreString = "Your score : " + std::to_string(score);

    utils::RenderEndText(font, renderer, scoreString.c_str(), WINDOW_WIDTH/2 - 100, WINDOW_HEIGHT/2 - 100);

    SDL_RenderPresent(renderer);
}

void EndGameMenu::cleanUp()
{
    TTF_CloseFont(font);
    SDL_DestroyTexture(backgroundTexture);
}