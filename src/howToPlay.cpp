#include "howToPlay.h"

void HowToPlay() {
	DrawHowToPlay();
}

void DrawHowToPlay() {
	BeginDrawing();
	DrawText("Player 1", (GetScreenWidth() / 2) - (MeasureText("Player 1", 50) / 2), static_cast<int>(GetPercentageScreenHeight(5)), 50, BLACK);
	DrawText("Movement: A | D  Jump: W", (GetScreenWidth() / 2) - (MeasureText("Movement: A | D  Jump: W", 30) / 2), static_cast<int>(GetPercentageScreenHeight(15)), 30, BLACK);
	DrawText("Shoot: SPACE", (GetScreenWidth() / 2) - (MeasureText("Shoot: SPACE", 30) / 2), static_cast<int>(GetPercentageScreenHeight(20)), 30, BLACK);
	DrawText("Player 2", (GetScreenWidth() / 2) - (MeasureText("Player 2", 50) / 2), static_cast<int>(GetPercentageScreenHeight(30)), 50, BLACK);
	DrawText("Movement: LEFT | RIGHT  Jump: UP", (GetScreenWidth() / 2) - (MeasureText("Movement: LEFT | RIGHT  Jump: UP", 30) / 2), static_cast<int>(GetPercentageScreenHeight(40)), 30, BLACK);
	DrawText("Shoot: ENTER", (GetScreenWidth() / 2) - (MeasureText("Shoot: ENTER", 30) / 2), static_cast<int>(GetPercentageScreenHeight(45)), 30, BLACK);
	DrawText("version 1.0", 0, 0, 20, BLACK);
	DrawExit();
	EndDrawing();
}

void DrawExit() {
	DrawRectangle(GetScreenWidth() - 100, 0, 100, 55, RED);
	DrawText("EXIT", GetScreenWidth() - 75, 20, 25, BLACK);
}