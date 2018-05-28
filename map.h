#ifndef MAP_H
#define MAP_H


class map
{
private:
    int mapLength;
    int mapHeight;

public:
    char screen[20][20];
    void setLength(int x);
    void setHeight(int x);
    int getLength();
    int getHeight();
    void initMap();
    void printMap();


    map();
    ~map();
};

#endif
