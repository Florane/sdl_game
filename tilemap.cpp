#include "tilemap.hpp"

Rect tileToRect(int x, int y)
{
    Rect r = {x*TILE_SIZE,y*TILE_SIZE,TILE_SIZE,TILE_SIZE};
    return r;
}
