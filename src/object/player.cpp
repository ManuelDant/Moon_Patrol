#include "player.h"

PLAYER CreatePlayer()
{
	PLAYER P1{};
	P1.height = 10;
	P1.width = 10;

	P1.XY.x = static_cast<float>(GetScreenWidth()/2);
	P1.XY.y = static_cast<float>(GetPercentageScreenHeight(80) - P1.height);

	P1.lives = 1;

	return P1;
}