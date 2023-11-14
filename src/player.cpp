#include <random>

#include "player.hpp"

Player::Player(EventManager &p_eventManager) : eventManager(p_eventManager)
{
    inventory["log"] = 0;
    inventory["honey"] = 0;
    inventory["coal"] = 0;
    inventory["iron"] = 0;
    inventory["wheat"] = 0;
    inventory["salad"] = 0;
}

void Player::addForest()
{
    inventory["log"] += 1;

    // Set up a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Create a distribution for the random number generator
    std::uniform_int_distribution<> distribution(1, 100);

    // Generate a random number
    int randomNumber = distribution(gen);

    if (randomNumber <= 10)
    {
        inventory["honey"] += 1;
    }
}