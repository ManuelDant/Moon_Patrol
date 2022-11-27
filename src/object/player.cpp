#include "player.h"

static const int maxBullets = 4;

PLAYER CreatePlayer()
{
	PLAYER P1{};
	P1.height = GetPercentageScreenHeight(25);
	P1.width = GetPercentageScreenWidth(10);

	P1.XY.x = static_cast<float>(GetScreenWidth()/4);

	P1.speed.x = 0;
	P1.speed.y = 0;

	P1.isJumping = false;

	P1.lives = 1;

	return P1;
}

PLAYER CreatePlayer2() {
	PLAYER P2{};
	P2.height = GetPercentageScreenHeight(25);
	P2.width = GetPercentageScreenWidth(10);

	P2.XY.x = static_cast<float>(GetScreenWidth() / 7);

	P2.speed.x = 0;
	P2.speed.y = 0;

	P2.isJumping = false;

	P2.lives = 1;

	return P2;
}

void PlayerInput(PLAYER& P1, BULLET ArrayBullets[])
{

	if ((IsKeyPressed(KEY_W)) && !P1.isJumping)
	{
		P1.speed.y = -600;
		P1.isJumping = true;
	}

	if (IsKeyDown(KEY_D))
	{
		P1.speed.x = 200;
	}
	else if (IsKeyDown(KEY_A))
	{
		P1.speed.x = -200;
	}
	else if (!P1.isJumping)
	{
		P1.speed.x = 0;
	}

	if (IsKeyPressed(KEY_SPACE))
	{
		for (int i = 0; i < maxBullets; i++)
		{
			if (!ArrayBullets[i].isShooted && ArrayBullets[i].isDestroyed)
			{
				ArrayBullets[i].isShooted = true;
				ArrayBullets[i].isDestroyed = false;
				i = maxBullets;
			}
		}
	}

}

void Player2Input(PLAYER& P2, BULLET ArrayBullets[])
{

	if ((IsKeyPressed(KEY_UP)) && !P2.isJumping)
	{
		P2.speed.y = -600;
		P2.isJumping = true;
	}

	if (IsKeyDown(KEY_RIGHT))
	{
		P2.speed.x = 200;
	}
	else if (IsKeyDown(KEY_LEFT))
	{
		P2.speed.x = -200;
	}
	else if (!P2.isJumping)
	{
		P2.speed.x = 0;
	}

	if (IsKeyPressed(KEY_ENTER))
	{
		for (int i = 0; i < maxBullets; i++)
		{
			if (!ArrayBullets[i].isShooted && ArrayBullets[i].isDestroyed)
			{
				ArrayBullets[i].isShooted = true;
				ArrayBullets[i].isDestroyed = false;
				i = maxBullets;
			}
		}
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

void Player2Move(PLAYER& P2)
{
	P2.XY.x += P2.speed.x * GetFrameTime();
	P2.XY.y += P2.speed.y * GetFrameTime();

	if (P2.isJumping)
	{
		P2.speed.y += 900 * GetFrameTime();
	}

	if (P2.XY.y > P2.startPosition)
	{
		P2.speed.y = 0;
		P2.isJumping = false;
	}

	if (P2.XY.x < 0)
	{
		P2.XY.x = 0;
	}

}

void CreateBullet(BULLET& ArrayBullets)
{
	ArrayBullets.XY.x;
	ArrayBullets.XY.y;

	ArrayBullets.speed = 400;

	ArrayBullets.isDestroyed = true;
	ArrayBullets.isShooted = false;
}

void BulleMove(BULLET ArrayBullets[], PLAYER P1)
{
	for (int i = 0; i < maxBullets; i++)
	{
		if (ArrayBullets[i].isShooted && !ArrayBullets[i].isDestroyed)
		{
			ArrayBullets[i].XY.y -= ArrayBullets[i].speed * GetFrameTime();
		}

		if (ArrayBullets[i].XY.y < 0)
		{
			ArrayBullets[i].isShooted = false;
			ArrayBullets[i].isDestroyed = true;
		}

		if (ArrayBullets[i].isDestroyed)
		{
			ArrayBullets[i].XY.x = P1.XY.x + P1.width / 2;
			ArrayBullets[i].XY.y = P1.XY.y;
		}

	}
}

void BulleMovePlayer2(BULLET ArrayBullets[], PLAYER P2)
{
	for (int i = 0; i < maxBullets; i++)
	{
		if (ArrayBullets[i].isShooted && !ArrayBullets[i].isDestroyed)
		{
			ArrayBullets[i].XY.y -= ArrayBullets[i].speed * GetFrameTime();
		}

		if (ArrayBullets[i].XY.y < 0)
		{
			ArrayBullets[i].isShooted = false;
			ArrayBullets[i].isDestroyed = true;
		}

		if (ArrayBullets[i].isDestroyed)
		{
			ArrayBullets[i].XY.x = P2.XY.x + P2.width / 2;
			ArrayBullets[i].XY.y = P2.XY.y;
		}

	}
}