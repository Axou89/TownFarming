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

// Background texture path
constexpr char* VERTICAL_ROAD_TEXTURE_PATH = "../../ressources/gfx/vertical_road.png";
constexpr char* HORIZONTAL_ROAD_TEXTURE_PATH = "../../ressources/gfx/horizontal_road.png";
constexpr char* CROSS_ROAD_TEXTURE_PATH = "../../ressources/gfx/cross_road.png";
constexpr char* EMPTY_TERRAIN_TEXTURE_PATH = "../../ressources/gfx/empty.png";

// Entities texture path
constexpr char* TREE_TEXTURE_PATH = "../../ressources/gfx/tree_animation.png";
constexpr char* FIELD_TEXTURE_PATH = "../../ressources/gfx/field.png";
constexpr char* MINE_TEXTURE_PATH = "../../ressources/gfx/mine_animation.png";

// Overlay texture path
constexpr char* OVERLAY_TEXTURE_PATH = "../../ressources/gfx/overlay.png";
constexpr char* LOG_TEXTURE_PATH = "../../ressources/gfx/log.png";
constexpr char* HONEY_TEXTURE_PATH = "../../ressources/gfx/honey.png";
constexpr char* COAL_TEXTURE_PATH = "../../ressources/gfx/coal.png";
constexpr char* IRON_TEXTURE_PATH = "../../ressources/gfx/iron.png";
constexpr char* CARROT_TEXTURE_PATH = "../../ressources/gfx/carrot.png";
constexpr char* SALAD_TEXTURE_PATH = "../../ressources/gfx/salad.png";
constexpr char* ADD_ZONE_TEXTURE_PATH = "../../ressources/gfx/add.png";
constexpr char* UPGRADE_ZONE_TEXTURE_PATH = "../../ressources/gfx/upgrade.png";

// Music path
constexpr char* GAME_MUSIC_PATH = "../../ressources/audio/chill_music.mp3";

// Font path
constexpr char* FONT_PATH = "../../ressources/fonts/arial.ttf";

// Text color
constexpr SDL_Color TEXT_COLOR = { 255, 255, 255 };

// Configuration of the platform sprite sheet
constexpr int PLATFORM_SPRITE_SHEET_CONFIGURATION_X = 0;
constexpr int PLATFORM_SPRITE_SHEET_CONFIGURATION_Y = 0;

// Configuration of the zone sprite sheet
constexpr int ZONE_SPRITE_SHEET_CONFIGURATION_X = 2;
constexpr int ZONE_SPRITE_SHEET_CONFIGURATION_Y = 2;

// Duration of the animation of the zones
constexpr int ZONE_ANIMATION_FRAME_TIME = 60;

// End Game Menu background
constexpr char* END_GAME_MENU_BACKGROUND_TEXTURE_PATH = "../../ressources/gfx/end_game_menu.jpg";