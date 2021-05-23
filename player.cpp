#include "player.hpp"
#include <stdio.h>

void initPlayer(Player& player)
{
    player.player = {0,0,100,100};
    player.movement = {0,0};
    player.isOnGround = false;
}

void loadPlayer(const char* name, Player& player)
{
    FILE* file;
    #ifdef __linux__
        file = fopen(name,"r");
        fscanf(file,"%lf",&player.player.pos.x);
        fscanf(file,"%lf",&player.player.pos.y);
    #elif _WIN32
        fopen_s(&file,name,"r");
        fscanf_s(file,"%lf",&player.player.pos.x);
        fscanf_s(file,"%lf",&player.player.pos.y);
    #endif
    fclose(file);
}

void stepPlayer(Player& player)
{
    player.player.pos = addVectors(player.player.pos,player.movement);
}

Rect shiftFromPlayer(const Rect& rect, const Player& player)
{
    Rect r;
    Vector actual = {350,250};
    r.pos = subVectors(rect.pos,player.player.pos);
    r.pos = addVectors(r.pos,actual);
    r.size = rect.size;
    return r;
}

void movePlayer_floaty(Player& player, char* keys)
{
    const double speed = 3.0;
    if(keys[0] == 1)
        player.movement.x = -speed;
    else if(keys[1] == 1)
        player.movement.x = speed;
    else
        player.movement.x = 0;

    if(keys[2] == 1)
        player.movement.y = -speed;
    else if(keys[3] == 1)
        player.movement.y = speed;
    else
        player.movement.y = 0;
    player.isOnGround = false;
}

void movePlayer_actually(Player& player, char* keys)
{
    const double speed = 3.0;
    const double gravity = 0.2;
    const double jump = 7.0;
    if(keys[0] == 1)
        player.movement.x = -speed;
    else if(keys[1] == 1)
        player.movement.x = speed;
    else
        player.movement.x = 0;

    if(keys[2] == 1 && player.isOnGround)
        player.movement.y = -jump;
    player.movement.y += gravity;
    player.isOnGround = false;
}
