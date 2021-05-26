#pragma once
#include "player.hpp"
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
    int id;
    Player player;
    Tilemap ground;
    Tilemap spikes;
    Tilemap coins;
    PlatformFactory platforms;
    PlatformFactory exit;
    PlatformFactory enemies;
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
