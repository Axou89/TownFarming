#include <random>

#include "player.hpp"

Player::Player(EventManager &p_eventManager) : eventManager(p_eventManager)
{
    inventory["log"] = 0;
    inventory["honey"] = 0;
    inventory["coal"] = 0;
    inventory["iron"] = 0;
    inventory["carrot"] = 0;
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

void Player::addMine()
{
    inventory["coal"] += 1;

    // Set up a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Create a distribution for the random number generator
    std::uniform_int_distribution<> distribution(1, 100);

    // Generate a random number
    int randomNumber = distribution(gen);

    if (randomNumber <= 10)
    {
        inventory["iron"] += 1;
    }
}

void Player::addFarm()
{
    inventory["carrot"] += 1;

    // Set up a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Create a distribution for the random number generator
    std::uniform_int_distribution<> distribution(1, 100);

    // Generate a random number
    int randomNumber = distribution(gen);

    if (randomNumber <= 10)
    {
        inventory["salad"] += 1;
    }
}

bool::Player::canBuildFarmingZone()
{
    if (inventory["log"] >= 1 && inventory["coal"] >= 1 && inventory["carrot"] >= 1)
    {
        return true;
    }
    return false;
}

void Player::buildFarmingZone()
{
    inventory["log"] -= 5;
    inventory["coal"] -= 5;
    inventory["carrot"] -= 5;
}