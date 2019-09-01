#include "Map.h"

Map* Map::m_Instance = NULL;

Map* Map::createMap()
{
	if (m_Instance == NULL)
		m_Instance = new Map;
	return m_Instance;
}
Map::Map()
{
}

Map::~Map()
{
	if (m_Instance)
		m_Instance = NULL;
}

void Map::draw()
{
	for (int i = 1; i < 29; i++)
	{
		gotoXY(30, i);
		putchar('*');
		gotoXY(90, i);
		putchar('*');
	}

	for (int i = 30; i < 90; i+=2)
	{
		gotoXY(i, 1);
		putchar('*');
		gotoXY(i, 28);
		putchar('*');
	}
	
}