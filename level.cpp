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

    #ifdef __linux__
        strcpy(groundName,name);
        strncat(groundName,"tilemap.txt",12);
    #elif _WIN32
        strcpy_s(groundName,strlen(name)+12,name);
        strncat_s(groundName,strlen(name)+12,"tilemap.txt",12);
    #endif


    loadTilemap(groundName,level.ground);
    free(groundName);

    //загрузка тайлов
    char* platformName = (char*)calloc(strlen(name)+14,sizeof(char));
    #ifdef __linux__
        strcpy(platformName,name);
        strncat(platformName,"platforms.txt",14);
    #elif _WIN32
        strcpy_s(platformName,strlen(name)+14,name);
        strncat_s(platformName,strlen(name)+14,"platforms.txt",14);
    #endif

    loadPlatforms(platformName,level.platforms);
    free(platformName);
}
