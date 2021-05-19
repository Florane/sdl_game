#include "complex_platforms.hpp"
#include "rect.hpp"
#include "draw.hpp"

void drawPlatforms(SDL_Renderer*& renderer, PlatformFactory& platforms, Player& player, SDL_Texture* platformTexture)
{
    Rect screen = {-350,-250,800,600};
    screen.pos = addVectors(screen.pos,player.player.pos);
    for(int i = 0;i < platforms.size;i++)
    {
        if(collideRectRect(&screen,&platforms.platforms[i].position))
        {
            SDL_Rect rect = rectToSDL_Rect(shiftFromPlayer(platforms.platforms[i].position,player));
            drawTexture(renderer, platformTexture, &rect);
        }
    }
}

void stepPlatforms(PlatformFactory& platforms)
{
    for(int i = 0;i < platforms.size;i++)
    {
        stepPlatform(platforms.platforms[i]);
    }
}
