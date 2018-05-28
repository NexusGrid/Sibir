#include "animal.h"
#include <vector>
#include <cstdlib>
#include "Simulation.h"
#include<conio.h>

using namespace std;
void start()
{

    map Map;
    Map.initMap();



    vector<class rabbit> vRabbit;
    vector<class wolf> vWolf;
    vector<class sheWolf> vSheWolf;

    for (int i = 0; i < 4; i++)
    {
        int xR = rand() % Map.getLength();
        int yR = rand() % Map.getHeight();

        rabbit startRabbit(xR, yR);
        vRabbit.push_back(startRabbit);
        startRabbit.~rabbit();
        rabbitCounter++;
        Map.screen[vRabbit[i].getY()][vRabbit[i].getX()] = 'R';
    }
    for (int i = 0; i < 2; i++)
    {
        int xW = rand() % Map.getLength();
        int yW = rand() % Map.getHeight();

        wolf startWolf(xW, yW);
        vWolf.push_back(startWolf);
        startWolf.~wolf();
        wolfCounter++;
        Map.screen[vWolf[i].getY()][vWolf[i].getX()] = 'W';
    }
    for (int i = 0; i < 2; i++)
    {
        int xSW = rand() % Map.getLength();
        int ySW = rand() % Map.getHeight();

        sheWolf startSheWolf(xSW, ySW);
        vSheWolf.push_back(startSheWolf);
        startSheWolf.~sheWolf();
        wolfCounter++;
        Map.screen[vSheWolf[i].getY()][vSheWolf[i].getX()] = 'S';

    }
    for(int iter = 0; iter < 100; iter++)
    {
        for (unsigned int i = 0; i < vRabbit.size(); i++)
        {
            int r = rand() % 10;
            if (r == 0 || r == 1)
            {
                vRabbit[i].reproduce(vRabbit,vWolf,vSheWolf,Map);
                rabbitCounter++;
            }
            else
            {
                Map.screen[vRabbit[i].getY()][vRabbit[i].getX()] = ' ';
                vRabbit[i].move(vRabbit, vWolf, vSheWolf, Map);
                Map.screen[vRabbit[i].getY()][vRabbit[i].getX()] = 'R';
            }
        }

        for (unsigned int i = 0; i < vSheWolf.size(); i++)
        {
            if (vSheWolf[i].getHunger() > 0)
            {

                bool checkFeed = false;

                vSheWolf[i].hunt(vRabbit, checkFeed);

                if(checkFeed == true)
                {
                    Map.screen[vSheWolf[i].getY()][vSheWolf[i].getX()] = 'S';
                }

                if (checkFeed == false)
                { 
                    Map.screen[vSheWolf[i].getY()][vSheWolf[i].getX()] = ' ';
                    vSheWolf[i].move(vRabbit, vWolf, vSheWolf, Map);
                    Map.screen[vSheWolf[i].getY()][vSheWolf[i].getX()] = 'S';
                }

                vSheWolf[i].setHunger(vSheWolf[i].getHunger() - 10);
            }
            else
            {
                int sheWolfDieX = vSheWolf[i].getX();
                int sheWolfDieY = vSheWolf[i].getY();
                 vSheWolf.erase(vSheWolf.begin() + i);
                 Map.screen[sheWolfDieY][sheWolfDieX] = ' ';
            }
        }

        for (unsigned int i = 0; i < vWolf.size(); i++)
        {
            if (vWolf[i].getHunger() > 0)
            {

                bool checkFeed = false;
                bool checkReproduce = false;

                vWolf[i].hunt(vRabbit, checkFeed);

                if(checkFeed == true)
                {
                    Map.screen[vWolf[i].getY()][vWolf[i].getX()] = 'W';
                }

                if (checkFeed == false)
                {
                    vWolf[i].reproduce(vRabbit, vWolf, vSheWolf, Map, checkReproduce);
                    if (checkReproduce == true)
                    {
                        Map.screen[vWolf[i].getY()][vWolf[i].getX()] = 'W';
                    }
                    if (checkReproduce == false)
                    {
                        Map.screen[vWolf[i].getY()][vWolf[i].getX()] = ' ';
                        vWolf[i].move(vRabbit, vWolf, vSheWolf, Map); 
                        Map.screen[vWolf[i].getY()][vWolf[i].getX()] = 'W';
                    }
                }
                vWolf[i].setHunger(vWolf[i].getHunger() - 10);
            }
            else
            {
                int WolfDieX = vWolf[i].getX();
                int WolfDieY = vWolf[i].getY();
                 vWolf.erase(vWolf.begin() + i);
                 Map.screen[WolfDieY][WolfDieX] = ' ';
            }
        }

        Map.printMap();

        _getch();
        system("cls");

    }

}
