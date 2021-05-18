#pragma once
#include "tilemap.hpp"

struct Level{
    Tilemap ground;
};

//Инициализация уровня
void initLevel(Level& level);

//Очистка памяти уровня
void freeLevel(Level& level);

//Загрузка уровня из директории
void loadLevel(const char* name, Level& level);
