#pragma once
#include "raylib.h"

#include "../tools.h"

struct PLAYER
{
	Vector2 XY;
	Vector2 speed;
	float startPosition;
	float maxJump;
	float width;
	float height;

	bool isJumping;

	int socre;
	int lives;
};

PLAYER CreatePlayer();

void PlayerInput(
	PLAYER& P1
);

void PlayerMove(
	PLAYER& P1
);