#pragma once

#include <SDL2/SDL.h>
#include <vector>

#include "entity.hpp"
#include "zone.hpp"
#include "render_window.hpp"

// Forward class Player
class Player;

class EventManager
{
public:
    // Constructor
    EventManager() = default;
    // Destructor
    ~EventManager() = default;

    bool isGameRunning() const { return gameRunning; }

    void processEvents(Player &player, std::vector<Zone> zones, RenderWindow &window);

private:
    // Structure which contains the event type and the datas related
    SDL_Event event;
    bool gameRunning{true};
};
