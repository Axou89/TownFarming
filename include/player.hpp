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

    int getLog() { return inventory["log"]; }
    int getHoney() { return inventory["honey"]; }
    int getCoal() { return inventory["coal"]; }
    int getIron() { return inventory["iron"]; }
    int getWheat() { return inventory["wheat"]; }
    int getSalad() { return inventory["salad"]; }

    void addForest();

private:
    EventManager &eventManager;
    std::map<std::string, int> inventory;
};