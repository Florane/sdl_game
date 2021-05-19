#pragma once
#ifdef __linux__
    #include <SDL2/SDL.h>
#elif _WIN32
    #include <SDL.h>
#endif
#include "platformFactory.hpp"
#include "player.hpp"

void drawPlatforms(SDL_Renderer*& renderer, PlatformFactory& platforms, Player& player, SDL_Texture* platformTexture);

void stepPlatforms(PlatformFactory& platforms);
