#pragma once
#include "rect.hpp"

/**
\defgroup Menu
@{
\brief Меню

Меню - хранилище кнопок с дополнительными функциями для возможности выбора кнопок
*/

///
/**
\param buttons
\param amount
\param selected
*/
struct Buttons
{
    Rect* buttons;
    int amount;
    int selected;
};

///Инициализация меню
/**
\param buttons Указатель на меню
*/
void initButtons(Buttons* buttons);

///Загрузить кнопки из файла
/**
\param name Имя файла
\param buttons Указатель на меню
*/
void loadButtons(const char* name, Buttons* buttons);

///Выбор кнопки с проверкой границ
/**
\param buttons Указатель на меню
*/
void cleanSelect(Buttons* buttons);

///Выбрать кнопку выше по списку
/**
\param buttons Указатель на меню
*/
void up(Buttons* buttons);

///Выбрать кнопку ниже по списку
/**
\param buttons Указатель на меню
*/
void down(Buttons* buttons);

///@}
