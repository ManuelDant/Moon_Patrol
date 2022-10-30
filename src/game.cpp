#include "game.h"

void Game()
{
	PLAYER P1 = CreatePlayer();

	const int amountObstacles = 1;
	OBSTACLE obstacle[amountObstacles];

	for (int i = 0; i < amountObstacles; i++)
	{
		CreateObstacle(obstacle[i]);
	}

	while (!WindowShouldClose())
	{

	}
}

void Draw(PLAYER P1, OBSTACLE obstacle)
{

}