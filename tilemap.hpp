#pragma once
#include "rect.hpp"

/**
\defgroup Rect_idiot
@{
\brief Простые прямоугольники

Описание всех основных вычислений и понятий для параллельных осям прямоугольников
*/

///Размер тайла в пикселях
const int TILE_SIZE = 50;

///Тайловая карта
/**
\param sizeX,sizeY Размер тайловой карты
\param tiles Двумерный массив тайлов
*/
struct Tilemap
{
    int sizeX, sizeY;
    char** tiles;
};
///Инициализация тайловой карты
/**
\param tiles Тайловая карта
*/
void initTilemap(Tilemap& tiles);

///Освободить память тайловой карты
/**
\param tiles Тайловая карта
*/
void freeTilemap(Tilemap& tiles);

///Загрузить карту из файла
/**
\param name Имя файла
\param tiles Тайловая карта
*/
void loadTilemap(const char* name, Tilemap& tiles);

///Возвращает видимый прямоугольник тайла
/**
\param x,y
\return Rect Видимый прямоугольник тайла
*/
Rect tileToRect(int x,int y);

///@}
