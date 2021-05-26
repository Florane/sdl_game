#include "score.hpp"
#include <stdio.h>

void loadScore(const char* name, int* score, int* time)
{
    FILE* file;
    #ifdef __linux__
        file = fopen(name,"r");
        fscanf(file,"%d",score);
        fscanf(file,"%d",time);
    #elif _WIN32
        fopen_s(&file,name,"r");
        fscanf_s(file,"%d",score);
        fscanf_s(file,"%d",time);
    #endif
    fclose(file);
}

void saveScore(const char* name, int score, int time)
{
    int maxScore, maxTime;
    FILE* file;
    #ifdef __linux__
        file = fopen(name,"r");
        fscanf(file,"%d",&maxScore);
        fscanf(file,"%d",&maxTime);
    #elif _WIN32
        fopen_s(&file,name,"r");
        fscanf_s(file,"%d",&maxScore);
        fscanf_s(file,"%d",&maxTime);
    #endif
    fclose(file);

    if(score > maxScore)
        maxScore = score;
    if(maxTime > time || maxTime <= 0)
        maxTime = time;

    #ifdef __linux__
        file = fopen(name,"w");
    #elif _WIN32
        fopen_s(&file,name,w);
    #endif
    fprintf(file,"%d\n%d\n",maxScore,maxTime);
    fclose(file);
}
