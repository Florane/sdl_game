#include "draw.hpp"

void loadTexture(const char* name,SDL_Renderer* renderer,SDL_Texture** texture)
{
    SDL_Surface* surface = SDL_LoadBMP(name);
    SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 255, 255));
    (*texture) = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
}

void drawTexture(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect* rect)
{
	SDL_RenderCopy(renderer, texture, NULL, rect);
}

SDL_Rect rectToSDL_Rect(Rect r)
{
    SDL_Rect rect = {r.pos.x,r.pos.y,r.size.x,r.size.y};
    return rect;
}
