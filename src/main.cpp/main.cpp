#include "../menu.h"

int main()
{
	int screenWidth = 1280;
	int screenHeight = 720;
	InitWindow(screenWidth, screenHeight, "Carrefour Patrol");
	SetExitKey(NULL);
	Menu();
	return 0;
}