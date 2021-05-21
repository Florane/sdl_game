#pragma once
#ifdef __linux__
    #include <SDL2/SDL.h>
#elif _WIN32
    #include <SDL.h>
#endif
#include "tilemap.hpp"
#include "player.hpp"

/**
\defgroup ComplexTilemap
@{
\brief Декоратор для тайловой карты

Дополнительные функции для использования с тайловыми картами
*/

///Отрисовать карту на экран
/**
\param renderer Рендерер
\param tilemap Тайловая карта
\param player Игрок
\param tilemapTextures Список текстур в соответствии с ID блоков
*/
void drawTilemap(SDL_Renderer*& renderer, Tilemap& tilemap, Player& player, SDL_Texture** tilemapTextures);

///@}
