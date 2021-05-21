#pragma once
#include "rect.hpp"

/**
\defgroup Platform_idiot
@{
\brief Платформа

Внутриигровая платформа и её основные функции
*/

///Платформа
/**
\param position Позиция и раазмер платформы
\param movement Границы разрешенного движения для платформы
\param speed Скорость платформы
\param mainDiagonal Техническое. Проверять ли выход за границы movement
*/
struct Platform
{
    Rect position;
    Rect movement;
    Vector speed;
    bool checkBoundary;
};

///Инициализация и установка платформы
/**
\param platform Платформа
\param position Позиция и раазмер платформы
\param movement Границы разрешенного движения для платформы
\param speed Скорость платформы
\param mainDiagonal По какой диагонали movement движется платформа. 1 - главная, -1 - дополнительная
*/
void initPlatform(Platform& platform, Rect position, Rect movement, double speed, char mainDiagonal);

///Передвинуть платформу на 1 кадр
/**
\param platform Платформа
*/
void stepPlatform(Platform& platform);

///@}
