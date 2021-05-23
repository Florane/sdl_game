#pragma once
#include "collision.hpp"
#include "tilemap.hpp"
#include "player.hpp"
#include "platformFactory.hpp"

/**
\defgroup ComplexCollision
@{
\brief Дополнительные функции для выисления столкновений

Функции для оптимизации и проверки столкновений между множеством объектов
*/

///Добавить все тайлы, с которыми возможно столкновение, в список объектов
/**
*/
void tilemapToStack(Object& parent, Tilemap& tilemap, ObjectStack& stack);

///Добавить все платформы, с которыми возможно столкновение, в список объектов
/**
*/
void platformsToStack(Object& parent, PlatformFactory& platforms, ObjectStack& stack);

///@}
