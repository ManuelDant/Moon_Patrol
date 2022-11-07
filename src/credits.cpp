#include "credits.h"

void Credits()
{
	DrawCredits();
}

void DrawCredits()
{
	BeginDrawing();
	DrawText("Programming and Audio", (GetScreenWidth() / 2) - (MeasureText("Programming and Audio", 50) / 2), 150, 50, BLACK);
	DrawText("Enzo Coletta", (GetScreenWidth() / 2) - (MeasureText("Enzo Coletta", 30) / 2), 225, 30, BLACK);
	DrawExitButton();
	EndDrawing();
}

void DrawExitButton()
{
	DrawRectangle(GetScreenWidth() - 100, 0, 100, 55, RED);
	DrawText("EXIT", GetScreenWidth() - 75, 20, 25, BLACK);
}