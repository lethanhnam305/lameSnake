#include "GamePlay.h"

GamePlay::GamePlay()
{
	m_Snake = Snake::createSnake();
	m_Food = Food::createFood();
	m_Map = Map::createMap();
}

void GamePlay::run()
{
	while (1) {
		clrscr();
		m_Map->draw();
		m_Snake->print();
		m_Food->print();
		m_Snake->move();
		this->foodEaten();
		if (gameOver()) {
			cout << "Loserrrrr :v" << endl;
			break;
		}	
		Sleep(150);
	}
}

void GamePlay::foodEaten()
{
	if (m_Snake->getX() == m_Food->getX() && m_Snake->getY() == m_Food->getY())
	{
		m_Snake->snakeGrowth();
		m_Food->resetPos();
	}
}

bool GamePlay::gameOver()
{
	if(m_Snake->touchWall())
		return true;
	if (m_Snake->biteItself())
		return true;
	return false;
}