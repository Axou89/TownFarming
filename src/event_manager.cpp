#include <iostream>

#include "event_manager.hpp"
#include "player.hpp"

// Process the game events
void EventManager::processEvents(Player &player)
{
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            gameRunning = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                std::cout << "Left mouse button pressed" << std::endl;
                player.addLog();
            }
            break;
        }
    }
}
