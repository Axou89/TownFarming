#pragma once

#include <utility>
#include <map>
#include <string>

#include "event_manager.hpp"

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
    void addLog() { inventory["log"] += 1; };
    void addCoal() { inventory["coal"] += 1; };
    void addCarrot() { inventory["carrot"] += 1; };

private:
    EventManager &eventManager;
    std::map<std::string, int> inventory;
};