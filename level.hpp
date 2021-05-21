#pragma once
#include "tilemap.hpp"
#include "platformFactory.hpp"

/**
\defgroup Level_idiot
@{
\brief Уровень

Хранилище для всех данных, необходимых для загрузки и отрисовки уровня
*/

///Уровень
/**
\param ground Тайловая карта уровня
\param platforms Список платформ
*/
struct Level{
    Tilemap ground;
    PlatformFactory platforms;
};

///Инициализация уровня
/**
\param level Уровень
*/
void initLevel(Level& level);

///Очистка памяти уровня
/**
\param level Уровень
*/
void freeLevel(Level& level);

///Загрузка уровня из директории
/**
\param name Имя директории с файлами уровня
\param level Уровень
*/
void loadLevel(const char* name, Level& level);

///@}
