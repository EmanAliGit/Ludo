#include<iostream>
#include<conio.h>
using namespace std;
#pragma once
#include "Board.h"

class Game
{
public:
    Board B;
    int NOP;
public:
    Game();
    Game(int np)
        :NOP(np)
    {

    }
    void StartGame();
    void SaveGame();

};