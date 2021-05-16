#include "menu.hpp"
#include <stdio.h>
#include <stdlib.h>

void initButtons(Buttons* buttons)
{
    Rect* buffer = (Rect*)malloc(sizeof(Rect));
    buffer[0] = {0,0,0,0};
    buttons->buttons = buffer;
    buttons->amount = 1;
    buttons->selected = 0;
}

void loadButtons(const char* name, Buttons* buttons)
{
    FILE* file;
    int size;

    #ifdef __linux__
        file = fopen(name, "r");
        fscanf(file, "%d", &size);
    #elif _WIN32
        fopen_s(&file, name, "r");
        fscanf_s(file, "%d", &size);
    #endif

    buttons->amount = size;
    buttons->buttons = (Rect*)realloc(buttons->buttons,size*sizeof(Rect));

    for(int i = 0;i < size;i++)
    {
        #ifdef __linux__
            fscanf(file, "%lf", &buttons->buttons[i].pos.x);
            fscanf(file, "%lf", &buttons->buttons[i].pos.y);
            fscanf(file, "%lf", &buttons->buttons[i].size.x);
            fscanf(file, "%lf", &buttons->buttons[i].size.y);
        #elif _WIN32
            fscanf_s(file, "%lf", &buttons->buttons[i].pos.x);
            fscanf_s(file, "%lf", &buttons->buttons[i].pos.y);
            fscanf_s(file, "%lf", &buttons->buttons[i].size.x);
            fscanf_s(file, "%lf", &buttons->buttons[i].size.y);
        #endif
    }
    buttons->selected = -1;
}

void cleanSelect(Buttons* buttons)
{
    while(buttons->selected < 0 || buttons->selected >= buttons->amount)
    {
        if(buttons->selected < 0)
            buttons->selected+=buttons->amount;
        else if(buttons->selected >= buttons->amount)
            buttons->selected-=buttons->amount;
    }
}

void up(Buttons* buttons)
{
    buttons->selected++;
    cleanSelect(buttons);
}

void down(Buttons* buttons)
{
    buttons->selected--;
    cleanSelect(buttons);
}
