#pragma once
#include <iostream>

#include "raylib.h"
#include"tools.h"

#include "object/player.h"
#include "object/obstacle.h"
#include "object/flyEnemy.h"

using namespace std;

struct BackGroundPosition
{
	Rectangle FarBackGround;
	Rectangle NearBackGround;
	Rectangle floorBackGround;
};

void Game(
	bool& closeGame
);

////////////////////////draw functions
void Draw(
	PLAYER P1,
	OBSTACLE obstacle,
	BackGroundPosition backGround[],
	FLYENEMY ArrayFlyEnemy[]
);
void DrawParalax(
	BackGroundPosition backGround[]
);
void ParalaxMove(
	BackGroundPosition backGround[]
);
void createBackGroundPosition(
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