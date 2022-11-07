#include "obstacle.h"

OBSTACLE CreateObstacle()
{
	OBSTACLE obstacle{};

	obstacle.height = 50;
	obstacle.width = 50;

	obstacle.XY.x = static_cast<float>(GetScreenWidth());
	obstacle.XY.y = static_cast<float>(GetPercentageScreenHeight(90) - obstacle.height);

	return obstacle;
}