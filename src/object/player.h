#pragma once
#include "raylib.h"

#include "../tools/tools.h"

struct PLAYER
{
	Vector2 XY;
	float width;
	float height;

	int lives;
};

PLAYER CreatePlayer();