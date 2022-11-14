#include "player.h"

PLAYER CreatePlayer()
{
	PLAYER P1{};
	P1.height = GetPercentageScreenHeight(25);
	P1.width = GetPercentageScreenWidth(15);

	P1.XY.x = static_cast<float>(GetScreenWidth()/4);

	P1.speed.x = 0;
	P1.speed.y = 0;

	P1.isJumping = false;

	P1.lives = 1;

	return P1;
}

void PlayerInput(PLAYER& P1)
{
	if ((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) && !P1.isJumping)
	{
		P1.speed.y = -600;
		P1.isJumping = true;
	}

	if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
	{
		P1.speed.x = 200;
	}
	else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
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