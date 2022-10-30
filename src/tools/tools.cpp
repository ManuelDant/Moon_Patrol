#include "tools.h"

float GetPercentageScreenHeight(float percentage)
{
	float valueToReturn = 0;
	valueToReturn = GetScreenHeight() / 100;
	valueToReturn *= percentage;
	return percentage;
}

float GetPercentageScreenWidth(float percentage)
{
	float valueToReturn = 0;
	valueToReturn = GetScreenWidth() / 100;
	valueToReturn *= percentage;
	return percentage;
}