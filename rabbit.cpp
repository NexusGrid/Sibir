#include "animal.h"


rabbit::rabbit() {};

rabbit::rabbit(unsigned int nX, unsigned int nY) : animal(nX, nY) {}

rabbit::~rabbit(){}


void rabbit::move(std::vector<class rabbit>& vRabbit, std::vector<class wolf>& vWolf, std::vector<class sheWolf>& vSheWolf,map& m)
{
    int block = 0;
    int r = std::rand() % 9;
    if(r != 1){
    bool pozition[8];
    unsigned int nX, nY;
    checkBlock(vRabbit, vWolf, vSheWolf, pozition, m);
    searchEmptyCell(nX, nY, pozition);
    for(int i = 0; i < 8; i++)
    {
        if(pozition[i] == false){ block++;}
    }
    if(block == 8)
    {
        return;
    }
    else
    {
    setX(nX);
    setY(nY);
    }

    }
    else { return; }
}
void rabbit::reproduce(std::vector<class rabbit>& vRabbit, std::vector<class wolf>& vWolf, std::vector<class sheWolf>& vSheWolf,map& m)
{
    int block = 0;
    unsigned int nX, nY;
    bool pozition[8];
    checkBlock(vRabbit, vWolf, vSheWolf, pozition, m);
    searchEmptyCell(nX, nY, pozition);
    for(int i = 0; i < 8; i++)
    {
        if(pozition[i] == false){ block++;}
    }
    if(block == 8)
    {
        return;
    }
    else
    {
    rabbit rab(nX, nY);
    m.screen[nX][nY] = 'R';
    vRabbit.push_back(rab);
    rab.~rabbit();
    }
}
