#pragma once
#ifdef __linux__
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_ttf.h>
#elif _WIN32
    #include <SDL.h>
    #include <SDL_ttf.h>
#endif
#include "rect.hpp"

//Загрузить текстуру из файла BMP
///name - название файла
///renderer - рендерер
///texture - указатель на текстуру
void loadTexture(const char* name,SDL_Renderer* renderer,SDL_Texture** texture);

//Нарисовать текстуру
///renderer - рендерер
///texture - текстура
///rect - указатель на границы текстуры
void drawTexture(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect* rect);

//конвертировать прямоугольник Rect в SDL_Rect
///rect - рисуемый прямоугольник
///возвращает SDL_Rect - прямоугольник с теми же координатами
SDL_Rect rectToSDL_Rect(Rect rect);

//Нарисовать текст на экране
void drawText(SDL_Renderer*& renderer,TTF_Font*& my_font, char*& text, int x, int y, int size);
