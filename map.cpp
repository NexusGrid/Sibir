#include "map.h"

void map::setLength(int x)
{
    mapLength = x;
}
void map::setHeight(int x)
{
    mapHeight = x;
}
int map::getLength()
{
    return mapLength;
}
int map::getHeight()
{
    return mapHeight;
}

map::map()
{
    mapLength = 20;
    mapHeight = 20;
}
map::~map()
{
}
