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
    printf("_\n");
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
                    printf("%d %d\n",_x,_y);
                    Object object;
                    initObject(object,tileToRect(_x,_y));
                    setObject(parent,stack,object);
                }
            }
        }
    }
}
