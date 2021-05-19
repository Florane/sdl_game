#pragma once
#include "rect.hpp"

struct Platform
{
    Rect position;
    Rect movement;
    Vector speed;
    bool checkBoundary;
};

void initPlatform(Platform& platform, Rect position, Rect movement, double speed, char mainDiagonal);

void stepPlatform(Platform& platform);
