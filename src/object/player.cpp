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