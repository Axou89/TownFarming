#pragma once

#include <SDL2/SDL.h>

// Window title
constexpr char *WINDOW_TITLE = "Town Farming";

// Window size
constexpr int WINDOW_HEIGHT = 896;
constexpr int WINDOW_WIDTH = 1664;

// Time between each logic game frame in seconds
constexpr float TIME_STEP = 0.01;

// Sprite size
constexpr int SPRITE_WIDTH = 32;
constexpr int SPRITE_HEIGHT = 32;

// Scale factor for sprites
constexpr int SCALE_FACTOR = 4;

// Texture path
constexpr char* VERTICAL_ROAD_TEXTURE_PATH = "../../ressources/gfx/vertical_road.png";
constexpr char* HORIZONTAL_ROAD_TEXTURE_PATH = "../../ressources/gfx/horizontal_road.png";
constexpr char* CROSS_ROAD_TEXTURE_PATH = "../../ressources/gfx/cross_road.png";
constexpr char* TREE_TEXTURE_PATH = "../../ressources/gfx/tree.png";
constexpr char* EMPTY_TERRAIN_TEXTURE_PATH = "../../ressources/gfx/empty.png";
constexpr char* OVERLAY_TEXTURE_PATH = "../../ressources/gfx/overlay.png";

// Music path
constexpr char* GAME_MUSIC_PATH = "../../ressources/audio/Duck-Sandstorm.mp3";

// Font path
constexpr char* FONT_PATH = "arial.ttf";

// Text color
constexpr SDL_Color TEXT_COLOR = { 255, 255, 255 };

// Configuration of the platform sprite sheet
constexpr int PLATFORM_SPRITE_SHEET_CONFIGURATION_X = 0;
constexpr int PLATFORM_SPRITE_SHEET_CONFIGURATION_Y = 0;