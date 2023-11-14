#pragma once

#include <SDL2/SDL.h>

class Player;

class EventManager
{
public:
    // Constructor
    EventManager() = default;
    // Destructor
    ~EventManager() = default;

    bool isGameRunning() const { return gameRunning; }

    void processEvents(Player &player);

private:
    // Structure which contains the event type and the datas related
    SDL_Event event;
    bool gameRunning{true};
};
