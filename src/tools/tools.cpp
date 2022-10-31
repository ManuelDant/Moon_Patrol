#include "tools.h"

float GetPercentageScreenHeight(float percentage)
{
	float valueToReturn = 0;
	valueToReturn = static_cast<float>(GetScreenHeight() / 100);
	valueToReturn *= percentage;
	return valueToReturn;
}

float GetPercentageScreenWidth(float percentage)
{
	float valueToReturn = 0;
	valueToReturn = static_cast<float>(GetScreenWidth() / 100);
	valueToReturn *= percentage;
	return valueToReturn;
}