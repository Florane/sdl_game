#pragma once
#include "rect.hpp"

const int TILE_SIZE = 50;

struct Tilemap
{
    int sizeX, sizeY;
    char** tiles;
};
//Инициализация
void initTilemap(Tilemap& tiles);

//Освободить память карты
void freeTilemap(Tilemap& tiles);

//Загрузить карту
void loadTilemap(const char* name, Tilemap& tiles);

//Прямоугольник тайла x,y
Rect tileToRect(int x,int y);
