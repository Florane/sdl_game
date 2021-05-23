#include "level.hpp"

#include <stdlib.h>
#include <string.h>

void initLevel(Level& level)
{
    initPlayer(level.player);
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
    char* playerName = (char*)calloc(strlen(name)+11,sizeof(char));

    #ifdef __linux__
        strcpy(playerName,name);
        strncat(playerName,"player.txt",11);
    #elif _WIN32
        strcpy_s(playerName,strlen(name)+11,name);
        strncat_s(playerName,strlen(name)+11,"player.txt",11);
    #endif

    loadPlayer(playerName,level.player);
    free(playerName);

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

    char* exitName = (char*)calloc(strlen(name)+9,sizeof(char));
    #ifdef __linux__
        strcpy(exitName,name);
        strncat(exitName,"exit.txt",9);
    #elif _WIN32
        strcpy_s(exitName,strlen(name)+9,name);
        strncat_s(exitName,strlen(name)+9,"exit.txt",9);
    #endif

    loadPlatforms(exitName,level.exit);
    free(exitName);
}
