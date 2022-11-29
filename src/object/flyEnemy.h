#pragma once
#include "raylib.h"
#include "raymath.h"

#include "tools.h"

struct FLYENEMY
{
	float x;
	float y;
	Vector2 speed;
	float width;
	float height;
	bool isAlive;
	bool isGoingDown;
};

void CreateFlyEnemy(
	FLYENEMY& flyEnemy
);

void FlyEnemyMove(
	FLYENEMY flyEnemy[]
);