#pragma once
#include "rect.hpp"

/**
\defgroup Collision
@{
\brief Декоратор для меню

Функции для оптимизации и проверки столкновений между множеством объектов
*/

///Физический объект
/**
\param position Позиция объекта
\param movement Скорость объекта
*/
struct Object
{
    Rect position;
    Vector movement;
};

///Инициализация объекта
/**
\param object Объект
\param position Позиция
\param movement Скорость
*/
void initObject(Object& object, Rect position, Vector movement);
void initObject(Object& object, Rect position);
void initObject(Object& object);

///Проверка столкновения динамического и постоянного объекта
/**
\param object1,object2 Объект
\param contact Точка столкновения
\param normal Перпендикуляр к плоскости столкновения
\param time Время столкновения от 0.0 до 1.0
*/
bool collideObjects(Object& object1, Object& object2, Vector& contact, Vector& normal, double& time);

///Разрешение столкновения
/**
\param object1 Динамический объект
\param object2 Статический объект
\param contact Точка столкновения
\param normal Перпендикуляр к плоскости столкновения
\param time Время столкновения от 0.0 до 1.0
*/
bool resolveObjects(Object& object1, Object& object2, Vector& contact, Vector& normal, double& time);

///Список объектов
/**
\param objects Массив объектов
\param size Максимальный размер списка
\param iter Последний доступный элемент списка
*/
struct ObjectStack
{
    Object* objects;
    int size, iter;
};

///Инициализация списка объектов
/**
\param objectStack Список объектов
*/
void initObjectStack(ObjectStack& objectStack);

///Добавить объект в конец списка
/**
\param objectStack Список объектов
\param object Объект
*/
void setObject(ObjectStack& objectStack, Object& object);

///Отсортировать список
/**
\param objectStack Список объектов
*/
void sortObjectList(ObjectStack& objectStack);

///@}
