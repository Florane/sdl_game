#include "complex_collision.hpp"
#include <cstdio>

void tilemapToStack(Object& parent, Tilemap& tilemap, ObjectStack& stack)
{
    Rect checkSize = parent.position;
    checkSize.size = {checkSize.size.x+_abs(parent.movement.x),checkSize.size.y+_abs(parent.movement.y)};
    if(parent.movement.x < 0)
        checkSize.pos.x+=parent.movement.x;
    if(parent.movement.y < 0)
        checkSize.pos.y+=parent.movement.y;
    checkSize.pos = multVectorNumber(checkSize.pos,1/50.0);
    checkSize.size = multVectorNumber(checkSize.size,1/50.0);
    for(int x = 0;x < checkSize.size.x+1;x++)
    {
        int _x = x+checkSize.pos.x;
        for(int y = 0;y < checkSize.size.y+1;y++)
        {
            int _y = y+checkSize.pos.y;
            if(_x >= 0 && _y >= 0 && _x < tilemap.sizeX && _y < tilemap.sizeY)
            {
                if(tilemap.tiles[_x][_y] != 0)
                {
                    Object object;
                    initObject(object,tileToRect(_x,_y));
                    setObject(parent,stack,object);
                }
            }
        }
    }
}

void platformsToStack(Object& parent, PlatformFactory& platforms, ObjectStack& stack)
{
    Rect checkSize1 = parent.position;
    checkSize1.size = {checkSize1.size.x+_abs(parent.movement.x),checkSize1.size.y+_abs(parent.movement.y)};
    if(parent.movement.x < 0)
        checkSize1.pos.x+=parent.movement.x;
    if(parent.movement.y < 0)
        checkSize1.pos.y+=parent.movement.y;

    for(int i = 0;i < platforms.size;i++)
    {
        Rect checkSize2 = platforms.platforms[i].position;
        checkSize2.size = {checkSize2.size.x+_abs(platforms.platforms[i].speed.x),checkSize2.size.y+_abs(platforms.platforms[i].speed.y)};
        if(platforms.platforms[i].speed.x < 0)
            checkSize2.pos.x+=platforms.platforms[i].speed.x;
        if(platforms.platforms[i].speed.y < 0)
            checkSize2.pos.y+=platforms.platforms[i].speed.y;
        if(collideRectRect(&checkSize1,&checkSize2))
        {
            Object object;
            initObject(object,platforms.platforms[i].position,platforms.platforms[i].speed);
            setObject(parent,stack,object);
        }
    }
}
