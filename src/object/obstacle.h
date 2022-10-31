#pragma once
#include "raylib.h"

#include "../tools/tools.h"

struct OBSTACLE
{
	Vector2 XY;
	float width;
	float height;
};

OBSTACLE CreateObstacle();