#pragma once
#include "raylib.h"

#include "../tools.h"

struct OBSTACLE
{
	Vector2 XY;
	float width;
	float height;
};

OBSTACLE CreateObstacle();

void ObjectMove(
	OBSTACLE& obstacle
);