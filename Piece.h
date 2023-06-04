#include<iostream>
#include<conio.h>
using namespace std;
#pragma once
#include "Position.h"
#include "Board.h"

class Piece
{
public:
    int m_Color();
    int m_number;               //()
    Position m_Position;
    Board* m_b;
    virtual bool IsKilled() = 0;        //false
    virtual bool IsHome() = 0;          //false
    virtual bool HasCompleted() = 0;   //false
    virtual bool IsHome() = 0;          //false
    virtual bool IsSafe() = 0;          //false

public:
    Piece(int c, Position p, Board* b) : m_number(c), m_Position(p), m_b(b) {}
    void Draw();
    void Move(Position end);
    bool IsKillHappen(Position end);
    bool IsLegal(Position EP);
    void SetPieceStatus();

};