#pragma once
#include <iostream>
#include "console.h"

using namespace std;

class Map
{
private:
	static Map *m_Instance;
	Map();
	~Map();
public:
	static Map* createMap();
	void draw();
	

};
