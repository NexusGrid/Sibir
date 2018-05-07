#ifndef MAP_H
#define MAP_H


class map
{
private:
    int mapLength;
    int mapHeight;
public:
    void setLength(int x);
    void setHeight(int x);
    int getLength();
    int getHeight();

    map();
    ~map();
};

#endif
