#include<iostream>
#include<conio.h>
using namespace std;
#pragma once
#include "Piece.h"

class Player
{
public:
	int Color;
	Piece* P;
	bool Iswin;			//(false)

public:
	Player(int c, Piece* p) : Color(c), P(p) {}

	bool IsWin();

};