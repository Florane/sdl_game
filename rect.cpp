#include <iostream>
#include "rect.hpp"

//математика для коллизий
double _abs(double a)
{
    if(a < 0)
        return -a;
    return a;
}

double min(double a, double b)
{
    if(a < b)
        return a;
    return b;
}

double max(double a, double b)
{
    if(a > b)
        return a;
    return b;
}

void swap(double* a, double* b)
{
    double c = *a;
    *a = *b;
    *b = c;
}

//замена операторов у векторов
Vector* addVectors(const Vector* v1, const Vector* v2)
{
    static Vector v;
    v.x = v1->x + v2->x;
    v.y = v1->y + v2->y;
    return &v;
}

Vector* subVectors(const Vector* v1, const Vector* v2)
{
    static Vector v;
    v.x = v1->x - v2->x;
    v.y = v1->y - v2->y;
    return &v;
}

Vector* multVectors(const Vector* v1, const Vector* v2)
{
    static Vector v;
    v.x = v1->x * v2->x;
    v.y = v1->y * v2->y;
    return &v;
}

Vector* addVectorNumber(const Vector* v1, const double* v2)
{
    static Vector v;
    v.x = v1->x + *v2;
    v.y = v1->y + *v2;
    return &v;
}

Vector* subVectorNumber(const Vector* v1, const double* v2)
{
    static Vector v;
    v.x = v1->x - *v2;
    v.y = v1->y - *v2;
    return &v;
}

Vector* multVectorNumber(const Vector* v1, const double* v2)
{
    static Vector v;
    v.x = v1->x * (*v2);
    v.y = v1->y * (*v2);
    return &v;
}

bool collidePointRect(const Vector* point, const Rect* rect)
{
    return (point->x > rect->pos.x &&
            point->x < rect->pos.x+rect->size.x &&
            point->y > rect->pos.y &&
            point->y < rect->pos.y+rect->size.y);
}

bool collideRectRect(const Rect* r1, const Rect* r2)
{
    return (r1->pos.x < r2->pos.x+r2->size.x &&
            r1->pos.x+r1->size.x > r2->pos.x &&
            r1->pos.y < r2->pos.y+r2->size.y &&
            r1->pos.y+r1->size.y > r2->pos.y);
}

bool collideRayRect(const Vector* origin, const Vector* direction, const Rect* target, Vector* contact, Vector* normal, double* nearTime)
{
    *contact = {0,0};
    *normal = {0,0};

    Vector invert = {1.0/direction->x,1.0/direction->y};
    Vector near = *multVectors(subVectors(&target->pos,origin),&invert);
    Vector far = *multVectors(subVectors(addVectors(&target->pos,&target->size),origin),&invert);
    //std::cout << near.x << " " << near.y << " " << far.x << " " << far.y << std::endl;

    if(far.x != far.x || far.y != far.y || near.x != near.x || near.y != near.y) return false;
    if(near.x > far.x) swap(&near.x,&far.x);
    if(near.y > far.y) swap(&near.y,&far.y);

    if(near.x > far.y || near.y > far.x) return false;

    *nearTime = max(near.x,near.y);
    double farTime = min(far.x,far.y);

    if(farTime < 0) return false;

    *contact = *addVectors(multVectorNumber(direction,nearTime),origin);
    if(near.x > near.y)
        if(invert.x < 0)
            *normal = {1,0};
        else
            *normal = {-1,0};
    else if(near.x < near.y)
        if(invert.y < 0)
            *normal = {0,1};
        else
            *normal = {0,-1};

    return true;
}
