#include "platformFactory.hpp"

#include <stdlib.h>
#include <stdio.h>

void initPlatformFactory(PlatformFactory& factory)
{
    factory.platforms = nullptr;
    factory.size = 0;
}

void freePlatformFactory(PlatformFactory& factory)
{
    if(factory.platforms != nullptr)
        free(factory.platforms);
}

void loadPlatforms(const char* name, PlatformFactory& factory)
{
    FILE* file;
    #ifdef __linux__
        file = fopen(name,"r");
        fscanf(file,"%d",&factory.size);
    #elif _WIN32
        fopen_s(&file,name,"r");
        fscanf_s(file,"%d",&factory.size);
    #endif

    factory.platforms = (Platform*)calloc(factory.size,sizeof(Platform));
    for(int i = 0;i < factory.size;i++)
    {
        double buffer[9];
        for(int j = 0;j < 9;j++)
        {
            #ifdef __linux__
                fscanf(file,"%lf",&buffer[j]);
            #elif _WIN32
                fscanf_s(file,"%lf",&buffer[j]);
            #endif
        }
        Rect pos = {buffer[0],buffer[1],buffer[2],buffer[3]};
        Rect mov = {buffer[4],buffer[5],buffer[6],buffer[7]};
        double speed = buffer[8];
        int md;
        #ifdef __linux__
            fscanf(file,"%d",&md);
        #elif _WIN32
            fscanf_s(file,"%d",&md);
        #endif
        initPlatform(factory.platforms[i],pos,mov,speed,(char)md);
    }
    fclose(file);
}
