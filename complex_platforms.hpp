#pragma once
#ifdef __linux__
    #include <SDL2/SDL.h>
#elif _WIN32
    #include <SDL.h>
#endif
#include "platformFactory.hpp"
#include "player.hpp"

/**
\defgroup ComplexPlatforms
@{
\brief Декоратор для платформ

Дополнительные функции для использования со списками платформ
*/

///Отрисовать все платформы на экране платформы относительно игрока
/**
\param renderer Рендерер
\param platforms Список платформ
\param player Игрок
\param platformTexture Текстура платформы
*/
void drawPlatforms(SDL_Renderer*& renderer, PlatformFactory& platforms, Player& player, SDL_Texture* platformTexture);

///Передвинуть все платформы на 1 кадр
/**
\param platforms Список платформ
*/
void stepPlatforms(PlatformFactory& platforms);

///@}
