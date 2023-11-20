#include <iostream>

#include "event_manager.hpp"
#include "player.hpp"
#include "utils.hpp"

// Process the game events
void EventManager::processEvents(Player &player, std::vector<Zone> zones)
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

                for (Zone zone : zones)
                {
                    Vector2f zonePosition = zone.getPosition();
                    if (utils::clickOnEntity(mouseX / SCALE_FACTOR, mouseY / SCALE_FACTOR, zonePosition))
                    {
                        if (zone.getZoneType() == "forest")
                        {
                            player.addForest();
                        }
                        else if (zone.getZoneType() == "mine")
                        {
                            player.addMine();
                        }
                        else if (zone.getZoneType() == "farm")
                        {
                            player.addFarm();
                        }
                    }
                }
            }
            break;
        }
    }
}
