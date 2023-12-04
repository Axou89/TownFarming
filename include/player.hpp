#pragma once

#include <utility>
#include <map>
#include <string>

#include "event_manager.hpp"
#include "global_variables.hpp"

// Forward class EventManager
class EventManager;

class Player
{
public:
    // Constructor
    Player(EventManager &p_eventManager);

    // Getters
    int getLog() { return inventory["log"]; }
    int getHoney() { return inventory["honey"]; }
    int getCoal() { return inventory["coal"]; }
    int getIron() { return inventory["iron"]; }
    int getCarrot() { return inventory["carrot"]; }
    int getSalad() { return inventory["salad"]; }

    // Add resources on click
    void addForest();
    void addMine();
    void addFarm();

    // Add resources automatically
    void addLog() { inventory["log"] += LOG_TO_ADD * MULTIPLICATOR_TO_ADD; };
    void addCoal() { inventory["coal"] += COAL_TO_ADD * MULTIPLICATOR_TO_ADD; };
    void addCarrot() { inventory["carrot"] += CARROT_TO_ADD * MULTIPLICATOR_TO_ADD; };

    // Check if the player has enough resources to build a zone
    bool canBuildFarmingZone();

    // Use ressources to build a zone
    void buildFarmingZone();

    // Check if the player has enough resources to upgrade farming zones
    bool canUpgradeFarmingZone();

    // Use ressources to upgrade farming zones
    void upgradeFarmingZone();

private:
    EventManager &eventManager;
    std::map<std::string, int> inventory;
};