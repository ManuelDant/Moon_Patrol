#include "obstacle.h"

OBSTACLE CreateObstacle()
{
	OBSTACLE obstacle{};

	obstacle.height = 50;
	obstacle.width = 50;

	obstacle.XY.x = static_cast<float>(GetScreenWidth());

	return obstacle;
}