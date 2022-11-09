#include "game.h"

Texture2D FarBackground;
Texture2D NearBackgound1;
Texture2D NearBackgound2;
Texture2D FloorBackground;

static const int backGroundsTot = 2;

void Game(bool& closeGame)
{
	BackGroundPosition backGround[backGroundsTot];
	createBackGroundPosition(backGround);

	PLAYER P1 = CreatePlayer();

	P1.XY.y = static_cast<float>(backGround[0].floorBackGround.y - P1.height);

	P1.startPosition = P1.XY.y;
	P1.maxJump = P1.startPosition + P1.height * 4;

	OBSTACLE obstacle = CreateObstacle();

	obstacle.XY.y = static_cast<float>(backGround[0].floorBackGround.y - obstacle.height);

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
	DrawRectangle(static_cast<int>(obstacle.XY.x), static_cast<int>(obstacle.XY.y), static_cast<int>(obstacle.width), static_cast<int>(obstacle.height), GREEN);

	//draw Version
	DrawText("version 0.2", 0, 0, 20, BLACK);

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