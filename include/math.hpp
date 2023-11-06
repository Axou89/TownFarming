#pragma once

#include <iostream>

// Structure for the 2D Vector
struct Vector2f
{
    // Default constructor
    Vector2f() : x(0.0), y(0.0) {}

    // Constructor
    Vector2f(float p_x, float p_y) : x(p_x), y(p_y) {}

    // Print the vector coordinates
    void print() { std::cout << "x: " << x << ", y: " << y << std::endl; }

    float x;
    float y;
};
