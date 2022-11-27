#pragma once
#include <iostream>

#include "raylib.h"
#include "tools.h"

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
	PLAYER P2,
	OBSTACLE obstacle,
	BackGroundPosition backGround[],
	FLYENEMY ArrayFlyEnemy[],
	BULLET ArrayBullets[],
	BULLET ArrayBulletsP2[]
);
void DrawParalax(
	BackGroundPosition backGround[]
);
void ParalaxMove(
	BackGroundPosition backGround[]
);
void CreateBackGroundPosition(
	BackGroundPosition backGround[]
);

void Activate1Player();
void Activate2Players();

/////////////////////Colision funciton
void CheckColision(
	OBSTACLE& obstacle,
	PLAYER& P1,
	PLAYER& P2,
	FLYENEMY ArrayFlyEnemy[],
	BULLET ArrayBullets[],
	BULLET ArrayBulletsP2[]
);

void CheckPlayerObstacle(
	OBSTACLE& obstacle,
	PLAYER& P1,
	PLAYER& P2,
	FLYENEMY ArrayFlyEnemy[],
	BULLET ArrayBullets[],
	BULLET ArrayBulletsP2[]
);


void CheckBulletFlyEnemy(
	FLYENEMY ArrayFlyEnemy[],
	BULLET ArrayBullets[],
	BULLET ArrayBulletsP2[]
);

void Pause();

bool ExitPause();

void RestartGame(OBSTACLE& obstacle,
	PLAYER& P1,
	PLAYER& P2,
	FLYENEMY ArrayFlyEnemy[],
	BULLET ArrayBullets[],
	BULLET ArrayBulletsP2[]
);
