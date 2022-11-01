#include "game.h"

void Game()
{
	PLAYER P1 = CreatePlayer();
	OBSTACLE obstacle = CreateObstacle();

	const int amountObstacles = 1;

	while (!WindowShouldClose() && P1.lives > 0)
	{
		Draw(P1, obstacle);
		PlayerInput(P1);
		PlayerMove(P1);
		ObjectMove(obstacle);
		CheckColision(obstacle, P1);
	}
}

void Draw(PLAYER P1, OBSTACLE obstacle)
{
	BeginDrawing();
	ClearBackground(BLACK);

	//draw background
	DrawLine(0, static_cast<int>(GetPercentageScreenHeight(80)), GetScreenWidth(), static_cast<int>(GetPercentageScreenHeight(80)), WHITE);

	//draw player
	DrawRectangle(static_cast<int>(P1.XY.x), static_cast<int>(P1.XY.y), static_cast<int>(P1.width), static_cast<int>(P1.height), WHITE);

	//draw obstacle
	DrawRectangle(static_cast<int>(obstacle.XY.x), static_cast<int>(obstacle.XY.y), static_cast<int>(obstacle.width), static_cast<int>(obstacle.height), WHITE);

	//draw Version
	DrawText("version 0.1", GetScreenWidth() - MeasureText("version 0.1", 10), GetScreenHeight() - 10, 10, WHITE);

	EndDrawing();
}

void PlayerInput(PLAYER& P1)
{
	if (IsKeyPressed(KEY_UP) && !P1.isJumping)
	{
		P1.speed.y = -600;
		P1.isJumping = true;
	}
}

void PlayerMove(PLAYER& P1)
{
	P1.XY.x += P1.speed.x * GetFrameTime();
	P1.XY.y += P1.speed.y * GetFrameTime();

	if (P1.isJumping)
	{
		P1.speed.y += 0.4f;
	}

	if (P1.XY.y + P1.height> static_cast<int>(GetPercentageScreenHeight(80)))
	{
		P1.speed.y = 0;
		P1.isJumping = false;
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

void CheckColision(OBSTACLE& obstacle, PLAYER& P1)
{
	CheckPlayerObstacle(obstacle, P1);
}

void CheckPlayerObstacle(OBSTACLE& obstacle, PLAYER& P1)
{
	if (CheckCollisionRecs(
		Rectangle{obstacle.XY.x, obstacle.XY.y, obstacle.width, obstacle.height}, 
		Rectangle{ P1.XY.x, P1.XY.y, P1.width, P1.height}))
	{
		P1.lives--;
	}
}