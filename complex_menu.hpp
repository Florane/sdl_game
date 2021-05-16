#pragma once
#ifdef __linux__
    #include <SDL2/SDL.h>
#elif _WIN32
    #include <SDL.h>
#endif
#include "rect.hpp"
#include "menu.hpp"
//Draws buttons on screen
void drawButtons(SDL_Renderer* renderer, Buttons* buttons, SDL_Texture** buttonTextures);

//Returns button pointed at
int selectButton(Buttons* buttons,const Vector* point);
