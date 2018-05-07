#include "animal.h"
#include <vector>
#include <cstdlib>
#include "Simulation.h"
#include<conio.h>

using namespace std;
void start()
{
    //int turn;
    map Map;
    int wolfCounter = 0;
    //int sheWolfCounter = 0;
    int rabbitCounter = 0;
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
        cout << "First Rabbit was born on: X: " << xR << "; Y: " << yR << endl;
        rabbitCounter++;
    }
    for (int i = 0; i < 2; i++)
    {
        int xW = rand() % Map.getLength();
        int yW = rand() % Map.getHeight();

        wolf startWolf(xW, yW);
        vWolf.push_back(startWolf);
        startWolf.~wolf();
        cout << "First Wolf was born on: X: " << xW << "; Y: " << yW << endl;
        wolfCounter++;
    }
    for (int i = 0; i < 2; i++)
    {
        int xSW = rand() % Map.getLength();
        int ySW = rand() % Map.getHeight();

        sheWolf startSheWolf(xSW, ySW);
        vSheWolf.push_back(startSheWolf);
        startSheWolf.~sheWolf();
        cout << "First SheWolf was born on: X: " << xSW << "; Y: " << ySW << endl;
        wolfCounter++;
    }
    for(int iter = 0; iter < 100; iter++)
    {
        for (unsigned int i = 0; i < vRabbit.size(); i++)
        {
            //int xR = vRabbit[i].getX();
           // int yR = vRabbit[i].getY();
            int r = rand() % 10;
            if (r == 0 || r == 1)
            {
                vRabbit[i].reproduce(vRabbit,vWolf,vSheWolf,Map);
                rabbitCounter++;
            }else{vRabbit[i].move(vRabbit, vWolf, vSheWolf, Map);}
        }

        for (unsigned int i = 0; i < vSheWolf.size(); i++)
        {
            if (vSheWolf[i].getHunger() > 0)
            {

                bool checkFeed = false;

                vSheWolf[i].hunt(vRabbit, checkFeed);
                if (checkFeed == true)
                {
                    int xSW = vSheWolf[i].getX();
                    int ySW = vSheWolf[i].getY();
                    cout << "SheWolf was eated Rabbit on X: " << xSW << "; Y: " << ySW << endl;
                    rabbitCounter--;
                }
                if (checkFeed == false)
                {
                    int xSW1 = vSheWolf[i].getX();
                    int ySW1 = vSheWolf[i].getY();
                    vSheWolf[i].move(vRabbit, vWolf, vSheWolf, Map);
                    int xSW2 = vSheWolf[i].getX();
                    int ySW2 = vSheWolf[i].getY();
                    if(xSW1 == xSW2 && ySW1 == ySW2)
                    {
                     cout << "SheWolf was staying" << endl;
                    }
                    else
                    {
                      cout << "SheWolf was moved on: X: " << xSW2 << "; Y: " << ySW2 << endl;
                    }
                }
                vSheWolf[i].setHunger(vSheWolf[i].getHunger() - 10);
            }
            else { vSheWolf.erase(vSheWolf.begin() + i); cout << "SheWolf die" << endl; wolfCounter--; }
        }

        for (unsigned int i = 0; i < vWolf.size(); i++)
        {
            if (vWolf[i].getHunger() > 0)
            {

                bool checkFeed = false;
                bool checkReproduce = false;

                vWolf[i].hunt(vRabbit, checkFeed);
                if (checkFeed == true)
                {
                    int xW = vWolf[i].getX();
                    int yW = vWolf[i].getY();
                    cout << "Wolf was eated Rabbit on: X: " << xW << "; Y: " << yW << endl; rabbitCounter--;
                }
                if (checkFeed == false)
                {
                    vWolf[i].reproduce(vRabbit, vWolf, vSheWolf, Map, checkReproduce);
                    if (checkReproduce == true) {wolfCounter++; }
                    if (checkReproduce == false)
                    {
                        int xW1 = vWolf[i].getX();
                        int yW1 = vWolf[i].getY();
                        vWolf[i].move(vRabbit, vWolf, vSheWolf, Map);
                        int xW2 = vWolf[i].getX();
                        int yW2 = vWolf[i].getY();
                        if(xW1 == xW2 && yW1 == yW2)
                        {
                        cout << "Wolf was staying" << endl;
                        }
                        else
                        {
                           cout << "Wolf was moved on: X: " << xW2 << "; Y: " << yW2 << endl;
                        }
                    }
                }
                vWolf[i].setHunger(vWolf[i].getHunger() - 10);
            }
            else { vWolf.erase(vWolf.begin() + i); cout << "Wolf die" << endl; wolfCounter--; }
        }
        cout << "Wolves: " << wolfCounter << endl << "Rabbits: " << rabbitCounter << endl << endl;
        cout << "------------------------------------------------------------------------" << endl;
        _getch();

    }

}
