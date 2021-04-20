#pragma once
#include "rect.hpp"

const int SIZE_X = 10;
const int SIZE_Y = 10;
const int TILE_SIZE = 50;

struct Tilemap
{
    int tiles[SIZE_X][SIZE_Y];
};

//Загружает карту из файла
///name - название файла
///tilemap - указатель на карту
void loadTilemap(const char* name, Tilemap* tilemap);

void saveTilemap(const char* name, Tilemap* tilemap);

//вернуть координаты тайла
///x,y - координаты тайла в Tilemap
///возвращает Rect - прямоугольник, равный координатам тайла
Rect tileToRect(int x, int y);
