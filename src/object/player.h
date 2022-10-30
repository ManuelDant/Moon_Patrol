#pragma once
#include "raylib.h"

struct PLAYER
{
	Vector2 XY;
	float width;
	float height;
};

PLAYER CreatePlayer();