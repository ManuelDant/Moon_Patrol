#include "obstacle.h"

OBSTACLE CreateObstacle()
{
	OBSTACLE obstacle{};

	obstacle.height = 25;
	obstacle.width = 25;

	obstacle.XY.x = static_cast<float>(GetScreenWidth());
	obstacle.XY.y = static_cast<float>(GetPercentageScreenHeight(80) - obstacle.height);

	return obstacle;
}