#include "end_game_menu.hpp"
#include "constants.hpp"
#include "utils.hpp"

// Constructor
EndGameMenu::EndGameMenu(SDL_Renderer *renderer) : renderer(renderer)
{
    // Load font
    font = TTF_OpenFont(FONT_PATH, 36);

    backgroundTexture = IMG_LoadTexture(renderer, END_GAME_MENU_BACKGROUND_TEXTURE_PATH);
}

// Render the end game menu
void EndGameMenu::render(SDL_Renderer *renderer, int score)
{
    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

    std::string scoreString = "Your score is : " + std::to_string(score);

    // Render text
    utils::RenderEndText(font, renderer, "Thanks for playing Town Farming", WINDOW_WIDTH/2 - 220, WINDOW_HEIGHT/14);
    utils::RenderEndText(font, renderer, scoreString.c_str(), WINDOW_WIDTH/2 - 120, WINDOW_HEIGHT/2 - 260);
    utils::RenderEndText(font, renderer, "Press ESC to quit", WINDOW_WIDTH/2 - 120, WINDOW_HEIGHT - 180);

    // Render image
    if (score >= 500)
    {
        utils::RenderEndImage(renderer, HONEY_TEXTURE_PATH, WINDOW_WIDTH/2 - 100, WINDOW_HEIGHT/2 - 200);
    }
    if (score >= 1000)
    {
        utils::RenderEndImage(renderer, IRON_TEXTURE_PATH, WINDOW_WIDTH/2, WINDOW_HEIGHT/2 - 200);
    }
    if (score >= 1500)
    {
        utils::RenderEndImage(renderer, SALAD_TEXTURE_PATH, WINDOW_WIDTH/2 + 100, WINDOW_HEIGHT/2 - 200);
    }

    SDL_RenderPresent(renderer);
}

void EndGameMenu::cleanUp()
{
    TTF_CloseFont(font);
    SDL_DestroyTexture(backgroundTexture);
}