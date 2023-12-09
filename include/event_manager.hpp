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
    void setGamePaused(bool p_gamePaused) { gamePaused = p_gamePaused; }

    // Getters
    bool isGameRunning() const { return gameRunning; }
    bool isGameFinished() const { return gameFinished; }
    bool isGamePaused() const { return gamePaused; }

    void processEvents(Player &player, Level &level);

private:
    // Structure which contains the event type and the datas related
    SDL_Event event;
    bool gameRunning{true};
    bool gameFinished {true};
    bool gamePaused{false};
};
