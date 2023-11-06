#pragma once

#include <utility>

#include "event_manager.hpp"

class Player
{
public:
    // Constructor
    Player(EventManager &p_eventManager) : eventManager(p_eventManager) {};

private:
    EventManager &eventManager;
};