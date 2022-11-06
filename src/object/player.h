#pragma once
#include "raylib.h"

#include "../tools/tools.h"

struct PLAYER
{
	Vector2 XY;
	Vector2 speed;
	float startPosition;
	float maxJump;
	float width;
	float height;

	bool isJumping;

	int lives;
};

PLAYER CreatePlayer();