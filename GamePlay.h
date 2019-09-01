#pragma once
#include "Snake.h"
#include "Food.h"
#include "Map.h"

class GamePlay
{
private:
	Food * m_Food;
	Snake * m_Snake;
	Map * m_Map;
public:
	GamePlay();
	void run();
	void foodEaten();// con ran an do an
	bool gameOver();//con ran cham tuong
};