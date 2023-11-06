#pragma once

#include "event_manager.hpp"
#include "level.hpp"

class UpdateManager
{
public:
    UpdateManager(EventManager &eventManager, Level &level);

private:
    EventManager &eventManager;
    Level &level;
};
