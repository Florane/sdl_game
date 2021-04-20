#include <stdio.h>
#include "tilemap.hpp"

void loadTilemap(const char* name, Tilemap* tilemap)
{
    FILE* file;

    file = fopen(name, "r");
    for(int y = 0;y < SIZE_X;y++)
    {
        for(int x = 0;x < SIZE_Y;x++)
        {
            fscanf(file, "%d", &tilemap->tiles[x][y]);
        }
    }
    fclose(file);
}

void saveTilemap(const char* name, Tilemap* tilemap)
{
    FILE* file;

    file = fopen(name, "w+");
    for(int y = 0;y < SIZE_X;y++)
    {
        for(int x = 0;x < SIZE_Y;x++)
        {
            fprintf(file, "%d ", tilemap->tiles[x][y]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

Rect tileToRect(int x, int y)
{
    Rect r = {x*TILE_SIZE,y*TILE_SIZE,TILE_SIZE,TILE_SIZE};
    return r;
}
