#include "Snake.h"
#include "Map.h"
#include "GamePlay.h"

int  main()
{
	srand(time(NULL));
	GamePlay gameplay;
	gameplay.run();
	system("pause");
	return 0;

}
