#pragma once

#include <utility>
#include <map>
#include <string>

#include "event_manager.hpp"

class EventManager;

class Player
{
public:
    // Constructor
    Player(EventManager &p_eventManager);

    int getLog() { return inventory["log"]; }

    void addLog() { inventory["log"]++; }

private:
    EventManager &eventManager;
    std::map<std::string, int> inventory;
};