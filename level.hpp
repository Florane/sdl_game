#pragma once
#include "tilemap.hpp"
#include "platformFactory.hpp"

struct Level{
    Tilemap ground;
    PlatformFactory platforms;
};

//Инициализация уровня
void initLevel(Level& level);

//Очистка памяти уровня
void freeLevel(Level& level);

//Загрузка уровня из директории
void loadLevel(const char* name, Level& level);
