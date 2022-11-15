#include "game.h"

Texture2D FarBackground;
Texture2D NearBackgound1;
Texture2D NearBackgound2;
Texture2D FloorBackground;
Texture2D enemy;
Texture2D dron1;
Texture2D bullet;

static const int backGroundsTot = 2;
static const int maxFlyEnemies = 3;
static const int maxBullets = 4;

void Game(bool& closeGame)
{
	BackGroundPosition backGround[backGroundsTot];
	createBackGroundPosition(backGround);

	PLAYER P1 = CreatePlayer();

	P1.XY.y = static_cast<float>(backGround[0].floorBackGround.y - P1.height);

	P1.startPosition = P1.XY.y;
	P1.maxJump = P1.startPosition + P1.height * 4;

	BULLET ArrayBullets[maxBullets];

	for (int i = 0; i < maxBullets; i++)
	{
		CreateBullet(ArrayBullets[i]);
		ArrayBullets[i].XY.x = P1.XY.x + P1.width / 2;
		ArrayBullets[i].XY.y = P1.XY.y;
	}

	OBSTACLE obstacle = CreateObstacle();

	obstacle.height = static_cast<float>(enemy.height);
	obstacle.width = static_cast<float>(enemy.width);
	obstacle.XY.y = static_cast<float>(backGround[0].floorBackGround.y - obstacle.height);

	FLYENEMY ArrayFlyEnemy[maxFlyEnemies];

	for (int i = 0; i < maxFlyEnemies; i++)
	{
		CreateFlyEnemy(ArrayFlyEnemy[i]);
		ArrayFlyEnemy[i].width = static_cast<float>(dron1.width);
		ArrayFlyEnemy[i].height = static_cast<float>(dron1.height);
	}

	const int amountObstacles = 1;

	while (!WindowShouldClose() && P1.lives > 0)
	{
		Draw(P1, obstacle, backGround, ArrayFlyEnemy, ArrayBullets);
		PlayerInput(P1, ArrayBullets);
		PlayerMove(P1);
		BulleMove(ArrayBullets, P1);
		ObjectMove(obstacle);
		FlyEnemyMove(ArrayFlyEnemy);
		ParalaxMove(backGround);
		CheckColision(obstacle, P1, ArrayFlyEnemy, ArrayBullets);
	}

	if (P1.lives <= 0)
	{
		closeGame = false;
	}

}

void Draw(PLAYER P1, OBSTACLE obstacle, BackGroundPosition backGround[], FLYENEMY ArrayFlyEnemy[], BULLET ArrayBullets[])
{
	BeginDrawing();
	ClearBackground(BLACK);

	//draw background
	DrawParalax(backGround);

	//draw player
	DrawRectangle(static_cast<int>(P1.XY.x), static_cast<int>(P1.XY.y), static_cast<int>(P1.width), static_cast<int>(P1.height), BLACK);

	//draw obstacle
	DrawRectangle(static_cast<int>(obstacle.XY.x), static_cast<int>(obstacle.XY.y), static_cast<int>(obstacle.width), static_cast<int>(obstacle.height), GREEN);
	DrawTexture(enemy, static_cast<int>(obstacle.XY.x), static_cast<int>(obstacle.XY.y), WHITE);

	//draw enemy
	for (int i = 0; i < maxFlyEnemies; i++)
	{
		if (ArrayFlyEnemy[i].isAlive)
		{
			DrawRectangle(
				static_cast<int>(ArrayFlyEnemy[i].x),
				static_cast<int>(ArrayFlyEnemy[i].y),
				static_cast<int>(ArrayFlyEnemy[i].width),
				static_cast<int>(ArrayFlyEnemy[i].height),
				GREEN);
			DrawTexture(dron1, static_cast<int>(ArrayFlyEnemy[i].x), static_cast<int>(ArrayFlyEnemy[i].y), WHITE);
		}
	}

	//draw bullet
	for (int i = 0; i < maxBullets; i++)
	{
		if (!ArrayBullets[i].isDestroyed)
		{
			DrawTexture(
				bullet,
				static_cast<int>(ArrayBullets[i].XY.x),
				static_cast<int>(ArrayBullets[i].XY.y),
				WHITE
			);
		}
	}

	//draw Version
	DrawText("version 0.3", 0, 0, 20, BLACK);

	EndDrawing();
}

void DrawParalax(BackGroundPosition backGround[])
{
	//far background
	DrawTexture(FarBackground,
		static_cast<int>(backGround[0].FarBackGround.x),
		static_cast<int>(backGround[0].FarBackGround.y),
		WHITE);

	DrawTexture(FarBackground,
		static_cast<int>(backGround[1].FarBackGround.x),
		static_cast<int>(backGround[1].FarBackGround.y),
		WHITE);

	//near background1
	DrawTexture(NearBackgound2,
		static_cast<int>(backGround[0].NearBackGround.x),
		static_cast<int>(backGround[0].NearBackGround.y),
		WHITE);
	DrawTexture(NearBackgound1,
		static_cast<int>(backGround[0].NearBackGround.x + NearBackgound1.width),
		static_cast<int>(backGround[0].NearBackGround.y),
		WHITE);
	DrawTexture(NearBackgound1,
		static_cast<int>(backGround[0].NearBackGround.x + NearBackgound1.width * 2),
		static_cast<int>(backGround[0].NearBackGround.y),
		WHITE);

	//near background2
	DrawTexture(NearBackgound1,
		static_cast<int>(backGround[1].NearBackGround.x),
		static_cast<int>(backGround[1].NearBackGround.y),
		WHITE);
	DrawTexture(NearBackgound2,
		static_cast<int>(backGround[1].NearBackGround.x + NearBackgound1.width),
		static_cast<int>(backGround[1].NearBackGround.y),
		WHITE);
	DrawTexture(NearBackgound1,
		static_cast<int>(backGround[1].NearBackGround.x + NearBackgound1.width * 2),
		static_cast<int>(backGround[1].NearBackGround.y),
		WHITE);

	//floor		
	DrawTexture(FloorBackground,
		static_cast<int>(backGround[0].floorBackGround.x),
		static_cast<int>(backGround[0].floorBackGround.y),
		WHITE);
	DrawTexture(FloorBackground,
		static_cast<int>(backGround[1].floorBackGround.x),
		static_cast<int>(backGround[1].floorBackGround.y),
		WHITE);
}

void ParalaxMove(BackGroundPosition backGround[])
{
	for (int i = 0; i < backGroundsTot; i++)
	{
		backGround[i].FarBackGround.x -= 50 * GetFrameTime();
		backGround[i].NearBackGround.x -= 100 * GetFrameTime();
		backGround[i].floorBackGround.x -= 200 * GetFrameTime();
	}

	for (int i = 0; i < backGroundsTot; i++)
	{
		if (backGround[i].FarBackGround.x < 0 - GetScreenWidth())
		{
			backGround[i].FarBackGround.x = static_cast<float>(GetScreenWidth());
		}

		if (backGround[i].NearBackGround.x < 0 - GetScreenWidth())
		{
			backGround[i].NearBackGround.x = static_cast<float>(GetScreenWidth());
		}

		if (backGround[i].floorBackGround.x < 0 - GetScreenWidth())
		{
			backGround[i].floorBackGround.x = static_cast<float>(GetScreenWidth());
		}
	}
}

void createBackGroundPosition(BackGroundPosition backGround[])
{
	for (int i = 0; i < backGroundsTot; i++)
	{
		if (i == 0)
		{
			backGround[i].FarBackGround.x = 0;
			backGround[i].NearBackGround.x = 0;
			backGround[i].floorBackGround.x = 0;
		}
		else
		{
			backGround[i].FarBackGround.x = static_cast<float>(GetScreenWidth());
			backGround[i].NearBackGround.x = static_cast<float>(GetScreenWidth());
			backGround[i].floorBackGround.x = static_cast<float>(GetScreenWidth());
		}


		backGround[i].FarBackGround.width = static_cast<float>(FarBackground.width);
		backGround[i].NearBackGround.width = static_cast<float>(NearBackgound1.width);
		backGround[i].floorBackGround.width = static_cast<float>(FloorBackground.width);

		backGround[i].FarBackGround.height = static_cast<float>(FarBackground.height);
		backGround[i].NearBackGround.height = static_cast<float>(NearBackgound1.height);
		backGround[i].floorBackGround.height = static_cast<float>(FloorBackground.height);

		backGround[i].FarBackGround.y = (GetPercentageScreenHeight(0));
		backGround[i].NearBackGround.y = GetScreenHeight() - backGround[i].floorBackGround.height - backGround[i].NearBackGround.height;
		backGround[i].floorBackGround.y = GetScreenHeight() - backGround[i].floorBackGround.height;
	}
}

void CheckColision(OBSTACLE& obstacle, PLAYER& P1, FLYENEMY ArrayFlyEnemy[], BULLET ArrayBullets[])
{
	CheckPlayerObstacle(obstacle, P1);
	CheckBulletFlyEnemy(ArrayFlyEnemy, ArrayBullets);
}

void CheckPlayerObstacle(OBSTACLE& obstacle, PLAYER& P1)
{
	if (CheckCollisionRecs(
		Rectangle{ obstacle.XY.x, obstacle.XY.y, obstacle.width, obstacle.height },
		Rectangle{ P1.XY.x, P1.XY.y, P1.width, P1.height }))
	{
		P1.lives--;
	}
}

void CheckBulletFlyEnemy(FLYENEMY ArrayFlyEnemy[], BULLET ArrayBullets[])
{
	for (int x = 0; x < maxFlyEnemies; x++)
	{
		for (int y = 0; y < maxBullets; y++)
		{
			if (CheckCollisionRecs(
				{ ArrayFlyEnemy[x].x ,
				ArrayFlyEnemy[x].y,
				ArrayFlyEnemy[x].width,
				ArrayFlyEnemy[x].height },

				{ ArrayBullets[y].XY.x ,
				ArrayBullets[y].XY.y,
				static_cast<float>(bullet.width),
				static_cast<float>(bullet.height) }))
			{
				ArrayFlyEnemy[x].isAlive = false;
				ArrayBullets[y].isDestroyed = true;
				ArrayBullets[y].isShooted = true;
			}
		}
	}
}