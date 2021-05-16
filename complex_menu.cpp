#include "complex_menu.hpp"
#include "draw.hpp"

void drawButtons(SDL_Renderer* renderer, Buttons* buttons, SDL_Texture**buttonTextures)
{
    for(int i = 0;i < buttons->amount;i++)
    {
        SDL_Rect rect = rectToSDL_Rect(buttons->buttons[i]);
        drawTexture(renderer, buttonTextures[i], &rect);
        if(i == buttons->selected)
        {
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
            SDL_RenderDrawRect(renderer, &rect);
        }
    }
}

int selectButton(Buttons* buttons,const Vector* point)
{
    for(int i = 0;i < buttons->amount;i++)
    {
        int j = buttons->amount-i-1;
        if(point->x >= buttons->buttons[j].pos.x &&
        point->x <= buttons->buttons[j].pos.x+buttons->buttons[j].size.x &&
        point->y >= buttons->buttons[j].pos.y &&
        point->y <= buttons->buttons[j].pos.y+buttons->buttons[j].size.y)
        {
            return j;
        }
    }
    return -1;
}
