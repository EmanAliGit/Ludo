#pragma once
#include "Position.h"

class Cells
{
public:
	Position m_Pos;
	int m_Color;
	bool IsStop();
	bool IsHome();
public:
	Cells(Position Pos, int c) : m_Pos(Pos), m_Color(c) {}
	void Draw();

};
