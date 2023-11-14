#include "player.hpp"

Player::Player(EventManager &p_eventManager) : eventManager(p_eventManager)
{
    inventory["log"] = 0;
    inventory["coal"] = 0;
    inventory["wheat"] = 0;
}