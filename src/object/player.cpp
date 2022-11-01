#include "player.h"

PLAYER CreatePlayer()
{
	PLAYER P1{};
	P1.height = 25;
	P1.width = 25;

	P1.XY.x = static_cast<float>(GetScreenWidth()/2);
	P1.XY.y = static_cast<float>(GetPercentageScreenHeight(80) - P1.height);

	P1.speed.x = 0;
	P1.speed.y = 0;

	P1.isJumping = false;
	P1.jumpTime = 0;

	P1.lives = 1;

	return P1;
}