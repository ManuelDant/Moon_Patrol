#pragma once
#include "raylib.h"

#include "../tools/tools.h"

struct PLAYER
{
	Vector2 XY;
	Vector2 speed;
	float width;
	float height;

	bool isJumping;
	float jumpTime;

	int lives;
};

PLAYER CreatePlayer();