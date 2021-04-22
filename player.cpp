#include "player.hpp"
#include <iostream>

void initPlayer(Player* player)
{
    player->player = {0,0,100,100};
    player->movement = {0,0};
}

void stepPlayer(Player* player)
{
    player->player.pos = *addVectors(&(player->player.pos),&(player->movement));
}

Rect shiftFromPlayer(const Rect* rect, const Player* player)
{
    Rect r;
    r.pos = *subVectors(&(rect->pos),&(player->player.pos));
    r.size = rect->size;
    return r;
}

void movePlayer_floaty(Player* player, bool keys[4])
{
    const double speed = 1.0;
    if(keys[0])
        player->movement.x = -speed;
    else if(keys[1])
        player->movement.x = speed;
    else
        player->movement.x = 0;

    if(keys[2])
        player->movement.y = -speed;
    else if(keys[3])
        player->movement.y = speed;
    else
        player->movement.y = 0;
}

bool collidePlayerRect(const Player* player, const Rect* rect, Vector* contact, Vector* normal, double* time)
{
    if(player->movement.x == 0 && player->movement.y == 0)
        return false;

    Rect expandedTarget;
    Vector buffer = {player->player.size.x/2.0,player->player.size.y/2.0};
    expandedTarget.pos = *subVectors(&rect->pos,&buffer);
    expandedTarget.size = *addVectors(&rect->size,&player->player.size);

    Vector buffer2 = *addVectors(&player->player.pos,&buffer); //Не работает иначе - возможно ошибки с указателями (стоит заменить на ссылки)
    if(collideRayRect(&buffer2,&player->movement,&expandedTarget, contact, normal, time))
    {
        return (*time >= 0.0 && *time < 1.0);
    }
    return false;
}

bool resolvePlayerRect(Player* player, const Rect* rect)
{
    Vector contact, normal;
    double time = 0.0;
    if(collidePlayerRect(player,rect,&contact,&normal,&time))
    {
        Vector buffer = {_abs(player->movement.x)*(1-time),_abs(player->movement.y)*(1-time)};
        player->movement = *addVectors(&player->movement,multVectors(&normal,&buffer));
        std::cout << player->movement.x << " " << player->movement.y << std::endl;
        return true;
    }
    return false;
}
