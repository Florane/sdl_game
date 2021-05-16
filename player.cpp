#include "player.hpp"
#include <iostream>

void initPlayer(Player& player)
{
    player.player = {0,0,100,100};
    player.movement = {0,0};
    player.isOnGround = false;
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
    const double gravity = 0.1;
    const double jump = 5.0;
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

bool collidePlayerRect(const Player* player, const Rect* rect, Vector& contact, Vector& normal, double& time)
{
    if(player->movement.x == 0 && player->movement.y == 0)
        return false;

    Rect expandedTarget;
    Vector buffer = {player->player.size.x/2.0,player->player.size.y/2.0};
    expandedTarget.pos = subVectors(rect->pos,buffer);
    expandedTarget.size = addVectors(rect->size,player->player.size);

    if(collideRayRect(addVectors(player->player.pos,buffer),player->movement,expandedTarget, contact, normal, time))
    {
        return (time >= 0.0 && time < 1.0);
    }
    return false;
}

bool collidePlayerRect(const Player* player, const Rect* rect)
{
    Vector contact, normal;
    double time = 0.0;
    return collidePlayerRect(player,rect,contact,normal,time);
}

bool resolvePlayerRect(Player* player, const Rect* rect)
{
    Vector contact, normal;
    double time = 0.0;
    if(collidePlayerRect(player,rect,contact,normal,time))
    {
        Vector buffer = {_abs(player->movement.x)*(1-time),_abs(player->movement.y)*(1-time)};
        player->movement = addVectors(player->movement,multVectors(normal,buffer));
        return true;
    }
    return false;
}

bool resolvePlayerRect(Player* player, const Rect* rect, Vector& normal)
{
    Vector contact;
    double time = 0.0;
    if(collidePlayerRect(player,rect,contact,normal,time))
    {
        Vector buffer = {_abs(player->movement.x)*(1-time),_abs(player->movement.y)*(1-time)};
        player->movement = addVectors(player->movement,multVectors(normal,buffer));
        return true;
    }
    return false;
}
