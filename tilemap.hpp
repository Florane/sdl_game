#pragma once
#include "rect.hpp"

const int TILE_SIZE = 50;

struct Tilemap
{
    int sizeX, sizeY;
    int** tiles;
};

Rect tileToRect(int x,int y);
