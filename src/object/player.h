#pragma once
#include "raylib.h"

#include "../tools.h"

//PLAYER
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

struct BULLET
{
	Vector2 XY;
	float speed;
	bool isDestroyed;
	bool isShooted;
};

PLAYER CreatePlayer();

void PlayerInput(
	PLAYER& P1, BULLET ArrayBullets[]
);

void PlayerMove(
	PLAYER& P1
);

void CreateBullet(
	BULLET& ArrayBullets
);

void BulleMove(
	BULLET ArrayBullets[],
	PLAYER P1
);