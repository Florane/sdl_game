#pragma once
#ifdef __linux__
    #include <SDL2/SDL.h>
#elif _WIN32
    #include <SDL.h>
#endif
#include "tilemap.hpp"
#include "player.hpp"

//Отрисовать кнопки на экран
void drawTilemap(SDL_Renderer*& renderer, Tilemap& tilemap, Player& player, SDL_Texture** tilemapTextures);
