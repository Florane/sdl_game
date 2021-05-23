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
\param parent Динамический объект
\param tilemap Тайловая карта
\param stack Список объектов
*/
void tilemapToStack(Object& parent, Tilemap& tilemap, ObjectStack& stack);

///Добавить все платформы, с которыми возможно столкновение, в список объектов
/**
\param parent Динамический объект
\param platforms Список полатформ
\param stack Список объектов
*/
void platformsToStack(Object& parent, PlatformFactory& platforms, ObjectStack& stack);

///@}
