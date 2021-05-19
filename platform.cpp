#include "platform.hpp"

#include <math.h>

void initPlatform(Platform& platform, Rect position, Rect movement, double speed, char mainDiagonal)
{
    platform.position = position;
    platform.movement = movement;

    double diagonal = sqrt((movement.size.x*movement.size.x)+(movement.size.y*movement.size.y));
    double normalX = movement.size.x/diagonal;
    double normalY = movement.size.y/diagonal;

    platform.speed.x = speed*normalX;
    platform.speed.y = speed*(int)(mainDiagonal)*normalY;
    platform.checkBoundary = true;
}

void stepPlatform(Platform& platform)
{
    platform.position.pos = addVectors(platform.position.pos,platform.speed);

    if(platform.position.pos.x > platform.movement.pos.x+platform.movement.size.x ||
        platform.position.pos.x < platform.movement.pos.x ||
        platform.position.pos.y > platform.movement.pos.y+platform.movement.size.y ||
        platform.position.pos.y < platform.movement.pos.y)
    {
        if(platform.checkBoundary)
        {
            platform.speed.x = -platform.speed.x;
            platform.speed.y = -platform.speed.y;
            platform.checkBoundary = false;
        }
    }
    else
    {
        platform.checkBoundary = true;
    }
}
