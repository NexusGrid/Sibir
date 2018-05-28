
#include "animal.h"
#include <cstdlib>
#include <ctime>



animal::animal(){ xCoord = 0; yCoord = 0;}
animal::animal(unsigned int nX, unsigned int nY) { xCoord = nX; yCoord = nY;}
animal::~animal(){}

void animal::setX(int x) { xCoord = x; }
void animal::setY(int y) { yCoord = y; }
int animal::getX() { return xCoord; }
int animal::getY() { return yCoord; }


void animal::checkBlock(std::vector<class rabbit>& vRabbit,std::vector<class wolf>& vWolf,std::vector<class sheWolf>& vSheWolf, bool *poz,map& m)
{
     int nX = getX();
     int nY = getY();

    for (int i = 0; i < 8; i++)
    {
        poz[i] = true;
    }

    if ((nX - 1) < 0)
    {
        poz[0] = poz[7] = poz[6] = false;
    }
    if ((nY - 1) < 0)
    {
        poz[6] = poz[5] = poz[4] = false;
    }
    if ((nX + 1) > m.getLength())
    {
        poz[2] = poz[3] = poz[4] = false;
    }
    if ((nY + 1) > m.getHeight())
    {
        poz[0] = poz[1] = poz[2] = false;
    }

    for (unsigned int i = 0; i < vRabbit.size(); i++)
    {
         int xR = vRabbit[i].getX();
         int yR = vRabbit[i].getY();

        if (((nX - 1) == xR) && ((nX + 1) == yR))
        {
            poz[0] = false;
        }
        if ((nX == xR) && ((nY + 1) == yR))
        {
            poz[1] = false;
        }
        if (((nX + 1) == xR) && ((nY + 1) == yR))
        {
            poz[2] = false;
        }
        if (((nX + 1) == xR) && (nY == yR))
        {
            poz[3] = false;
        }
        if (((nX + 1) == xR) && ((nY - 1) == yR))
        {
            poz[4] = false;
        }
        if ((nX == xR) && ((nY - 1) == yR))
        {
            poz[5] = false;
        }
        if (((nX - 1) == xR) && ((nX - 1) == yR))
        {
            poz[6] = false;
        }
        if (((nX - 1) == xR) && (nY == yR))
        {
            poz[7] = false;
        }
    }

    for (unsigned int i = 0; i < vWolf.size(); i++)
    {
         int xW = vWolf[i].getX();
         int yW = vWolf[i].getY();

        if (((nX - 1) == xW) && ((nX + 1) == yW))
        {
            poz[0] = false;
        }
        if ((nX == xW) && ((nY + 1) == yW))
        {
            poz[1] = false;
        }
        if (((nX + 1) == xW) && ((nY + 1) == yW))
        {
            poz[2] = false;
        }
        if (((nX + 1) == xW) && (nY == yW))
        {
            poz[3] = false;
        }
        if (((nX + 1) == xW) && ((nY - 1) == yW))
        {
            poz[4] = false;
        }
        if ((nX == xW) && ((nY - 1) == yW))
        {
            poz[5] = false;
        }
        if (((nX - 1) == xW) && ((nX - 1) == yW))
        {
            poz[6] = false;
        }
        if (((nX - 1) == xW) && (nY == yW))
        {
            poz[7] = false;
        }
    }

    for (unsigned int i = 0; i < vSheWolf.size(); i++)
    {
        int xSW = vSheWolf[i].getX();
        int ySW = vSheWolf[i].getY();

        if (((nX - 1) == xSW) && ((nX + 1) == ySW))
        {
            poz[0] = false;
        }
        if ((nX == xSW) && ((nY + 1) == ySW))
        {
            poz[1] = false;
        }
        if (((nX + 1) == xSW) && ((nY + 1) == ySW))
        {
            poz[2] = false;
        }
        if (((nX + 1) == xSW) && (nY == ySW))
        {
            poz[3] = false;
        }
        if (((nX + 1) == xSW) && ((nY - 1) == ySW))
        {
            poz[4] = false;
        }
        if ((nX == xSW) && ((nY - 1) == ySW))
        {
            poz[5] = false;
        }
        if (((nX - 1) == xSW) && ((nX - 1) == ySW))
        {
            poz[6] = false;
        }
        if (((nX - 1) == xSW) && (nY == ySW))
        {
            poz[7] = false;
        }
    }
}

void animal::searchEmptyCell(unsigned int& nX, unsigned int& nY, bool *poz)
{
    unsigned int xF = getX();
    unsigned int yF = getY();
    nX = getX();
    nY = getY();

    int blocked = 0;
    for (int i = 0; i < 8; i++)
    {
        if (poz[i] == false)
        {
            blocked++;
        }
    }
    if (blocked == 8)
    {
        return;
    }

    bool check = true;
    while (check) {
        int rand = std::rand() % 8;

        if (poz[rand] == true)
        {
            switch (rand)
            {
            case 0:
                nX = xF - 1;
                nY = yF + 1;
                check = false;
                break;
            case 1:
                nX = xF;
                nY = yF + 1;
                check = false;
                break;
            case 2:
                nX = xF + 1;
                nY = yF + 1;
                check = false;
                break;
            case 3:
                nX = xF + 1;
                nY = yF;
                check = false;
                break;
            case 4:
                nX = xF + 1;
                nY = yF - 1;
                check = false;
                break;
            case 5:
                nX = xF;
                nY = yF - 1;
                check = false;
                break;
            case 6:
                nX = xF - 1;
                nY = yF - 1;
                check = false;
                break;
            case 7:
                nX = xF - 1;
                nY = yF;
                check = false;
                break;

            }
        }
    }

}

void animal::move(std::vector<class rabbit>& vRabbit, std::vector<class wolf>& vWolf, std::vector<class sheWolf>& vSheWolf,map& m)
{
    int block = 0;
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
