#include <stdio.h>
#include <stdlib.h>
#include "tilemap.hpp"

void initTilemap(Tilemap& tiles)
{
    tiles.sizeX = 0; tiles.sizeY = 0;
    tiles.tiles = nullptr;
}

void freeTilemap(Tilemap& tiles)
{
    if(tiles.tiles != nullptr)
    {
        for(int i = 0;i < tiles.sizeX;i++)
        {
            if(tiles.tiles[i] != nullptr)
                free(tiles.tiles[i]);
        }
        free(tiles.tiles);
    }
}

void loadTilemap(const char* name, Tilemap& tiles)
{
    FILE* file;
    #ifdef __linux__
        file = fopen(name,"r");
        fscanf(file,"%d",&tiles.sizeX);
        fscanf(file,"%d",&tiles.sizeY);
    #elif _WIN32
        fopen_s(&file,name,"r");
        fscanf_s(file,"%d",&tiles.sizeX);
        fscanf_s(file,"%d",&tiles.sizeY);
    #endif

    tiles.tiles = (char**)calloc(tiles.sizeX,sizeof(char*));
    for(int i = 0;i < tiles.sizeX;i++)
    {
        tiles.tiles[i] = (char*)calloc(tiles.sizeY,sizeof(char));
    }

    for(int y = 0;y < tiles.sizeY;y++)
    {
        for(int x = 0;x < tiles.sizeX; x++)
        {
            #ifdef __linux__
                fscanf(file,"%d",&tiles.tiles[x][y]);
            #elif _WIN32
                fscanf_s(file,"%d",&tiles.tiles[x][y]);
            #endif
        }
    }
    fclose(file);
}

Rect tileToRect(int x, int y)
{
    Rect r = {x*TILE_SIZE,y*TILE_SIZE,TILE_SIZE,TILE_SIZE};
    return r;
}
