#pragma once
#ifdef __linux__
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_ttf.h>
#elif _WIN32
    #include <SDL.h>
    #include <SDL_ttf.h>
#endif
#include "rect.hpp"

/**
\defgroup Draw
@{
\brief Функции отрисовки

Основные функции для отрисовки сложных объектов
*/

///Загрузить текстуру из файла BMP
/**
\param name Имя файла
\param renderer Рендерер
\param texture Указатель на текстуру
*/
void loadTexture(const char* name,SDL_Renderer* renderer,SDL_Texture** texture);

///Нарисовать текстуру
/**
\param renderer Рендерер
\param texture Текстура
\param rect Указатель на границы текстуры
*/
void drawTexture(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect* rect);

///Конвертировать прямоугольник Rect в SDL_Rect
/**
\param rect Простой прямоугольник
\return `SDL_Rect` Прямоугольник с теми же координатами
*/
SDL_Rect rectToSDL_Rect(Rect rect);

///Нарисовать текст на экране
/**
\param renderer Рендерер
\param my_font Шрифт
\param text Текст для вывода
\param x,y Позиция на экране
\param size Высота символа
*/
void drawText(SDL_Renderer*& renderer,TTF_Font*& my_font, char*& text, int x, int y, int size);

///@}
