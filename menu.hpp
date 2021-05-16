#pragma once
#include "rect.hpp"

struct Buttons
{
    Rect* buttons;
    int amount;
    int selected;
};

//Конструктор
void initButtons(Buttons* buttons);

//Загрузить кнопки из файла
void loadButtons(const char* name, Buttons* buttons);

//Выбор кнопки с проверкой границ
void cleanSelect(Buttons* buttons);

//Передвижение по кнопкам с проверкой границ
void up(Buttons* buttons);
void down(Buttons* buttons);
