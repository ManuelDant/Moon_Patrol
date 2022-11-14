#include "obstacle.h"

OBSTACLE CreateObstacle()
{
	OBSTACLE obstacle{};

	obstacle.height = GetPercentageScreenHeight(10);
	obstacle.width = GetPercentageScreenWidth(10);

	obstacle.XY.x = static_cast<float>(GetScreenWidth());

	return obstacle;
}

void ObjectMove(OBSTACLE& obstacle)
{
	obstacle.XY.x -= 200 * GetFrameTime();

	if (obstacle.XY.x < 0 - obstacle.width)
	{
		obstacle.XY.x = static_cast<float>(GetScreenWidth());
	}
}