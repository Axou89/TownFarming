#include <iostream>

#include "event_manager.hpp"
#include "player.hpp"
#include "utils.hpp"

// Process the game events
void EventManager::processEvents(Player &player, Level &level)
{
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            gameRunning = false;
            gameFinished = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                int mouseX = event.button.x;
                int mouseY = event.button.y;

                std::vector<Zone> zones = level.getZones();

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
                    if (player.canBuildFarmingZone() && zones.size() < 24)
                    {
                        player.buildFarmingZone();

                        // Add a new random zone
                        int randomZoneType = rand() % 3;
                        level.createZone(zones[randomZoneType].getTexture(),
                            SPRITE_WIDTH, SPRITE_HEIGHT,
                            std::make_pair(PLATFORM_SPRITE_SHEET_CONFIGURATION_X, PLATFORM_SPRITE_SHEET_CONFIGURATION_Y),
                            zones[randomZoneType].getZoneType());
                    }
                }

                // Check if the player clicked on the upgrade zone button
                if (utils::clickOnUpgradeZoneButton(mouseX, mouseY))
                {
                    if (player.canUpgradeFarmingZone())
                    {
                        player.upgradeFarmingZone();
                    }
                }
            }
            break;
        }
    }
}
