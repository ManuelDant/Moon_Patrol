#pragma once
#include "raylib.h"
#include "object/player.h"
#include "object/obstacle.h"

void Game();

///////////////////////draw functions
void Draw(
	PLAYER P1,
	OBSTACLE obstacle
);

///////////////////////input function
void PlayerInput();


///////////////////////move funciton
void PlayerMove(
	PLAYER& P1
);
void ObjectMove(
	OBSTACLE& obstacle
);