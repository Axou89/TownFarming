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

    // Setters
    void setGameRunning(bool p_gameRunning) { gameRunning = p_gameRunning; }
    void setGameFinished(bool p_gameFinished) { gameFinished = p_gameFinished; }

    bool isGameRunning() const { return gameRunning; }

    void processEvents(Player &player, Level &level);

    bool isGameFinished() const { return gameFinished; }

private:
    // Structure which contains the event type and the datas related
    SDL_Event event;
    bool gameRunning{true};
    bool gameFinished {true};
};
