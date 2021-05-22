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
    time = 0.0;
    bool ret = false;
    if(collideObjects(object1,object2,contact,normal,time))
    {
        Vector buffer = {_abs(object1.movement.x)*(1-time),_abs(object1.movement.y)*(1-time)};
        object1.movement = addVectors(object1.movement,multVectors(normal,buffer));
        ret = true;
    }
    object1.movement = addVectors(object1.movement,object2.movement);
    return ret;
}

void initObjectStack(ObjectStack& objectStack, int size)
{
    objectStack.objects = (Object*)calloc(size,sizeof(Object));
    objectStack.size = size;
    objectStack.iter = 0;
    objectStack.distances = (Dist*)calloc(size,sizeof(Dist));
}

double getDistance(Object& parent, Object& object)
{
    Vector pos1 = {parent.position.pos.x+(parent.position.size.x/2),parent.position.pos.y+(parent.position.size.y/2)};
    Vector contact,q; double w;
    collideObjects(parent,object,contact,q,w);
    return ((pos1.x-contact.x)*(pos1.x-contact.x))+((pos1.y-contact.y)*(pos1.y-contact.y));
}

void setObject(Object& parent, ObjectStack& objectStack, Object& object)
{
    objectStack.objects[objectStack.iter] = object;
    Dist dist = {getDistance(parent,object),objectStack.iter};
    objectStack.distances[objectStack.iter] = dist;

    objectStack.iter++;
    if(objectStack.iter == objectStack.size)
    {
        objectStack.size++;
        objectStack.objects = (Object*)realloc(objectStack.objects,sizeof(Object)*objectStack.size);
        objectStack.distances = (Dist*)realloc(objectStack.distances,sizeof(Dist)*objectStack.size);
        initObject(objectStack.objects[objectStack.iter]);
    }
}

int comp(const Dist* a, const Dist* b)
{
    return (int)(a->distance-b->distance);
}

void sortObjectStack(ObjectStack& objectStack)
{
    qsort(objectStack.distances,objectStack.iter,sizeof(Dist),(int(*) (const void *, const void *)) comp);
}

int resolveObjectStack(Object& parent, ObjectStack& objectStack)
{
    int bitData = 0;
    for(int i = 0;i < objectStack.iter;i++)
    {
        int buffer = 0;
        int j = objectStack.distances[i].position;
        Vector contact, normal; double time = 0.0;
        if(resolveObjects(parent,objectStack.objects[j],contact,normal,time))
            buffer += 1;
        if(normal.y == -1 && buffer != 0)
            buffer += 2;
        if(buffer > bitData)
            bitData = buffer;
    }
    return bitData;
}
