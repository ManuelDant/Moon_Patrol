#include "game.h"
#include "score.h"

Texture2D farBackground;
Texture2D nearBackgound1;
Texture2D nearBackgound2;
Texture2D floorBackground;
Texture2D enemy;
Texture2D pauseButton;
Texture2D dron1;
Texture2D bullet;
Texture2D playerimg;

static const int backGroundsTot = 2;
static const int maxFlyEnemies = 3;
static const int maxBullets = 4;

static bool isPlayer2 = false;

bool pause = false;

void Game(bool& closeGame)
{
	BackGroundPosition backGround[backGroundsTot];
	CreateBackGroundPosition(backGround);

	PLAYER P1 = CreatePlayer();
	PLAYER P2 = CreatePlayer2();

	P1.XY.y = static_cast<float>(backGround[0].floorBackGround.y - P1.height);

	P1.startPosition = P1.XY.y;
	P1.maxJump = P1.startPosition + P1.height * 4;

	P2.XY.y = static_cast<float>(backGround[0].floorBackGround.y - P2.height);

	P2.startPosition = P2.XY.y;
	P2.maxJump = P2.startPosition + P2.height * 4;

	BULLET ArrayBullets[maxBullets];
	BULLET ArrayBulletsP2[maxBullets];

	for (int i = 0; i < maxBullets; i++)
	{
		CreateBullet(ArrayBullets[i]);
		ArrayBullets[i].XY.x = P1.XY.x + P1.width / 2;
		ArrayBullets[i].XY.y = P1.XY.y;
	}

	for (int i = 0; i < maxBullets; i++)
	{
		CreateBullet(ArrayBulletsP2[i]);
		ArrayBulletsP2[i].XY.x = P2.XY.x + P2.width / 2;
		ArrayBulletsP2[i].XY.y = P2.XY.y;
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

	while (!WindowShouldClose() && P1.lives > 0 && P2.lives > 0)
	{
		Draw(P1,P2, obstacle, backGround, ArrayFlyEnemy, ArrayBullets, ArrayBulletsP2);
		if (!pause)
		{
			PlayerInput(P1, ArrayBullets);
			PlayerMove(P1);
			BulleMove(ArrayBullets, P1);
			ObjectMove(obstacle);
			FlyEnemyMove(ArrayFlyEnemy);
			ParalaxMove(backGround);
			CheckColision(obstacle, P1, P2, ArrayFlyEnemy, ArrayBullets, ArrayBulletsP2);

			if (isPlayer2)
			{
				Player2Input(P2, ArrayBulletsP2);
				Player2Move(P2);
				BulleMovePlayer2(ArrayBulletsP2, P2);
			}

			if (IsKeyReleased(KEY_ESCAPE))
			{
				pause = true;
			}
		}
		else
		{
			Pause();
			if (IsKeyReleased(KEY_SPACE))
			{
				P1.lives = 0;
				pause = false;
				RestartScore();
			}
		}
		
	}

	if (P1.lives <= 0)
	{
		closeGame = false;
	}

	if (P2.lives <= 0)
	{
		closeGame = false;
	}

}

void Draw(PLAYER P1, PLAYER P2, OBSTACLE obstacle, BackGroundPosition backGround[], FLYENEMY ArrayFlyEnemy[], BULLET ArrayBullets[], BULLET ArrayBulletsP2[])
{
	BeginDrawing();
	ClearBackground(BLACK);

	//draw background
	DrawParalax(backGround);
	DrawScore();

	//draw player
	int adjustPosition = 20;
	DrawTexture(playerimg, static_cast<int>(P1.XY.x), static_cast<int>(P1.XY.y - adjustPosition), WHITE);
	if (isPlayer2)
	{
		DrawTexture(playerimg, static_cast<int>(P2.XY.x), static_cast<int>(P2.XY.y - adjustPosition), RED);
	}

	//draw obstacle
	DrawTexture(enemy, static_cast<int>(obstacle.XY.x), static_cast<int>(obstacle.XY.y), WHITE);

	//draw enemy
	for (int i = 0; i < maxFlyEnemies; i++)
	{
		if (ArrayFlyEnemy[i].isAlive)
		{
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

		if (!ArrayBulletsP2[i].isDestroyed)
		{
			DrawTexture(
				bullet,
				static_cast<int>(ArrayBulletsP2[i].XY.x),
				static_cast<int>(ArrayBulletsP2[i].XY.y),
				WHITE
			);
		}
		if (ArrayBullets[i].isDestroyed == true && ArrayBullets[i].isShooted == true)
		{
			ArrayBullets[i].isDestroyed = false;
		}
	}

	//draw Version
	DrawText("version 1.0", 0, 0, 20, BLACK);
	UpdateMaxScore();

	if (pause)
	{
		DrawTexture(pauseButton, static_cast<int>(GetPercentageScreenWidth(30)), static_cast<int>(GetPercentageScreenHeight(5)), WHITE);
		DrawText("Game Paused", (GetScreenWidth() / 2) - (MeasureText("Game Paused", 45) / 2 - 80), static_cast<int>(GetPercentageScreenHeight(22)), 45, BLACK);
		DrawText("ESC to Resume", (GetScreenWidth() / 2) - (MeasureText("ESC to Resume", 47) / 2), static_cast<int>(GetPercentageScreenHeight(60)), 47, BLACK);
		DrawText("SPACE to Go Menu", (GetScreenWidth() / 2) - (MeasureText("SPACE to Go Menu", 45) / 2), static_cast<int>(GetPercentageScreenHeight(70)), 45, BLACK);
	}
	EndDrawing();
}

void Activate2Players() {
	isPlayer2 = true;
}

void Activate1Player() {
	isPlayer2 = false;
}

void DrawParalax(BackGroundPosition backGround[])
{
	//far background
	DrawTexture(farBackground,
		static_cast<int>(backGround[0].FarBackGround.x),
		static_cast<int>(backGround[0].FarBackGround.y),
		WHITE);

	DrawTexture(farBackground,
		static_cast<int>(backGround[1].FarBackGround.x),
		static_cast<int>(backGround[1].FarBackGround.y),
		WHITE);

	//near background1
	DrawTexture(nearBackgound2,
		static_cast<int>(backGround[0].NearBackGround.x),
		static_cast<int>(backGround[0].NearBackGround.y),
		WHITE);
	DrawTexture(nearBackgound1,
		static_cast<int>(backGround[0].NearBackGround.x + nearBackgound1.width),
		static_cast<int>(backGround[0].NearBackGround.y),
		WHITE);
	DrawTexture(nearBackgound1,
		static_cast<int>(backGround[0].NearBackGround.x + nearBackgound1.width * 2),
		static_cast<int>(backGround[0].NearBackGround.y),
		WHITE);

	//near background2
	DrawTexture(nearBackgound1,
		static_cast<int>(backGround[1].NearBackGround.x),
		static_cast<int>(backGround[1].NearBackGround.y),
		WHITE);
	DrawTexture(nearBackgound2,
		static_cast<int>(backGround[1].NearBackGround.x + nearBackgound1.width),
		static_cast<int>(backGround[1].NearBackGround.y),
		WHITE);
	DrawTexture(nearBackgound1,
		static_cast<int>(backGround[1].NearBackGround.x + nearBackgound1.width * 2),
		static_cast<int>(backGround[1].NearBackGround.y),
		WHITE);

	//floor		
	DrawTexture(floorBackground,
		static_cast<int>(backGround[0].floorBackGround.x),
		static_cast<int>(backGround[0].floorBackGround.y),
		WHITE);
	DrawTexture(floorBackground,
		static_cast<int>(backGround[1].floorBackGround.x),
		static_cast<int>(backGround[1].floorBackGround.y),
		WHITE);
}

void ParalaxMove(BackGroundPosition backGround[])
{
	int speedFarBG = 50;
	int speedNearBG = 100;
	int speedFloorBG = 200;
	for (int i = 0; i < backGroundsTot; i++)
	{
		backGround[i].FarBackGround.x -= speedFarBG * GetFrameTime();
		backGround[i].NearBackGround.x -= speedNearBG * GetFrameTime();
		backGround[i].floorBackGround.x -= speedFloorBG * GetFrameTime();
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

void CreateBackGroundPosition(BackGroundPosition backGround[])
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


		backGround[i].FarBackGround.width = static_cast<float>(farBackground.width);
		backGround[i].NearBackGround.width = static_cast<float>(nearBackgound1.width);
		backGround[i].floorBackGround.width = static_cast<float>(floorBackground.width);

		backGround[i].FarBackGround.height = static_cast<float>(farBackground.height);
		backGround[i].NearBackGround.height = static_cast<float>(nearBackgound1.height);
		backGround[i].floorBackGround.height = static_cast<float>(floorBackground.height);

		backGround[i].FarBackGround.y = (GetPercentageScreenHeight(0));
		backGround[i].NearBackGround.y = GetScreenHeight() - backGround[i].floorBackGround.height - backGround[i].NearBackGround.height;
		backGround[i].floorBackGround.y = GetScreenHeight() - backGround[i].floorBackGround.height;
	}
}

void CheckColision(OBSTACLE& obstacle, PLAYER& P1, PLAYER& P2, FLYENEMY ArrayFlyEnemy[], BULLET ArrayBullets[], BULLET ArrayBulletsP2[])
{
	CheckPlayerObstacle(obstacle, P1, P2, ArrayFlyEnemy, ArrayBullets, ArrayBulletsP2);
	CheckBulletFlyEnemy(ArrayFlyEnemy, ArrayBullets, ArrayBulletsP2);
}

void CheckPlayerObstacle(OBSTACLE& obstacle, PLAYER& P1, PLAYER& P2, FLYENEMY ArrayFlyEnemy[], BULLET ArrayBullets[], BULLET ArrayBulletsP2[])
{
	int checkAddScore = 1;

	if (CheckCollisionRecs(
		Rectangle{ obstacle.XY.x, obstacle.XY.y, obstacle.width, obstacle.height },
		Rectangle{ P1.XY.x, P1.XY.y, P1.width, P1.height }))
	{
		RestartGame(obstacle, P1, P2, ArrayFlyEnemy, ArrayBullets, ArrayBulletsP2);
		RestartScore();
	}

	
	if (CheckCollisionRecs(
		Rectangle{ obstacle.XY.x, obstacle.XY.y - obstacle.height,obstacle.width / 4,obstacle.height },
		Rectangle{ P1.XY.x, P1.XY.y, P1.width, P1.height }))
	{
		obstacle.checkCollision++;
		if (obstacle.checkCollision == checkAddScore)
		{
			AddScore(1);

		}	
	}
	else
	{
		obstacle.checkCollision = 0;
	}

	if (isPlayer2)
	{
		if (CheckCollisionRecs(
			Rectangle{ obstacle.XY.x, obstacle.XY.y, obstacle.width, obstacle.height },
			Rectangle{ P2.XY.x, P2.XY.y, P2.width, P2.height }))
		{
			RestartGame(obstacle, P1, P2, ArrayFlyEnemy, ArrayBullets, ArrayBulletsP2);
			RestartScore();
		}

		if (CheckCollisionRecs(
			Rectangle{ obstacle.XY.x, obstacle.XY.y - obstacle.height,obstacle.width / 4,obstacle.height },
			Rectangle{ P2.XY.x, P2.XY.y, P2.width, P2.height }))
		{
			obstacle.checkCollisionP2++;
			if (obstacle.checkCollisionP2 == checkAddScore)
			{
				AddScore(1);
			}
		}
		else
		{
			obstacle.checkCollisionP2 = 0;
		}
	}	

}

void CheckBulletFlyEnemy(FLYENEMY ArrayFlyEnemy[], BULLET ArrayBullets[], BULLET ArrayBulletsP2[])
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
				AddScore(1); //Suma +3 Puntos.		
				ArrayFlyEnemy[x].isAlive = false;
				ArrayBullets[y].isShooted = true;
			}


			if (CheckCollisionRecs(
				{ ArrayFlyEnemy[x].x ,
				ArrayFlyEnemy[x].y,
				ArrayFlyEnemy[x].width,
				ArrayFlyEnemy[x].height },

				{ ArrayBulletsP2[y].XY.x ,
				ArrayBulletsP2[y].XY.y,
				static_cast<float>(bullet.width),
				static_cast<float>(bullet.height) }))
			{
				AddScore(1); //Suma +3 Puntos.
				ArrayFlyEnemy[x].isAlive = false;
				ArrayBulletsP2[y].isShooted = true;
			}
		}
	}
}

void Pause() {
	if (IsKeyReleased(KEY_ESCAPE))
	{
		pause = false;
		
	}
}

bool ExitPause() {
	if (pause)
	{
		if (IsKeyReleased(KEY_SPACE))
		{
			return true;
		}
	}
	return false;
}

void RestartGame(OBSTACLE& obstacle, PLAYER& P1, PLAYER& P2, FLYENEMY ArrayFlyEnemy[], BULLET ArrayBullets[], BULLET ArrayBulletsP2[]) {
	float outScreen = -200;

	P1.XY.x = GetPercentageScreenWidth(15);
	P1.XY.y = GetPercentageScreenHeight(66);

	P2.XY.x = GetPercentageScreenWidth(10);
	P2.XY.y = GetPercentageScreenHeight(66);
	obstacle.XY.x = GetScreenWidth() + obstacle.width;

	for (int i = 0; i < maxBullets; i++)
	{
		ArrayBullets[i].XY.y = outScreen;
		ArrayBulletsP2[i].XY.y = outScreen;
	}

	for (int i = 0; i < maxFlyEnemies; i++)
	{
		ArrayFlyEnemy[i].x = 0 - ArrayFlyEnemy[i].width;
	}
}
