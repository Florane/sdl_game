#include "player.hpp"

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
