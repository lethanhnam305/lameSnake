#include "Food.h"

Food::Food()
{
	do {
		Coordinate.x = 31 + rand () % 59;
	} while (Coordinate.x % 2);
	Coordinate.y = 20;
}

 Food* Food::m_Instance = NULL;

 Food* Food::createFood()
 {
	 if (m_Instance == NULL)
		 m_Instance = new Food;
	 return m_Instance;
 }

 int Food::getX()
 {
	 return Coordinate.x;
 }

 int Food::getY()
 {
	 return Coordinate.y;
 }
 void Food::resetPos()
 {
	 do{
		 Coordinate.x = 31 + rand() % 59;
	 } while (Coordinate.x % 2);
	 Coordinate.y = 2 + rand() % 26;
 }
 void Food::print()
 {
	 gotoXY(Coordinate.x, Coordinate.y);
	 puts("0");
 }