#ifdef __linux__
    #include <SDL2/SDL.h>
#elif _WIN32
    #include <SDL.h>
#endif

#include <stdio.h>
#include <locale.h>
#include <iostream>

#include "draw.hpp"
#include "tilemap.hpp"
#include "player.hpp"
#include "menu.hpp"

///все комменты с тремя слешами удали перед сдачей

const int SCR_WIDTH = 800;
const int SCR_HEIGHT = 600;
const int TILES_COUNT = 3;
const int KEYS = 4+1+4+10;
const bool debug = false;

void drawTilemap(SDL_Renderer* renderer, Tilemap* tilemap, SDL_Texture** tiles, Player* player)
{
    for(int x = 0;x < SIZE_X;x++)
    {
        for(int y = 0;y < SIZE_Y;y++)
        {
            if(tilemap->tiles[x][y] != 0)
            {
                 Rect r = tileToRect(x,y);
                SDL_Rect rect = rectToSDL_Rect(shiftFromPlayer(&r, player));
                drawTexture(renderer, tiles[(tilemap->tiles[x][y])-1], &rect);
            }
        }
    }
}

void drawButtons(SDL_Renderer* renderer, Buttons* buttons, SDL_Texture**buttonTextures, int shiftX, int shiftY)
{
    for(int i = 0;i < AMOUNT;i++)
    {
        Rect r = buttons->buttons[i];
        Vector shift = {shiftX,shiftY};
        r.pos = *addVectors(&r.pos,&shift);
        SDL_Rect rect = rectToSDL_Rect(r);
        drawTexture(renderer, buttonTextures[i], &rect);
        if(i == buttons->selected)
        {
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
            SDL_RenderDrawRect(renderer, &rect);
        }
    }
}

int main(int argc, char** argv)
{
    //инициализация
    SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	setlocale(LC_ALL, "Russian");

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
        return 1;
	}

	window = SDL_CreateWindow("Test1", 100,100, SCR_WIDTH, SCR_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("Could not create window: %s\n", SDL_GetError());
        return 2;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    //загружаем текстуры
    SDL_Texture *heroTexture, *bgTexture, *platformTexture;

    const SDL_Rect heroRect = {350,250,100,100};
    loadTexture("textures/cat.bmp",renderer,&heroTexture);
    const SDL_Rect bgRect = {0,0,SCR_WIDTH,SCR_HEIGHT};
    loadTexture("textures/bg.bmp",renderer,&bgTexture); ///вместо разных текстурок, у тебя есть одна текстура бэкграунда размером с экран.
    loadTexture("textures/platform.bmp",renderer,&platformTexture);

    SDL_Texture* tiles[TILES_COUNT];
    loadTexture("textures/tiles/land.bmp",renderer,&tiles[0]);
    loadTexture("textures/tiles/grass.bmp",renderer,&tiles[1]);
    loadTexture("textures/tiles/box.bmp", renderer, &tiles[2]);

    Buttons buttons;
    initButtons(&buttons,SCR_WIDTH-200,SCR_HEIGHT-40);

    SDL_Texture* buttonTextures[AMOUNT];
    loadTexture("textures/buttons/logo.bmp",renderer,&buttonTextures[0]);
    loadTexture("textures/buttons/button1.bmp",renderer,&buttonTextures[1]);
    loadTexture("textures/buttons/button2.bmp",renderer,&buttonTextures[2]);

    //загружаем карту
    Tilemap tilemap;
    loadTilemap("load.txt",&tilemap);

    //загружаем игрока
    Player player;
    initPlayer(&player);

    Vector cursor = {0,0};

    //проверка нажатия кнопок
    bool pressed[KEYS] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    const SDL_Keycode checkKeys[KEYS] = {SDLK_a,SDLK_d,SDLK_w,SDLK_s,SDLK_SPACE
        ,SDLK_LEFT,SDLK_RIGHT,SDLK_UP,SDLK_DOWN
        ,SDLK_0,SDLK_1,SDLK_2,SDLK_3,SDLK_4,SDLK_5,SDLK_6,SDLK_7,SDLK_8,SDLK_9};

    bool keyLock[4] = {0,0,0,0};

    int state = 0;
    //главный цикл
    while(true)
    {
        ///не выноси event из цикла - он из-за этого сохраняет предыдущий ивент, что создает лаг у кнопок
        SDL_Event event;
        SDL_PollEvent(&event);
		if (event.type == SDL_QUIT || state == 3)
			break;
        //проверка нажатия кнопок
        if(event.type == SDL_KEYDOWN)
        {
            for(int i = 0;i < KEYS;i++)
            {
                if(event.key.keysym.sym == checkKeys[i])
                pressed[i] = true;
            }
        }
        else if(event.type == SDL_KEYUP)
        {
            for(int i = 0;i < KEYS;i++)
            {
                if(event.key.keysym.sym == checkKeys[i])
                pressed[i] = false;
                if(i >= 5 && i <= 8)
                    keyLock[i-5] = false;
            }
        }

        //преверка кнопок в меню
        if(state == 0)
        {
            if(pressed[2])
            {
                buttons.selected--;
                if(buttons.selected < 1)
                    buttons.selected = 2;
                pressed[2] = false;
            }
            else if(pressed[3])
            {
                buttons.selected++;
                if(buttons.selected > 2)
                    buttons.selected = 1;
                pressed[3] = false;
            }
            else if(pressed[4])
            {
                state = buttons.selected;
                if (state == 1 && debug)
                    state = 2;
            }
        }
        //проверка физики
        else if(state == 1 || state == 2)
        {
            movePlayer_floaty(&player,pressed);

            Rect r = tileToRect(cursor.x,cursor.y);
            r = shiftFromPlayer(&r,&player);
            Player actualPlayer = player;
            actualPlayer.player.pos = {350,250};
            resolvePlayerRect(&actualPlayer,&r);
            player.movement = actualPlayer.movement;

            stepPlayer(&player);
            if(state == 2)
            {
                if(pressed[5] && !keyLock[0] && cursor.x > 0)
                {
                    keyLock[0] = true;
                    cursor.x--;
                }
                else if(pressed[6] && !keyLock[1] && cursor.x < SIZE_X-1)
                {
                    keyLock[1] = true;
                    cursor.x++;
                }
                if(pressed[7] && !keyLock[2] && cursor.y > 0)
                {
                    keyLock[2] = true;
                    cursor.y--;
                }
                else if(pressed[8] && !keyLock[3] && cursor.y < SIZE_X-1)
                {
                    keyLock[3] = true;
                    cursor.y++;
                }

                for(int i = 0;i < TILES_COUNT+1;i++)
                {
                    if(pressed[9+i])
                    {
                        int x = cursor.x, y = cursor.y;
                        tilemap.tiles[x][y] = i;
                    }
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 51, 153, 255, 0);
		SDL_RenderClear(renderer);

        drawTexture(renderer, bgTexture, &bgRect);
        if(state == 0)
        {
            drawButtons(renderer, &buttons, buttonTextures, 100, 20);
        }
        else if(state == 1 || state == 2)
        {
            drawTilemap(renderer, &tilemap, tiles, &player);
            drawTexture(renderer, heroTexture, &heroRect);
            if(state == 2)
            {
                Rect r = tileToRect(cursor.x,cursor.y);
                r = shiftFromPlayer(&r,&player);
                SDL_Rect r2 = rectToSDL_Rect(r);
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
                SDL_RenderDrawRect(renderer, &r2);
            }
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }
    saveTilemap("load.txt",&tilemap);
    SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
