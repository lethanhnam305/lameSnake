#pragma once
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Snake.h"
using namespace std;

class Food
{
private:
	Food();
	Coordinate Coordinate;
	static Food * m_Instance;
public:
	int getX();
	int getY();
	static Food* createFood();
	void print();
	void resetPos();//Tao moi thuc an
};