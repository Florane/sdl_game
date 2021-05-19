#include "level.hpp"

#include <stdlib.h>
#include <string.h>

void initLevel(Level& level)
{
    initTilemap(level.ground);
    initPlatformFactory(level.platforms);
}

void freeLevel(Level& level)
{
    freeTilemap(level.ground);
    freePlatformFactory(level.platforms);
}

void loadLevel(const char* name, Level& level)
{
    //загрузка земли
    char* groundName = (char*)calloc(strlen(name)+12,sizeof(char));
    strcpy(groundName,name);
    strncat(groundName,"tilemap.txt",12);

    loadTilemap(groundName,level.ground);
    free(groundName);

    //загрузка тайлов
    char* platformName = (char*)calloc(strlen(name)+14,sizeof(char));
    strcpy(platformName,name);
    strncat(platformName,"platforms.txt",14);

    loadPlatforms(platformName,level.platforms);
    free(platformName);
}
