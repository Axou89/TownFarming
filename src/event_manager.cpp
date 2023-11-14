#include <iostream>

#include "event_manager.hpp"
#include "player.hpp"
#include "utils.hpp"

// Process the game events
void EventManager::processEvents(Player &player, Entity entities)
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
                int mouseX = event.button.x;
                int mouseY = event.button.y;
                Vector2f entityPosition = entities.getPosition();

                if (utils::clickOnEntity(mouseX / SCALE_FACTOR, mouseY / SCALE_FACTOR, entityPosition))
                    {
                        player.addLog();
                    }
            }
            break;
        }
    }
}
