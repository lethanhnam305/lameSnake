#include "Snake.h"

Snake* Snake::m_Instance = NULL;

Snake::Snake()
{
	length = 3;
	head = new Coordinate[3];
//Create the initial coordinates of the snake
	head[0].x = 36;
	head[0].y = 20;
	head[1].x = 34;
	head[1].y = 20;
	head[2].x = 32;
	head[2].y = 20;
	Status = RIGHT;
}

Snake::~Snake()
{
	if (m_Instance)
		m_Instance = NULL;
	delete[] head;
}

Snake* Snake::createSnake()
{
	if (m_Instance == NULL)
		m_Instance = new Snake();
	return m_Instance;
}

int Snake::getX()
{
	return head[0].x;
}

int Snake::getY()
{
	return head[0].y;
}

int Snake::getLength()
{
	return length;
}

void Snake::snakeGrowth()
{
	length++;
}
void Snake::print()
{
	for (int i = length-1; i >= 0; i--)
	{
		gotoXY(head[i].x, head[i].y);
		if (i == 0)
			putchar(254);
		else
			puts("o");
	}

}

void Snake::move()
{
	for (int i = length - 1 ; i > 0 ; i--)
		head[i] = head[i- 1];

//To recognize whether we touch the keyboard or not
	if (_kbhit()) 
	{	
		// Memorize the character we pressed
		char stt = _getch();

		if ((stt == 's' || stt == 'S') && Status != UP) {
			Status = DOWN;
		}
		else if ((stt == 'w' || stt == 'W') && Status != DOWN) {
			Status = UP;
		}
		else if ((stt == 'a' || stt == 'A') && Status != RIGHT) {
			Status = LEFT;
		}
		else if ((stt == 'd' || stt == 'D') && Status != LEFT) {
			Status = RIGHT;
		}
	}

//Movement
	if (Status == UP)
		head[0].y--;
	else if (Status == DOWN)
		head[0].y++;
	else if (Status == LEFT)
		head[0].x -= 2 ;
	else if (Status == RIGHT)
		head[0].x += 2 ;
}

bool Snake::touchWall()
{
	if (head[0].x == 30 || head[0].x == 90 || head[0].y == 1 || head[0].y == 28)
		return true;
	return false;
}

bool Snake::biteItself()
{
	for (int i = 1; i < length; i++)
		if (head[0].x == head[i].x && head[0].y == head[i].y)
			return true;
	return false;
}
