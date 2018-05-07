#ifndef ANIMAL_H
#define ANIMAL_H

#include<iostream>
#include "map.h"
#include <vector>

class animal
{
protected:
    int xCoord;
    int yCoord;
public:
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();

    void checkBlock(std::vector<class rabbit>& vRabbit,std::vector<class wolf>& vWolf,std::vector<class sheWolf>& vSheWolf, bool *poz,map& m);
    void searchEmptyCell(unsigned int& nX, unsigned int& nY, bool *poz);
    void move(std::vector<class rabbit>& vRabbit,std::vector<class wolf>& vWolf,std::vector<class sheWolf>& vSheWolf,map& m);



    animal();
    animal(unsigned int nX, unsigned int nY);
     ~animal();
};

class rabbit : public animal
{
public:

    void move(std::vector<class rabbit>& vRabbit, std::vector<class wolf>& vWolf, std::vector<class sheWolf>& vSheWolf, map& m);
    void reproduce(std::vector<class rabbit>& vRabbit, std::vector<class wolf>& vWolf, std::vector<class sheWolf>& vSheWolf, map& m);

    rabbit();
    rabbit(unsigned int nX, unsigned int nY);
    ~rabbit();
};

class sheWolf : public animal
{
protected:
    int hunger;
public:
    void setHunger(int h);
    int getHunger();
    void hunt(std::vector<class rabbit>& vRabbit, bool& check);

    sheWolf();
    sheWolf(unsigned int nX, unsigned int nY);
    ~sheWolf();
};

class wolf : public sheWolf
{
public:
    wolf();
    wolf(unsigned int nX, unsigned int nY);
    ~wolf();

    void reproduce(std::vector<class rabbit>& vRabbit, std::vector<class wolf>& vWolf, std::vector<class sheWolf>& vSheWolf, map& m, bool& check);
};


#endif
