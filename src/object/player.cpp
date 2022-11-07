#include "player.h"

PLAYER CreatePlayer()
{
	PLAYER P1{};
	P1.height = 50;
	P1.width = 50;

	P1.XY.x = static_cast<float>(GetScreenWidth()/4);
	P1.XY.y = static_cast<float>(GetPercentageScreenHeight(90) - P1.height);

	P1.startPosition = P1.XY.y;
	P1.maxJump = P1.startPosition + P1.height * 4;

	P1.speed.x = 0;
	P1.speed.y = 0;

	P1.isJumping = false;

	P1.lives = 1;

	return P1;
}