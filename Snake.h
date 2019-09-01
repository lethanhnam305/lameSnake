#pragma once
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "console.h"
#include<conio.h>
using namespace std;

enum Status {
	UP, DOWN, LEFT, RIGHT, STOP,
};

struct Coordinate
{
	int x, y;
};

class Snake
{
private:
	int length;
	Status Status;
	static Snake* m_Instance;
	~Snake();
	Snake();
	Coordinate * head;
public:
	int getX();
	int getY();
	int getLength();
	void snakeGrowth();
	static Snake* createSnake();
	void move();
	void print();
	bool touchWall();
	bool biteItself();
};