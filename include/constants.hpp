#pragma once

// Window title
constexpr char *WINDOW_TITLE = "Town Farming";

// Window size
constexpr int WINDOW_HEIGHT = 720;
constexpr int WINDOW_WIDTH = 1280;

// Time between each logic game frame in seconds
constexpr float TIME_STEP = 0.01;

// Platform size
constexpr int PLATFORM_WIDTH = 32;
constexpr int PLATFORM_HEIGHT = 32;

// Scale factor for platforms
constexpr int SCALE_FACTOR = 4;

// Texture path
constexpr char* PLATFORM_TEXTURE_PATH = "../../ressources/gfx/grass.png";

// Music path
constexpr char* GAME_MUSIC_PATH = "../../ressources/audio/Duck-Sandstorm.mp3";

// Configuration of the platform sprite sheet
constexpr int PLATFORM_SPRITE_SHEET_CONFIGURATION_X = 0;
constexpr int PLATFORM_SPRITE_SHEET_CONFIGURATION_Y = 0;