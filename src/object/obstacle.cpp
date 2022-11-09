#include "obstacle.h"

OBSTACLE CreateObstacle()
{
	OBSTACLE obstacle{};

	obstacle.height = GetPercentageScreenHeight(10);
	obstacle.width = GetPercentageScreenWidth(10);

	obstacle.XY.x = static_cast<float>(GetScreenWidth());

	return obstacle;
}