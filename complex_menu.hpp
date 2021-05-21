#pragma once
#ifdef __linux__
    #include <SDL2/SDL.h>
#elif _WIN32
    #include <SDL.h>
#endif
#include "rect.hpp"
#include "menu.hpp"

/**
\defgroup ComplexMenu
@{
\brief Декоратор для меню

Дополнительные функции для использования с меню
*/

///Отрисовать кнопки на экран
/**
\param renderer Рендерер
\param buttons Меню с кнопками
\param buttonTextures Массив текстур кнопок по порядку
*/
void drawButtons(SDL_Renderer* renderer, Buttons* buttons, SDL_Texture** buttonTextures);

///Возвращает кнопку, выделенную курсором
/**
\param buttons Меню с кнопками
\param point Курсор мышки
\return ID выбранной кнопки
*/
int selectButton(Buttons* buttons,const Vector* point);

///@}
