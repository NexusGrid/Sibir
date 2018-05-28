#include "map.h"
#include <iostream>

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

void map::initMap()
{
    for(int i = 0; i < map::getHeight(); i++)
    {
        for(int j = 0 ; j < map::getLength(); j++)
        {
            screen[i][j] = ' ';
        }
    }
}

void map::printMap()
{
    for(int i = 0; i < map::getHeight(); i++)
    {
        for(int j = 0 ; j < map::getLength(); j++)
        {
            std::cout << screen[i][j];
        }
        std::cout << std::endl;
    }

}

