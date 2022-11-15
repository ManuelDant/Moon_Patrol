#include "credits.h"

void Credits()
{
	DrawCredits();
}

void DrawCredits()
{
	BeginDrawing();
	DrawText("Programming and Audio", (GetScreenWidth() / 2) - (MeasureText("Programming and Audio", 50) / 2), static_cast<int>(GetPercentageScreenHeight(5)), 50, BLACK);
	DrawText("Enzo Coletta", (GetScreenWidth() / 2) - (MeasureText("Enzo Coletta", 30) / 2), static_cast<int>(GetPercentageScreenHeight(15)), 30, BLACK);
	DrawText("Manuel Dantuono", (GetScreenWidth() / 2) - (MeasureText("Manuel Dantuono", 30) / 2), static_cast<int>(GetPercentageScreenHeight(20)), 30, BLACK);
	DrawText("Art", (GetScreenWidth() / 2) - (MeasureText("Art", 50) / 2), static_cast<int>(GetPercentageScreenHeight(25)), 50, BLACK);
	DrawText("Ezequiel Gonzales - Canine Lotus", (GetScreenWidth() / 2) - (MeasureText("Ezequiel Gonzales - Canine Lotus", 30) / 2), static_cast<int>(GetPercentageScreenHeight(35)), 30, BLACK);
	DrawExitButton();
	EndDrawing();
}

void DrawExitButton()
{
	DrawRectangle(GetScreenWidth() - 100, 0, 100, 55, RED);
	DrawText("EXIT", GetScreenWidth() - 75, 20, 25, BLACK);
}