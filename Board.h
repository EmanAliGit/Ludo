#include<iostream>
#include<conio.h>
using namespace std;
#pragma once
#include "Piece.h"
#include "Player.h"
#include "Cells.h"
#include "Position.h"

class Board
{
public:
	int NOP, turn;
	Player* P;
	Piece* Pie;
	Cells* C;
	Position S;
	Position E;

public:
	Board();
	void InitBoard(int n);
	void PrintBoard();
	void Printpieces();
	void DispUpdateBoard();
	void Move();
	void SelectPiece();
	void CalculateDestination(int score);
	void RollDice();
	bool IsValidSelection();
	void TurnChange();
	void DispPlayerMsg();
	void DisplayUpdatedBoard();
	int DiceRoll();
};