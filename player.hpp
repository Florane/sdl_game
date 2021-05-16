#pragma once
#include "rect.hpp"

struct Player
{
    Rect player;
    Vector movement;
    bool isOnGround;
};

//инициализация игрока
///player - указатель на игрока
void initPlayer(Player& player);

//сделать шаг, переместив игрока на вектор скорости
///player - указатель на игрока
void stepPlayer(Player& player);

//переместить прямоугольник для отрисовки относительно игрока
///rect - указатель на рисуемый прямоугольник
///player - указатель на игрока
///возвращает Rect - смещенный прямоугольник
Rect shiftFromPlayer(const Rect& rect, const Player& player);

//перемещать игрока, игнорируя физику
///player - указатель на игрока
///keys - нажатые клавиши
void movePlayer_floaty(Player& player, char* keys);

//перемещать игрока с гравитацией
void movePlayer_actually(Player& player, char* keys);

//проверка столкновения игрока
bool collidePlayerRect(const Player* player, const Rect* rect, Vector& contact, Vector& normal, double& time);
bool collidePlayerRect(const Player* player, const Rect* rect);

//разрешение столкновения игрока
bool resolvePlayerRect(Player* player, const Rect* rect);
bool resolvePlayerRect(Player* player, const Rect* rect, Vector& normal);
