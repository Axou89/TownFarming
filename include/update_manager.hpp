#pragma once

#include "event_manager.hpp"
#include "level.hpp"

class UpdateManager
{
public:
    UpdateManager(EventManager &eventManager, Level &level);

    void update();

private:
    EventManager &eventManager;
    Level &level;
};
