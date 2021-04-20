#pragma once
#include <SDL2/SDL.h>
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
