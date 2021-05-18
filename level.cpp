#include "level.hpp"

#include <stdlib.h>
#include <string.h>

void initLevel(Level& level)
{
    initTilemap(level.ground);
}

void freeLevel(Level& level)
{
    freeTilemap(level.ground);
}

void loadLevel(const char* name, Level& level)
{
    //загрузка земли
    char* groundName = (char*)calloc(strlen(name)+12,sizeof(char));
    strcpy(groundName,name);
    strncat(groundName,"tilemap.txt",12);

    loadTilemap(groundName,level.ground);
    free(groundName);
}
