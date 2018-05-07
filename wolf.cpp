#include "animal.h"

wolf::wolf() { hunger = 100; }
wolf::wolf(unsigned int nX, unsigned int nY){ setX(nX), setY(nY), hunger = 100; }
wolf::~wolf() {}

void wolf::reproduce(std::vector<class rabbit>& vRabbit, std::vector<class wolf>& vWolf, std::vector<class sheWolf>& vSheWolf,map& m, bool& check)
{
    unsigned int nX = getX();
    unsigned int nY = getY();
    int sheX = -1;
    int sheY = -1;
    unsigned int sWNum;


    for (unsigned int i = 0; i < vSheWolf.size(); i++)
    {
        unsigned int xSw = vSheWolf[i].getX();
        unsigned int ySw = vSheWolf[i].getY();

        if (((nX - 1) == xSw) && ((nX + 1) == ySw))
        {
            sheX = nX - 1;
            sheY = nY + 1;
            sWNum = i;
        }
        if ((nX == xSw) && ((nY + 1) == ySw))
        {
            sheX = nX;
            sheY = nY + 1;
            sWNum = i;
        }
        if (((nX + 1) == xSw) && ((nY + 1) == ySw))
        {
            sheX = nX + 1;
            sheY = nY + 1;
            sWNum = i;
        }
        if (((nX + 1) == xSw) && (nY == ySw))
        {
            sheX = nX + 1;
            sheY = nY;
            sWNum = i;
        }
        if (((nX + 1) == xSw) && ((nY - 1) == ySw))
        {
            sheX = nX + 1;
            sheY = nY - 1;
            sWNum = i;
        }
        if ((nX == xSw) && ((nY - 1) == ySw))
        {
            sheX = nX;
            sheY = nY - 1;
            sWNum = i;
        }
        if (((nX - 1) == xSw) && ((nX - 1) == ySw))
        {
            sheX = nX - 1;
            sheY = nY - 1;
            sWNum = i;
        }
        if (((nX - 1) == xSw) && (nY == ySw))
        {
            sheX = nX - 1;
            sheY = nY;
            sWNum = i;
        }
    }

    for(unsigned int i = 0; i < vWolf.size(); i++ )
    {
        int checkX = vWolf[i].getX();
        int checkY = vWolf[i].getY();
        if(sheX == checkX && sheY == checkY){return;}
    }

    if (sheX != -1 && sheY != -1)
    {
        int block = 0;
        setX(sheX);
        setY(sheY);
        bool pozition[8];
        unsigned int newX, newY;
        checkBlock(vRabbit, vWolf, vSheWolf, pozition, m);
        searchEmptyCell(newX, newY, pozition);
        int r = std::rand() % 2;
        for(int i = 0; i < 8; i++)
        {
            if(pozition[i] == false){ block++;}
        }
        if(block == 8){std::cout << "Wolf cant born" << std::endl; return;}
        else{

        if (r == 0)
        {
            wolf newWolf(newX, newY);
            vWolf.push_back(newWolf);
            newWolf.~wolf();
            check = true;
            std::cout << "Wolf was born on: X:" << newX <<"; Y:" << newY <<std::endl;
        }
        if (r == 1)
        {
            sheWolf newSheWolf(newX, newY);
            vSheWolf.push_back(newSheWolf);
            newSheWolf.~sheWolf();
            check = true;
             std::cout << "SheWolf was born on: X:" << newX <<"; Y:" << newY <<std::endl;
        }
        }

    }
    else{return;}
}
