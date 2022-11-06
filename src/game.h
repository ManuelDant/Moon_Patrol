#pragma once
#include <iostream>

#include "raylib.h"
#include"tools/tools.h"

#include "object/player.h"
#include "object/obstacle.h"

using namespace std;

struct BackGroundPosition
{
	Rectangle FarBackGround;
	Rectangle NearBackGround;
	Rectangle floorBackGround;
};

void Game();

////////////////////////draw functions
void Draw(
	PLAYER P1,
	OBSTACLE obstacle,
	BackGroundPosition backGround[]
);
void DrawParalax(
	BackGroundPosition backGround[]
);

////////////////////////input function
void PlayerInput(
	PLAYER& P1
);

/////////////////////////move funciton
void PlayerMove(
	PLAYER& P1
);
void ObjectMove(
	OBSTACLE& obstacle
);
void ParalaxMove(
	BackGroundPosition backGround[]
);

/////////////////////Colision funciton
void CheckColision(
	OBSTACLE& obstacle,
	PLAYER& P1
);

void CheckPlayerObstacle(
	OBSTACLE& obstacle,
	PLAYER& P1
);

//create
void createBackGroundPosition(
	BackGroundPosition backGround[]
);