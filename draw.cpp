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

void drawText(SDL_Renderer*& renderer,TTF_Font*& my_font, char*& text, int x, int y, int size)
{
    SDL_Color fore_color = {0,0,0};

    SDL_Surface* textSurface = NULL;
    textSurface = TTF_RenderText_Solid(my_font, text, fore_color);

    SDL_Rect rect = { x,y,(int)((size/2.0)*strlen(text)),size };
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);

    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(textSurface);
}
