#include "game.h"

Texture2D FarBackground;
Texture2D NearBackgound1;
Texture2D NearBackgound2;
Texture2D FloorBackground;

static const int backGroundsTot = 2;

void Game(bool& closeGame)
{
	PLAYER P1 = CreatePlayer();
	OBSTACLE obstacle = CreateObstacle();

	BackGroundPosition backGround[backGroundsTot];
	createBackGroundPosition(backGround);

	const int amountObstacles = 1;

	while (!WindowShouldClose() && P1.lives > 0)
	{
		Draw(P1, obstacle, backGround);
		PlayerInput(P1);
		PlayerMove(P1);
		ObjectMove(obstacle);
		ParalaxMove(backGround);
		CheckColision(obstacle, P1);
	}

	if (P1.lives <= 0)
	{
		closeGame = false;
	}

}

void Draw(PLAYER P1, OBSTACLE obstacle, BackGroundPosition backGround[])
{
	BeginDrawing();
	ClearBackground(BLACK);

	//draw background
	DrawParalax(backGround);

	//draw player
	DrawRectangle(static_cast<int>(P1.XY.x), static_cast<int>(P1.XY.y), static_cast<int>(P1.width), static_cast<int>(P1.height), BLACK);

	//draw obstacle
	DrawRectangle(static_cast<int>(obstacle.XY.x), static_cast<int>(obstacle.XY.y), static_cast<int>(obstacle.width), static_cast<int>(obstacle.height), WHITE);

	//draw Version
	DrawText("version 0.1", GetScreenWidth() - MeasureText("version 0.1", 10), GetScreenHeight() - 10, 10, WHITE);

	EndDrawing();
}

void DrawParalax(BackGroundPosition backGround[])
{
	//far background
	DrawRectangleRec(backGround[0].FarBackGround, RED);
	DrawRectangleRec(backGround[1].FarBackGround, Color{230, 0, 55, 255});
							
	//near background
	DrawRectangleRec(backGround[0].NearBackGround, BLUE);
	DrawRectangleRec(backGround[1].NearBackGround, Color{ 41, 121, 241, 255 });

							
	//floor		
	DrawRectangleRec(backGround[0].floorBackGround, GREEN);
	DrawRectangleRec(backGround[1].floorBackGround, Color{ 41, 255, 48, 255 });
}

void PlayerInput(PLAYER& P1)
{
	if (IsKeyPressed(KEY_UP) && !P1.isJumping)
	{
		P1.speed.y = -600;
		P1.isJumping = true;
	}

	if (IsKeyDown(KEY_RIGHT))
	{
		P1.speed.x = 200;
	}
	else if (IsKeyDown(KEY_LEFT))
	{
		P1.speed.x = -200;
	}
	else if (!P1.isJumping)
	{
		P1.speed.x = 0;
	}

}

void PlayerMove(PLAYER& P1)
{
	P1.XY.x += P1.speed.x * GetFrameTime();
	P1.XY.y += P1.speed.y * GetFrameTime();

	if (P1.isJumping)
	{
		P1.speed.y += 900 * GetFrameTime();
	}

	if (P1.XY.y > P1.startPosition)
	{
		P1.speed.y = 0;
		P1.isJumping = false;
	}

	if (P1.XY.x < 0)
	{
		P1.XY.x = 0;
	}

	if (P1.XY.x + P1.width > GetScreenWidth()/2)
	{
		P1.XY.x = GetScreenWidth()/2 - P1.width;
	}

}

void ObjectMove(OBSTACLE& obstacle)
{
	obstacle.XY.x -= 200 * GetFrameTime();

	if (obstacle.XY.x < 0)
	{
		obstacle.XY.x = static_cast<float>(GetScreenWidth());
	}
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
		if (backGround[i].FarBackGround.x < 0 - backGround[i].FarBackGround.width)
		{
			backGround[i].FarBackGround.x = static_cast<float>(GetScreenWidth());
		}

		if (backGround[i].NearBackGround.x < 0 - backGround[i].NearBackGround.width)
		{
			backGround[i].NearBackGround.x = static_cast<float>(GetScreenWidth());
		}

		if (backGround[i].floorBackGround.x < 0 - backGround[i].floorBackGround.width)
		{
			backGround[i].floorBackGround.x = static_cast<float>(GetScreenWidth());
		}
	}
}

void CheckColision(OBSTACLE& obstacle, PLAYER& P1)
{
	CheckPlayerObstacle(obstacle, P1);
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

		backGround[i].FarBackGround.y = (GetPercentageScreenHeight(0));
		backGround[i].NearBackGround.y = (GetPercentageScreenHeight(45));
		backGround[i].floorBackGround.y = (GetPercentageScreenHeight(90));

		backGround[i].FarBackGround.width = static_cast<float>(GetScreenWidth());
		backGround[i].NearBackGround.width = static_cast<float>(GetScreenWidth());
		backGround[i].floorBackGround.width = static_cast<float>(GetScreenWidth());

		backGround[i].FarBackGround.height = (GetPercentageScreenHeight(100));
		backGround[i].NearBackGround.height = (GetPercentageScreenHeight(55));
		backGround[i].floorBackGround.height = (GetPercentageScreenHeight(10));
	}
}