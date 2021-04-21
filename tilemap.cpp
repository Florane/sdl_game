#include <stdio.h>
#include "tilemap.hpp"

void loadTilemap(const char* name, Tilemap* tilemap)
{
    FILE* file;

    #ifdef __linux__
        file = fopen(name, "r");
    #elif _WIN32
        fopen_s(file, name, "r");
    #endif

    for(int y = 0;y < SIZE_X;y++)
    {
        for(int x = 0;x < SIZE_Y;x++)
        {
            #ifdef __linux__
                fscanf(file, "%d", &tilemap->tiles[x][y]);
            #elif _WIN32
                fscanf_s(file, "%d", &tilemap->tiles[x][y]);
            #endif
        }
    }
    fclose(file);
}

void saveTilemap(const char* name, Tilemap* tilemap)
{
    FILE* file;

    #ifdef __linux__
        file = fopen(name, "r");
    #elif _WIN32
        fopen_s(file, name, "r");
    #endif
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
