#pragma once
#include "rect.hpp"

/**
\defgroup Player_idiot
@{
\brief Игрок

Хранение данных и логика для игрока
*/

///Данные игрока
/**
\param player Позиция и размеры игрока
\param movement Скорость игрока
\param isOnGround Техническое - стоит ли игрок на земле
*/
struct Player
{
    Rect player;
    Vector movement;
    bool isOnGround;
};

///Инициализация игрока
/**
\param player Игрок
*/
void initPlayer(Player& player);

///Загрузить позицию игрока из файла
/**
\param name Имя файла
\param player Игрок
*/
void loadPlayer(const char* name, Player& player);

///Сделать шаг, переместив игрока на вектор скорости
/**
\param player Указатель на игрока
*/
void stepPlayer(Player& player);

///Переместить прямоугольник для отрисовки относительно игрока
/**
\param rect Рисуемый прямоугольник
\param player Игрок
\return Rect Смещенный прямоугольник
*/
Rect shiftFromPlayer(const Rect& rect, const Player& player);

///Перемещать игрока, игнорируя физику
/**
\param player Игрок
\param keys Нажатые клавиши
*/
void movePlayer_floaty(Player& player, char* keys);

///Перемещать игрока с гравитацией
/**
\param player Игрок
\param keys Нажатые клавиши
*/
void movePlayer_actually(Player& player, char* keys);

///@}
