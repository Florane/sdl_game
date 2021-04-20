#pragma once
#pragma GCC diagnostic ignored "-Wnarrowing"
///удали строчку выше - она не нужна, и скорее всего не будет работать в MVS

struct Vector
{
    double x,y;
};

struct Rect
{
    Vector pos, size;
};

double _abs(double a);

//сложить 2 вектора
///v1 - указатель на вектор
///v2 - указатель на вектор
///возвращает Vector - вектор-сумму
Vector* addVectors(const Vector* v1, const Vector* v2);

//вычесть вектор из вектора
///v1 - указатель на вектор
///v2 - указатель на вектор
///возвращает Vector - вектор-разность
Vector* subVectors(const Vector* v1, const Vector* v2);

//перемножить координаты векторов
///v1 - указатель на вектор
///v2 - указатель на вектор
///возвращает Vector - вектор, где координаты равны произведению координат аргументов
Vector* multVectors(const Vector* v1, const Vector* v2);

//проверить пересечение двух прямоугольников
///v1 - указатель на прямоугольник
///v2 - указатель на прямоугольник
///возвращает bool - пересекаются-ли прямоугольники
bool collideRectRect(const Rect* r1, const Rect* r2);

bool collideRayRect(const Vector* origin, const Vector* direction, const Rect* target, Vector* contact, Vector* normal, double* time);
