#include "animal.h"

sheWolf::sheWolf(): hunger(100){}
sheWolf::sheWolf(unsigned int nX, unsigned int nY) : animal(nX, nY) { hunger = 100; }
sheWolf::~sheWolf(){}

void sheWolf::setHunger(int h) { hunger = h; }
int sheWolf::getHunger() { return hunger; }

void sheWolf::hunt(std::vector<class rabbit>& vRabbit, bool& check)
{
    unsigned int nX = getX();
    unsigned int nY = getY();
    int rabX = -1;
    int rabY = -1;
    unsigned int rNum;


    for (int i = 0; i < vRabbit.size(); i++)
    {
        unsigned int xR = vRabbit[i].getX();
        unsigned int yR = vRabbit[i].getY();

        if (((nX - 1) == xR) && ((nX + 1) == yR))
        {
            rabX = nX - 1;
            rabY = nY + 1;
            rNum = i;
        }
        if ((nX == xR) && ((nY + 1) == yR))
        {
            rabX = nX;
            rabY = nY + 1;
            rNum = i;
        }
        if (((nX + 1) == xR) && ((nY + 1) == yR))
        {
            rabX = nX + 1;
            rabY = nY + 1;
            rNum = i;
        }
        if (((nX + 1) == xR) && (nY == yR))
        {
            rabX = nX + 1;
            rabY = nY;
            rNum = i;
        }
        if (((nX + 1) == xR) && ((nY - 1) == yR))
        {
            rabX = nX + 1;
            rabY = nY - 1;
            rNum = i;
        }
        if ((nX == xR) && ((nY - 1) == yR))
        {
            rabX = nX;
            rabY = nY - 1;
            rNum = i;
        }
        if (((nX - 1) == xR) && ((nX - 1) == yR))
        {
            rabX = nX - 1;
            rabY = nY - 1;
            rNum = i;
        }
        if (((nX - 1) == xR) && (nY == yR))
        {
            rabX = nX - 1;
            rabY = nY;
            rNum = i;
        }
    }
    if (rabX != -1 && rabY != -1)
    {
        setX(rabX);
        setY(rabY);
        vRabbit.erase(vRabbit.begin() + rNum);
        setHunger(getHunger() + 100);
        check = true;
    }
}
