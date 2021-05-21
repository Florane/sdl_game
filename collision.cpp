#include "collision.hpp"
#include <cstdio>
#include "stdlib.h"

void initObject(Object& object, Rect position, Vector movement)
{
    object.position = position;
    object.movement = movement;
}

void initObject(Object& object, Rect position)
{
    object.position = position;
    object.movement = {0,0};
}

void initObject(Object& object)
{
    object.position = {0,0,1,1};
    object.movement = {0,0};
}

bool collideObjects(Object& object1, Object& object2, Vector& contact, Vector& normal, double& time)
{
    object1.movement = subVectors(object1.movement,object2.movement);
    if(object1.movement.x == 0 && object1.movement.y == 0)
        return false;

    Rect expandedTarget;
    Vector buffer = {object1.position.size.x/2.0,object1.position.size.y/2.0};
    expandedTarget.pos = subVectors(object2.position.pos,buffer);
    expandedTarget.size = addVectors(object2.position.size,object1.position.size);

    if(collideRayRect(addVectors(object1.position.pos,buffer),object1.movement,expandedTarget, contact, normal, time))
    {
        return (time >= 0.0 && time < 1.0);
    }
    return false;
}

bool resolveObjects(Object& object1, Object& object2, Vector& contact, Vector& normal, double& time)
{
    object1 = object1;
    time = 0.0;
    if(collideObjects(object1,object2,contact,normal,time))
    {
        Vector buffer = {_abs(object1.movement.x)*(1-time),_abs(object1.movement.y)*(1-time)};
        object1.movement = addVectors(object1.movement,multVectors(normal,buffer));
        return true;
    }
    return false;
}

void initObjectStack(ObjectStack& objectStack)
{
    objectStack.objects = (Object*)calloc(1,sizeof(Object));
    initObject(objectStack.objects[0]);
    objectStack.size = 1;
    objectStack.iter = 0;
}

void setObject(ObjectStack& objectStack, Object& object)
{
    objectStack.objects[objectStack.iter] = object;
    objectStack.iter++;
    if(objectStack.iter == objectStack.size)
    {
        objectStack.size++;
        objectStack.objects = (Object*)realloc(objectStack.objects,sizeof(Object)*objectStack.size);
        initObject(objectStack.objects[objectStack.iter]);
    }
}

void sortObjectList(ObjectStack& objectStack)
{

}
