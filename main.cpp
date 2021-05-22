#ifdef __linux__
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_ttf.h>
#elif _WIN32
    #include <SDL.h>
    #include <SDL_ttf.h>
#endif

#include <stdio.h>
#include <locale.h>
#include <string.h>

#include "draw.hpp"
#include "tilemap.hpp"
#include "player.hpp"
#include "level.hpp"
#include "complex_menu.hpp"
#include "complex_tilemap.hpp"
#include "complex_platforms.hpp"
#include "collision.hpp"

///все комменты с тремя слешами удали перед сдачей

const int SCR_WIDTH = 800;
const int SCR_HEIGHT = 600;
const int KEYS = 4+2+4+10;
const int MOUSE_KEYS = 1;

int main(int argc, char** argv)
{
    //Инициализация окна
    SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	setlocale(LC_ALL, "Russian");

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
        return 1;
	}

    TTF_Init();

	window = SDL_CreateWindow("Test1", 100,100, SCR_WIDTH, SCR_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("Could not create window: %s\n", SDL_GetError());
        return 2;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    //Информация для дебага
    const bool debug_cursor = true;
    Vector debug_cursor_pos = {0,0};

    const bool debug_info = true;
    int debug_font_size = 20;
    TTF_Font* debug_font = TTF_OpenFont("DejaVuSansMono.ttf", debug_font_size*2);

    const bool debug_player_info = true;
    const bool debug_physics_info = true;
    const bool debug_frame_info = true;

    int debug_info_size = 1+(debug_player_info ? 3 : 0)+(debug_physics_info ? 2 : 0)+(debug_frame_info ? 1 : 0);
    char** debug_info_str = (char**)calloc(debug_info_size,sizeof(char*));
    for(int i = 0;i < debug_info_size;i++)
    {
        debug_info_str[i] = (char*)calloc(64,sizeof(char));
    }

    const bool debug_movement = true;
    const bool debug_physics = true;
    bool debug_collision = true;
    Vector debug_normal = {0,0};
    const bool debug_level = true;

    double debug_frame = 0;

    //Стартовый экран
    Buttons startScreen;
    initButtons(&startScreen);
    loadButtons("menu/startscreen.txt", &startScreen);

    SDL_Texture** startScreenTextures = (SDL_Texture**)calloc((startScreen.amount),sizeof(SDL_Texture*));
    loadTexture("textures/bg.bmp",renderer,startScreenTextures);

    //Главное меню
    Buttons mainMenu, mainMenuTitle;
    initButtons(&mainMenu);
    loadButtons("menu/mainmenu.txt", &mainMenu);
    initButtons(&mainMenuTitle);
    loadButtons("menu/mainmenutitle.txt", &mainMenuTitle);

    SDL_Texture** mainMenuTextures = (SDL_Texture**)calloc((mainMenu.amount+mainMenuTitle.amount),sizeof(SDL_Texture*));
    loadTexture("textures/bg.bmp",renderer,mainMenuTextures);
    loadTexture("textures/buttons/logo.bmp",renderer,mainMenuTextures+1);
    loadTexture("textures/buttons/button1.bmp",renderer,mainMenuTextures+2);
    loadTexture("textures/buttons/button3.bmp",renderer,mainMenuTextures+3);

    //Меню выбора уровней
    Buttons levelMenu, levelMenuBg;
    initButtons(&levelMenu);
    loadButtons("menu/levels.txt", &levelMenu);
    initButtons(&levelMenuBg);
    loadButtons("menu/levelsbg.txt", &levelMenuBg);

    SDL_Texture** levelMenuTextures = (SDL_Texture**)calloc((levelMenu.amount+levelMenuBg.amount),sizeof(SDL_Texture*));
    loadTexture("textures/bg.bmp",renderer,levelMenuTextures);
    loadTexture("textures/buttons/levels/1.bmp",renderer,levelMenuTextures+1);
    loadTexture("textures/buttons/levels/2.bmp",renderer,levelMenuTextures+2);
    loadTexture("textures/buttons/levels/3.bmp",renderer,levelMenuTextures+3);
    loadTexture("textures/buttons/levels/4.bmp",renderer,levelMenuTextures+4);

    //Игрок
    Player player;
    initPlayer(player);

    SDL_Texture* playerTexture;
    loadTexture("textures/cat.bmp",renderer,&playerTexture);

    //Уровень
    Level level;
    initLevel(level);

    ObjectStack objects;
    initObjectStack(objects,2);

    //Текстуры тайлов
    SDL_Texture** groundTileset = (SDL_Texture**)calloc(3,sizeof(SDL_Texture*));
    loadTexture("textures/tiles/land.bmp",renderer,groundTileset);
    loadTexture("textures/tiles/grass.bmp",renderer,groundTileset+1);
    loadTexture("textures/tiles/box.bmp",renderer,groundTileset+2);

    //Текстура платформы
    SDL_Texture* platformTexture;
    loadTexture("textures/platform.bmp",renderer,&platformTexture);

    //Проверка нажатых кнопок (char для экономии памяти)
    //0 - стандартное состояние
    //1 - кнопка нажата
    //-1 - кнопка нажата, процесс выполнен
    char pressed[KEYS] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    const SDL_Keycode checkKeys[KEYS] = {SDLK_a,SDLK_d,SDLK_w,SDLK_s,SDLK_SPACE,SDLK_ESCAPE //Список кнопок для проверки
        ,SDLK_LEFT,SDLK_RIGHT,SDLK_UP,SDLK_DOWN
        ,SDLK_0,SDLK_1,SDLK_2,SDLK_3,SDLK_4,SDLK_5,SDLK_6,SDLK_7,SDLK_8,SDLK_9};

    //Состояние игры
    //0 - начало
    //1 - главное меню
    //2 - выбор уровня
    //3-100 - загруженный уровень
    int state = 0;

    //Внутриигровой таймер
    int timer = 0;

    //Мышь
    Vector mouse = {0,0}, prevMouse = {0,0};
    char mouseClick = 0;
    while(true)
    {
        //Начало кадра
        long long int start = SDL_GetPerformanceCounter();

        SDL_Event event;
        SDL_PollEvent(&event);
		if (event.type == SDL_QUIT || state == -1)
			{break;}
        //Проверка нажатия клавиатуры
        if(event.type == SDL_KEYDOWN)
        {
            for(int i = 0;i < KEYS;i++)
            {
                if(event.key.keysym.sym == checkKeys[i] && pressed[i] == 0)
                    pressed[i] = 1;
            }
        }
        else if(event.type == SDL_KEYUP)
        {
            for(int i = 0;i < KEYS;i++)
            {
                if(event.key.keysym.sym == checkKeys[i])
                    pressed[i] = 0;
            }
        }
        //Проверка нажатия мыши
        else if(event.type == SDL_MOUSEBUTTONDOWN)
        {
            if(event.button.button == SDL_BUTTON_LEFT && mouseClick == 0)
                mouseClick = 1;
        }
        else if(event.type == SDL_MOUSEBUTTONUP)
        {
            if(event.button.button == SDL_BUTTON_LEFT)
                mouseClick = 0;
        }

        //Обработка движения мыши
        prevMouse = mouse;
        int x,y;
        SDL_GetMouseState(&x,&y);
        mouse = {x,y};

        //Взаимодействие
        if(state == 0) // Таймер для главного экрана
        {
            if(timer >= 75)
            {
                state = 1;
                timer = 0;
            }
            timer++;
        }
        else if(state == 1) //Взаимодействие в меню
        {
            if(mouse.x != prevMouse.x || mouse.y != prevMouse.y)
            {
                int buffer = selectButton(&mainMenu,&mouse);
                if(buffer != -1)
                    mainMenu.selected = buffer;
            }
            if(pressed[2] == 1)
            {
                up(&mainMenu);
                pressed[2] = -1;
            }
            if(pressed[3] == 1)
            {
                down(&mainMenu);
                pressed[3] = -1;
            }
            if(pressed[4] == 1 || mouseClick == 1)
            {
                if(mainMenu.selected == 0)
                    state = 2;
                else if(mainMenu.selected == 1)
                    state = -1;
                if(pressed[4] == 1)
                    pressed[4] = -1;
                if(mouseClick == 1)
                    mouseClick = -1;
            }
            if(pressed[5] == 1)
            {
                state = -1;
                pressed[5] = -1;
            }
        }
        else if(state == 2)
        {
            if(mouse.x != prevMouse.x || mouse.y != prevMouse.y)
            {
                int buffer = selectButton(&levelMenu,&mouse);
                if(buffer != -1)
                    levelMenu.selected = buffer;
            }
            if(pressed[1] == 1)
            {
                up(&levelMenu);
                pressed[1] = -1;
            }
            if(pressed[0] == 1)
            {
                down(&levelMenu);
                pressed[0] = -1;
            }
            if(pressed[4] == 1 || mouseClick == 1)
            {
                if(levelMenu.selected != -1)
                {
                    state = levelMenu.selected+3;
                    char c[30];
                    #ifdef __linux__
                        sprintf(c,"levels/%d/",levelMenu.selected);
                    #elif _WIN32
                        sprintf_s(c,30,"levels/%d/",levelMenu.selected);
                    #endif
                    freeLevel(level);
                    initLevel(level);
                    if(debug_level)
                        loadLevel("levels/debug/",level);
                    else
                        loadLevel(c,level);
                }
                if(pressed[4] == 1)
                    pressed[4] = -1;
                if(mouseClick == 1)
                    mouseClick = -1;
            }
            if(pressed[5] == 1)
            {
                state = 1;
                pressed[5] = -1;
            }
        }
        else if(state >= 3 && state <= 100) //Движение и физика на уровне
        {
            if(pressed[5] == 1)
            {
                state = 2;
                pressed[5] = -1;
            }

            //Движение
            if(debug_movement)
            {
                movePlayer_floaty(player,pressed);
            }
            else
            {
                movePlayer_actually(player,pressed);
            }

            //Физика
            stepPlatforms(level.platforms);
            Rect buffer = tileToRect(debug_cursor_pos.x,debug_cursor_pos.y);
            Rect buffer1 = tileToRect(debug_cursor_pos.x+1,debug_cursor_pos.y);
            Rect buffer2 = tileToRect(debug_cursor_pos.x+2,debug_cursor_pos.y);
            if(debug_physics)
            {
                Object object1, object2;
                initObject(object1, player.player, player.movement);
                initObject(object2, buffer);
                setObject(object1,objects,object2);
                initObject(object2, buffer1);
                setObject(object1,objects,object2);
                initObject(object2, buffer2);
                setObject(object1,objects,object2);
                sortObjectStack(objects);
                int bitData;
                bitData = resolveObjectStack(object1,objects);
                debug_collision = bitData%2;
                player.isOnGround = bitData/2%2;
                objects.iter = 0;
                player.movement = object1.movement;
            }
            else
            {

            }

            //Изменение положения
            stepPlayer(player);
        }

        SDL_SetRenderDrawColor(renderer, 51, 153, 255, 0);
		SDL_RenderClear(renderer);

        //Отрисовка
        if(state == 0)
        {
            drawButtons(renderer, &startScreen, startScreenTextures);
        }
        else if(state == 1)
        {
            drawButtons(renderer, &mainMenuTitle, mainMenuTextures);
            drawButtons(renderer, &mainMenu, mainMenuTextures+2);
        }
        else if(state == 2)
        {
            drawButtons(renderer, &levelMenuBg, levelMenuTextures);
            drawButtons(renderer, &levelMenu, levelMenuTextures+1);
        }
        else if(state >= 3 && state <= 100)
        {
            SDL_Rect playerRect = {350,250,100,100};
            drawTexture(renderer, playerTexture, &playerRect);
            drawTilemap(renderer, level.ground, player, groundTileset);
            drawPlatforms(renderer, level.platforms, player, platformTexture);

            if(debug_cursor) //Дебаг курсор
            {
                SDL_Rect cursorRect = rectToSDL_Rect(shiftFromPlayer(tileToRect(debug_cursor_pos.x,debug_cursor_pos.y),player));
                SDL_SetRenderDrawColor(renderer, 255, 153, 51, 0);
                SDL_RenderDrawRect(renderer, &cursorRect);
            }
            if(debug_info) //Дебаг информация о игре
            {
                int debug_info_y = 0;
                int debug_str_i = 0;

                if(debug_player_info) //Информация о персонаже
                {
                    char c1[64], c2[64], c3[14];
                    #ifdef __linux__
                        sprintf(c1,"pos x:%.1lf y:%.1lf",player.player.pos.x,player.player.pos.y);
                        sprintf(c2,"mov x:%.1lf y:%.1lf",player.movement.x,player.movement.y);
                        sprintf(c3,"ground: %s",(player.isOnGround ? "true" : "false"));

                        strcpy(*(debug_info_str+debug_str_i),c1);
                        strcpy(*(debug_info_str+debug_str_i+1),c2);
                        strcpy(*(debug_info_str+debug_str_i+2),c3);
                    #elif _WIN32
                        sprintf_s(c1,"pos x:%.1lf y:%.1lf",player.player.pos.x,player.player.pos.y);
                        sprintf_s(c2,"mov x:%.1lf y:%.1lf",player.movement.x,player.movement.y);
                        sprintf_s(c3,"ground: %s",(player.isOnGround ? "true" : "false"));

                        strcpy_s(*(debug_info_str+debug_str_i),64,c1);
                        strcpy_s(*(debug_info_str+debug_str_i+1),64,c2);
                        strcpy_s(*(debug_info_str+debug_str_i+2),64,c3);
                    #endif
                    debug_str_i+=3;
                }
                if(debug_physics_info)//Информация о физике
                {
                    char c1[64], c2[64];
                    #ifdef __linux__
                        sprintf(c1,"collision: %s",(debug_collision ? "true" : "false"));
                        sprintf(c2,"normal x:%.1lf y:%.1lf",debug_normal.x,debug_normal.y);

                        strcpy(*(debug_info_str+debug_str_i),c1);
                        strcpy(*(debug_info_str+debug_str_i+1),c2);
                    #elif _WIN32
                        sprintf_s(c1,"collision: %s",(debug_collision ? "true" : "false"));
                        sprintf_2(c2,"normal x:%.1lf y:%.1lf",debug_normal.x,debug_normal.y);

                        strcpy_s(*(debug_info_str+debug_str_i),64,c1);
                        strcpy_s(*(debug_info_str+debug_str_i+1),64,c2);
                    #endif
                    debug_str_i+=2;
                }
                if(debug_frame_info)//Информация о кадре
                {
                    char c1[64];
                    #ifdef __linux__
                        sprintf(c1,"frame time: %.1lf",debug_frame);

                        strcpy(*(debug_info_str+debug_str_i),c1);
                    #elif _WIN32
                        sprintf_s(c1,"frame time: %.1lf",debug_frame);

                        strcpy_s(*(debug_info_str+debug_str_i),64,c1);
                    #endif
                    debug_str_i+=1;
                }
                *(debug_info_str+debug_str_i) = nullptr;

                char** loop = debug_info_str;
                while(*loop != nullptr)
                {
                    drawText(renderer,debug_font,*loop,0,debug_info_y,debug_font_size);
                    debug_info_y+=debug_font_size;
                    loop++;
                }
            }
        }

        SDL_RenderPresent(renderer);

        //Окончание кадра
        long long int end = SDL_GetPerformanceCounter();
        double elapsedTime = (end-start)/(float)SDL_GetPerformanceFrequency()*1000.0;
        debug_frame = elapsedTime;
        if(elapsedTime < 20.0)
            SDL_Delay((int)(20.0-elapsedTime));
    }
    SDL_DestroyWindow(window);
    TTF_CloseFont(debug_font);
    TTF_Quit();
	SDL_Quit();
	return 0;
}
