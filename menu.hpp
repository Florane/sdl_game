#pragma once
#include "rect.hpp"

const int AMOUNT = 4;
struct Buttons
{
    Rect buttons[AMOUNT];
    int selected;
};

void initButtons(Buttons* buttons, int sizeX, int sizeY);
