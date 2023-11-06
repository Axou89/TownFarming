#include "update_manager.hpp"
#include "event_manager.hpp"
#include "level.hpp"

// Constructor
UpdateManager::UpdateManager(EventManager &eventManager, Level &level) : eventManager(eventManager), level(level) {}