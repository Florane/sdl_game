#pragma once
#pragma GCC diagnostic ignored "-Wnarrowing"

/**
\defgroup Rect_idiot
@{
\brief Простые прямоугольники

Описание всех основных вычислений и понятий для параллельных осям прямоугольников
*/

///Вектор
/**
Вектор с началом в точке 0,0
\param x,y Направление
*/
struct Vector
{
    double x,y;
};

///Прямоугольник
/**
\param pos Позиция
\param size Размер
*/
struct Rect
{
    Vector pos, size;
};

///Модуль числа
/**
\param a Число
\return double Модуль
*/
double _abs(const double& a);

///Сложить 2 вектора
/**
\param v1 Вектор
\param v2 Вектор
\return Vector Вектор - сумма
*/
Vector addVectors(const Vector& v1, const Vector& v2);

///Вычесть 2 вектора
/**
\param v1 Вектор
\param v2 Вектор
\return Vector Вектор - сумма
*/
Vector subVectors(const Vector& v1, const Vector& v2);

///Перемножить координаты 2 векторов
/**
\param v1 Вектор
\param v2 Вектор
\return Vector Вектор с произведениями
*/
Vector multVectors(const Vector& v1, const Vector& v2);

/// Добавляет число к координатам вектора
/**
\param v1 Вектор
\param v2 Число
\return Vector Вектор - результат
*/
Vector addVectorNumber(const Vector& v1, const double& v2);

/// Вычитает число из координат вектора
/**
\param v1 Вектор
\param v2 Число
\return Vector Вектор - результат
*/
Vector subVectorNumber(const Vector& v1, const double& v2);

/// Умножает координаты вектора на число
/**
\param v1 Вектор
\param v2 Число
\return Vector Вектор - результат
*/
Vector multVectorNumber(const Vector& v1, const double& v2);

///Проверить пересечение двух прямоугольников
/**
\param r1 указатель на прямоугольник
\param r2 указатель на прямоугольник
\return bool Пересекаются-ли прямоугольники
*/
bool collideRectRect(const Rect* r1, const Rect* r2);

///Проверить пересечение отрезка и прямоугольника
/**
\param origin Начало отрезка
\param direction Направление отрезка
\param target Объект пересечения
\param contact Точка пересечения
\param normal Перпендикуляр к плоскости пересечения
\param nearTime Позиция точки пересечения на отрезке от 0.0 до 1.0
\return bool Пересекаются-ли отрезок и прямоугольник
*/
bool collideRayRect(const Vector& origin, const Vector& direction, const Rect& target, Vector& contact, Vector& normal, double& nearTime);

///@}
