#include "score.h"

#include "raylib.h"

void DrawScore() {
	DrawText(TextFormat("Puntuacion: %02i", score), 10, 15, 40, RED);
}

void DrawMaxScore() {
	

	if (maxScore > 0)
	{
		DrawText(TextFormat("Maxima Puntuacion: %02i", maxScore), GetScreenWidth() / 2 - 300, 10, 60, RED);
	}
}

void UpdateMaxScore() {
	if (score > maxScore)
	{
		maxScore = score;
	}
}

void RestartScore() {
	score = 0;
}

void AddScore(int Score) {
	score += Score;
}