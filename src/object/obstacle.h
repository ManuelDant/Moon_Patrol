#pragma once
#include "raylib.h"

#include "../tools.h"

struct OBSTACLE
{
	Vector2 XY;
	float width;
	float height;
	int checkCollision = 0;
};

OBSTACLE CreateObstacle();

void ObjectMove(
	OBSTACLE& obstacle
);