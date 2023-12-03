#include <iostream>

#include "event_manager.hpp"
#include "player.hpp"
#include "utils.hpp"

// Process the game events
void EventManager::processEvents(Player &player, std::vector<Zone> zones, RenderWindow &window)
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

                // Check if the player clicked on a farming zone
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

                // Check if the player clicked on the add zone button
                if (utils::clickOnAddZoneButton(mouseX, mouseY))
                {
                    if (player.canBuildFarmingZone())
                    {
                        int randomZoneType = rand() % 3;
                        zones.push_back(zones[zones.size()].createZone(window.loadTexture(TREE_TEXTURE_PATH),
                            SPRITE_WIDTH, SPRITE_HEIGHT,
                            std::make_pair(PLATFORM_SPRITE_SHEET_CONFIGURATION_X, PLATFORM_SPRITE_SHEET_CONFIGURATION_Y),
                            zones[randomZoneType].getZoneType()));
                    }
                }
            }
            break;
        }
    }
}
