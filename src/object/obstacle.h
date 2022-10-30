#pragma once
#include "raylib.h"

struct OBSTACLE
{
	Vector2 XY;
	float width;
	float height;
};

void CreateObstacle(OBSTACLE& obstacle);