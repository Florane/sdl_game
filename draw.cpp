#include "draw.hpp"
#include <SDL2/SDL_ttf.h>

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

void drawText(SDL_Renderer*& renderer, char*& text, int x, int y, int size)
{
    TTF_Init();

    TTF_Font* my_font = TTF_OpenFont("DejaVuSansMono.ttf", 100);
    SDL_Color fore_color = {0,0,0};
    SDL_Color back_color = {255,255,255,0};

    SDL_Surface* textSurface = NULL;
    textSurface = TTF_RenderText_Shaded(my_font, text, fore_color, back_color);

    SDL_Rect rect = { x,y,(int)((size/2.0)*strlen(text)),size };
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);

    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(textSurface);
    TTF_CloseFont(my_font);

    TTF_Quit();
}
