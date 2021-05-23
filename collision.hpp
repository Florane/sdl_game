#pragma once
#include "rect.hpp"

/**
\defgroup Collision
@{
\brief Коллизия

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

///Техническое. Расстояние до объекта position
/**
\param distance Расстояние до объекта
\param position ID объекта
*/
struct Dist
{
    double distance;
    int position;
};

///Список объектов
/**
\param objects Массив объектов
\param size Максимальный размер списка
\param iter Последний доступный элемент списка
\param distances Массив расстояний до объектов
*/
struct ObjectStack
{
    Object* objects;
    int size, iter;
    Dist* distances;
};

///Инициализация списка объектов
/**
\param objectStack Список объектов
\param size Размер списка
*/
void initObjectStack(ObjectStack& objectStack, int size);

///Расстояние между двумя объектами
/**
\param parent Динамический объект
\param object Статический объект
\return double Расстояние до точки касания со статическим объектом
*/
double getDistance(Object& parent, Object& object);

///Добавить объект в конец списка
/**
\param parent Динамический объект
\param objectStack Список объектов
\param object Статический объект
*/
void setObject(Object& parent, ObjectStack& objectStack, Object& object);

///Отсортировать список
/**
\param objectStack Список объектов
*/
void sortObjectStack(ObjectStack& objectStack);

///Разрешение столкновения со всеми объектами списка
/**
\param parent Динамический объект
\param objectStack Список статических объектов
\return int Битовая маска
*/
int resolveObjectStack(Object& parent, ObjectStack& objectStack);

///@}
