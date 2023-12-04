#pragma once

#include <SDL2/SDL.h>
#include <vector>

#include "entity.hpp"
#include "render_window.hpp"
#include "level.hpp"

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

    void processEvents(Player &player, RenderWindow &window, Level &level);

private:
    // Structure which contains the event type and the datas related
    SDL_Event event;
    bool gameRunning{true};
};
